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
		for (int& x : a)
			cin >> x;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (i == 0 || i == n - 1)
				ans.push_back(a[i]);
			else if ((a[i - 1] < a[i] && a[i] > a[i + 1]) || (a[i - 1] > a[i] && a[i] < a[i + 1]))
				ans.push_back(a[i]);
		}
		cout << sz(ans) << '\n';
		for (int x : ans)
			cout << x << ' ';
		cout << '\n';
	}
}