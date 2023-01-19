#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, l[N], r[N], newl[N], newr[N];
std::vector<int> all;
int cnt[N];
int mx, which, year;

void work() {
	sort(all.begin(), all.end());
	FOR(i, 1, n) {
		int L = lower_bound(all.begin(), all.end(), l[i]) - all.begin();
		int R = lower_bound(all.begin(), all.end(), r[i]) - all.begin();
		assert(L <= R);
		cnt[L]++, cnt[R + 1]--;
		newl[i] = L;
		newr[i] = R;
	}
	mx = -1;
	which = -1;
	FOR(i, 0, N - 1) {
		if (i)
			cnt[i] += cnt[i - 1];
		if (cnt[i] > mx) {
			mx = cnt[i];
			which = i;
		}
	}
	assert(~mx && ~which);

	year = -1;
	FOR(i, 1, n) {
		if (newl[i] == which) {
			year = l[i];
			break;
		}
	}

	assert(~year);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	FOR(i, 1, n) {
		cin >> l[i] >> r[i];
		--r[i];
		all.push_back(l[i]);
		all.push_back(r[i]);
	}

	work();

	cout << year << ' ' << mx << '\n';
}