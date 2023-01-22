#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n;
string s;
vector<int> segs;

bool can(int ops) {
	int m = sz(segs);
	vector<int> upd(m);
	for (int i = 0; i < m; i++) {
		upd[i] = segs[i] - (i + 1 <= ops);
	}
	int id = 0;
	for (int i = 0; i < ops - 1; i++) {
		id = max(id, i);
		while (id < sz(segs) && !upd[id])
			id++;
		if (id == sz(segs))
			return 0;
		assert(upd[id] > 0);
		--upd[id];
	}
	return 1;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n >> s;
		s = " " + s;
		char ch = s[1];
		int len = 1;
		segs.clear();

		for (int i = 2; i <= n; i++) {
			if (s[i] == ch) {
				++len;
			} else {
				segs.push_back(len);
				ch = s[i];
				len = 1;
			}
		}
		segs.push_back(len);
		int tot = sz(segs);

		int lo = 1, hi = tot, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (can(mid))
				ans = mid, lo = mid + 1;
			else
				hi = mid - 1;
		}

		assert(~ans);
		cout << ans << '\n';
	}
}