#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n;
int a[N];

int ask(int L, int R) {
	cout << "? " << L << " " << R << endl;
	int ans;
	cin >> ans;
	return ans;
}

int32_t main() {

	cin >> n;
	int sum = ask(1, n);
	a[1] = sum;
	FOR(i, 2, n) {
		if (i < n) {
			int suff_sum = ask(i, n);
			a[i] = suff_sum;
		}
	}
	int first = ask(1, n - 1);
	a[n] = sum - first;
	FOR(i, 1, n) {
		a[i] = a[i] - a[i + 1];
	}

	cout << "! ";
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
}