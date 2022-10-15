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

class segTree {

	private:
	int n;
	vector<int> st;

	public:
	// Keeping it 1-based
	void init(int _n) {
		n = _n;
		st = vector<int>(4 * n + 5, 0);
		build(1, 1, n);
	}

	void build(int node, int tl, int tr) {
		if (tl == tr)
			st[node] = pref[tl]; // leaf value from global array 'a'
		else {
			int mid = (tl + tr) / 2;
			build(2 * node, tl, mid);
			build(2 * node + 1, mid + 1, tr);
			st[node] = min(st[2 * node], st[2 * node + 1]); // operation
		}
	}

	void pointUpdate(int node, int tl, int tr, int pos, int val) {
		if (tl == tr) {
			st[node] = val;
		} else {
			int mid = (tl + tr) / 2;
			if (pos <= mid)
				pointUpdate(2 * node, tl, mid, pos, val);
			else
				pointUpdate(2 * node + 1, mid + 1, tr, pos, val);
			st[node] = min(st[2 * node], st[2 * node + 1]); // operation
		}
	}

	int rangeQuery(int node, int tl, int tr, int l, int r) {
		if (l > r)
			return 1e18; // handle this value carefully
		if ((l == tl) && (r == tr))
			return st[node];
		int mid = (tl + tr) / 2;
		int left_ans = rangeQuery(2 * node, tl, mid, l, min(r, mid));
		int right_ans = rangeQuery(2 * node + 1, mid + 1, tr, max(l, mid + 1), r);
		return min(left_ans, right_ans); // operation
	}

	void update(int pos, int val) {
		pointUpdate(1, 1, n, pos, val);
	}

	int query(int l, int r) {
		return rangeQuery(1, 1, n, l, r);
	}
};

void solve() {
	cin >> N;
	FOR(i, 1, N) {
		cin >> A[i];
		pref[i] = pref[i - 1] + A[i];
		prefpref[i] = prefpref[i - 1] + pref[i];
	}
	int ans = 0;
	segTree T;
	T.init(N);
	// see(T.query(1, 2));
	FOR(L, 1, N) {
		int lo = L, hi = N;
		int X = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int small = T.query(L, mid);
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
