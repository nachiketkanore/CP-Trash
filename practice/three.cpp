#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

map<vector<int>, int> dp;

int go(vector<int> a) {
	if (sz(a) == 1)
		return a[0];
	if (dp.count(a))
		return dp[a];

	int ans = inf;

	for (int i = 0; i < sz(a); i++) {
		for (int j = i + 1; j < sz(a); j++) {
			vector<int> next;
			for (int id = 0; id < sz(a); id++) {
				if (id == i || id == j)
					continue;
				next.push_back(a[id]);
			}
			int add = (a[i] + a[j] + 1) / 2;
			next.push_back(add);
			ans = min(ans, go(next));
		}
	}
	dp[a] = ans;
	return ans;
}

void trace(vector<int> a) {
	if (sz(a) == 1)
		return;

	int ans = go(a);

	for (int i = 0; i < sz(a); i++) {
		for (int j = i + 1; j < sz(a); j++) {
			vector<int> next;
			for (int id = 0; id < sz(a); id++) {
				if (id == i || id == j)
					continue;
				next.push_back(a[id]);
			}
			int add = (a[i] + a[j] + 1) / 2;
			next.push_back(add);
			int get = go(next);
			if (get == ans) {
				for (int x : a)
					cout << x << ' ';
				cout << ", choices = ";
				cout << a[i] << ' ' << a[j] << '\n';
				return trace(next);
			}
		}
	}
	// return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	FOR(TC, 1, 10) {
		cout << "\n" << TC << " : ";
		int n = TC;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			a[i] = i + 1;
		int ans = go(a);
		cout << ans << '\n';
		cout << "choices : \n";

		trace(a);
		cout << "\n\n";
	}
}