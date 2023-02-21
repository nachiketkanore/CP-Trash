/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 21 February 2023 06:47:27 PM IST
 **/
#include "bits/stdc++.h"
#include <strings.h>
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

const int INF = 1e9;

struct BIT {
	int N;
	vector<int> bit;

	void init(int n) {
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val) {
		while (idx <= N) {
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	void updateMax(int idx, int val) {
		while (idx <= N) {
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int pref(int idx) {
		int ans = 0;
		while (idx > 0) {
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r) {
		if (l > r)
			return 0;
		return pref(r) - pref(l - 1);
	}

	int prefMax(int idx) {
		int ans = -2e9;
		while (idx > 0) {
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
} frequencies;

class node {
	public:
	static const int inf = 1e18;
	int mn, mx, sum;

	node(int _mn, int _mx, int _sum) {
		mn = _mn;
		mx = _mx;
		sum = _sum;
	}

	node() {
		mn = inf;
		mx = -inf;
		sum = 0;
	}
};

// Default tasks
// Point assignment with range queries
struct segtree {
	int N;
	vector<node> st;
	void init(int n) {
		N = n;
		st.resize((N << 2) + 2);
		build(1, 1, N);
	}

	// Write reqd merge functions
	void merge(node& ret, node& left, node& right) {
		ret.mn = min(left.mn, right.mn);
		ret.mx = max(left.mx, right.mx);
		ret.sum = left.sum + right.sum;
	}

	void build(int u, int L, int R) {
		if (L == R) {
			// Leaf value
			st[u] = node(INF, 0, 0);
			return;
		}
		int M = (L + R) / 2;
		build(u * 2, L, M);
		build(u * 2 + 1, M + 1, R);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}

	node Query(int u, int L, int R, int i, int j) {
		if (j < L || i > R)
			return node();
		if (i <= L && R <= j)
			return st[u];
		int M = (L + R) / 2;
		node left = Query(u * 2, L, M, i, j);
		node right = Query(u * 2 + 1, M + 1, R, i, j);
		node ret;
		merge(ret, left, right);
		return ret;
	}

	node pQuery(int u, int L, int R, int pos) {
		if (L == R)
			return st[u];
		int M = (L + R) / 2;
		if (pos <= M)
			return pQuery(u * 2, L, M, pos);
		else
			return pQuery(u * 2 + 1, M + 1, R, pos);
	}

	void pUpdate(int u, int L, int R, int pos, int val) {
		if (L == R) {
			// Point update
			// Update leaf value
			st[u] = node(val, val, val);
			return;
		}
		int M = (L + R) / 2;
		if (pos <= M)
			pUpdate(u * 2, L, M, pos, val);
		else
			pUpdate(u * 2 + 1, M + 1, R, pos, val);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}

	node query(int pos) {
		return pQuery(1, 1, N, pos);
	}

	node query(int l, int r) {
		return Query(1, 1, N, l, r);
	}

	void update(int pos, int val) {
		pUpdate(1, 1, N, pos, val);
	}
} index_finder;

void solve() {
	int N, K;
	cin >> N >> K;
	int A[N + 1];

	int equal_pairs = 0;
	map<int, int> freq;
	FOR(i, 1, N) {
		cin >> A[i];
		equal_pairs += ++freq[A[i]];
	}

	auto compute = [&]() {
		vector<int> dp(N + 1);
		int ret = 0;
		for (int i = N; i >= 1; i--) {
			int j = index_finder.query(A[i] + 1, A[i] + K).mn;
			if (j > i && j <= N) {
				dp[i] = dp[j] + frequencies.rsum(A[i] + 1, A[j]);
			} else {
				dp[i] = 0;
			}
			index_finder.update(A[i], i);
			frequencies.update(A[i], +1);
			ret += dp[i];
		}
		FOR(i, 1, N) {
			index_finder.update(A[i], INF);
			frequencies.update(A[i], -1);
		}
		return ret;
	};

	int ans = equal_pairs;
	ans += compute();
	reverse(A + 1, A + N + 1);
	ans += compute();

	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	frequencies.init(500005);
	index_finder.init(500005);

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
