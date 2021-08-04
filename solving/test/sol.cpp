/* Author: Nachiket Kanore
Created: Saturday 30 January 2021 05:16:41 PM IST
(ツ) When you are content to be simply yourself and don't compare or compete, everybody will respect you.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>
using namespace std;

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
typedef vector<int> ar;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int N = 2e5 + 5, inf = 1e18;
const int MOD = 1e9 + 7;

vector<int> fact;

void func() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		
	}
}

struct fast_io{
    fast_io() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        vector<int> fact;
   }
    ~fast_io() {
        cerr << "Program finished\n";
    }
};

void hello() {
	vector<char> f;
	int n;
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int u;
		cin >> u;
		f.push_back(u);
	}
}

void solve2(int u) {
	int x;
	cin >> x;
	int xx;
	cin >> xx;
	cout << x * xx << endl;
	return;
}

void precomputation() {
   for (int i = 0; i < N; i++) {
       if (fact.empty()) {
           fact.push_back(1);
       } else {
           fact.push_back(fact.back() * (i + 1) % MOD);
       }
   } 
}

void hello() {
    string name;
    cin >> name;
    cout << "HElloworld " << name << '\n';
}

void search() {
    for (int i = 0; i < n; i++) {
        nachiket[21][0][25] = 21;
    }
}

void hello() {
    string name;
    cin >> name;
    cout << "Hello " << name << '\n';
}

int32_t main() {
    precomputation();
    int tc; cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] >= 21) {
                ans++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != MOD) {
            cout << "Found\n";
            return 0;
        }
    }
    int inversions = 0;
    for (int j = 1; j <= n; j++) {
        for (int i = j + 1; i <= n; i++) {
            if (a[i] > a[j]) {
                inversions++;
            }
        }
    }
    return 0;
}    
