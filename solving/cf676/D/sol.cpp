#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int tot = 0;
map<int, int> ways;

vector<int> get(vector<int>& a, int i, int j) {
	assert(j - i == 1);
	std::vector<int> ret;
	FOR(k, 0, i - 1) ret.push_back(a[k]);
	ret.push_back(a[i] + a[j]);
	FOR(k, j + 1, sz(a) - 1) ret.push_back(a[k]);
	return ret;
}

void go(std::vector<int> curr, int score) {
	if (sz(curr) == 1) {
		tot++;
		ways[score]++;
		return;
	}

	for (int i = 0; i < sz(curr) - 1; i++) {
		go(get(curr, i, i + 1), score + curr[i] + curr[i + 1]);
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";

		int n;
		cin >> n;
		std::vector<int> a(n);
		for (int& x : a)
			cin >> x;

		ways.clear();
		tot = 0;
		go(a, 0);

		using ld = long double;

		ld ans = 0.0;

		for (auto it : ways) {
			int val = it.first;
			int cnt = it.second;
			ld prob = (ld)(cnt) / (ld)(tot);
			ans += (ld)(val) * (ld)(prob);
		}

		cout << fixed << setprecision(10) << ans << '\n';
	}
}