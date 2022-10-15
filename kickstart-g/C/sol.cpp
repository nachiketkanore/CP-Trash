/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 15 October 2022 05:51:56 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int MX = 5e5 + 5;
int N, A[MX], pref[MX], prefpref[MX];

template <typename T> class SparseTable {
	public:
	int n;
	vector<vector<T>> mat;

	SparseTable(const vector<T>& a) {
		n = static_cast<int>(a.size());
		int max_log = 32 - __builtin_clz(n);
		mat.resize(max_log);
		mat[0] = a;
		for (int j = 1; j < max_log; j++) {
			mat[j].resize(n - (1 << j) + 1);
			for (int i = 0; i <= n - (1 << j); i++) {
				mat[j][i] = min(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	T get(int from, int to) const {
		--from, --to;
		assert(0 <= from && from <= to && to <= n - 1);
		int lg = 32 - __builtin_clz(to - from + 1) - 1;
		return min(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
	}
};

void solve() {
	cin >> N;
	vector<int> P;
	FOR(i, 1, N) {
		cin >> A[i];
		pref[i] = pref[i - 1] + A[i];
		P.push_back(pref[i]);
		prefpref[i] = prefpref[i - 1] + pref[i];
	}
	int ans = 0;
	SparseTable<int> T(P);
	FOR(L, 1, N) {
		int lo = L, hi = N;
		int X = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int small = T.get(L, mid);
			// see(L, mid, small);
			if (small >= pref[L - 1]) {
				X = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (~X) {
			int add = (prefpref[X] - prefpref[L - 1]) - (X - L + 1) * pref[L - 1];
			// see(L, X, add);
			ans += add;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}

	return 0;
}
