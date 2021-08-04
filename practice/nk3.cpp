#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

int count_inversion_merge(vector<int> &array, int first, int last)
{
    int mid = (first+last)/2;
    int ai = first;
    int bi = mid+1;
    int final[last-first+1], finali=0;
    int inversion = 0, i;

    while (ai <= mid && bi <= last) {
        if (array[ai] <= array[bi]) {
                final[finali++] = array[ai++];
        } else {
                final[finali++] = array[bi++];
                inversion += mid - ai + 1;
        }
    }

    while (ai <= mid)
        final[finali++] = array[ai++];

    while (bi <= last) 
        final[finali++] = array[bi++];

    for (i=0 ; i<last-first+1 ; i++)
        array[i+first] = final[i];      

    return inversion;
}

int count_inversion(vector<int> &array, int a, int b)
{
    int x, y, z, mid;
    if (a >= b) return 0;

    mid = (a+b)/2;
    
    x = count_inversion(array, a, mid);
    y = count_inversion(array, mid+1, b);
    z = count_inversion_merge(array, a, b);

    return x+y+z;
}

int n, inversions, value;

int get_inversions(vector<int> a) {
	return count_inversion(a, 0, sz(a) - 1);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;

	inversions = get_inversions(a);

	for (int bit = 30; bit >= 0; bit--) {
		int BIT = 1 << bit;
		for (int &x : a) x ^= BIT;
		int invs = get_inversions(a);
		if (invs < inversions) {
			// This bit should be set
			inversions = invs;
			value |= BIT;
		} else {
			// This bit should be unset
			// So, reset the array now
			for (int &x : a) x ^= BIT;
		}
	}
	cout << inversions << ' ' << value << '\n';
}