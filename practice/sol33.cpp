#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int ans = 0;
		for (int& x : a)
			cin >> x;
		cin >> ans;
		for (int mask = 1; mask < (1 << n); mask++) {
			int val = 0;
			vector<int> ids;
			for (int i = 0; i < n; i++)
				if (mask >> i & 1) {
					val += a[i];
					ids.push_back(i);
				}
			// else val -= a[i];
			if (val == ans) {
				cout << "FOUND" << T << '\n';
				for (int id : ids)
					cout << a[id] << ' ';
				cout << '\n';
			}
		}
	}
}
/*
78 91 121 484
sum = 774, ans = 605

15 26 26 45 54 84 100 144
sum = 494, ans = 0

9 14 49 63 90 101 1089
sum = 1415, ans = 1147

3 4 41 64 81 169
sum = 362, ans = 149
*/