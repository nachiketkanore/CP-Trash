/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 26 May 2022 04:08:30 PM IST
 **/
#include "bits/stdc++.h"

#define int int64_t
#define MP make_pair
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 2e5 + 5;
const int INF = 1e14;

pair<int, int> operator+(const pair<int, int>& one, const pair<int, int>& two) {
	return make_pair(one.first + two.first, one.second + two.second);
}

int manhattan_distance(const pair<int, int>& one, const pair<int, int>& two) {
	return abs(one.first - two.first) + abs(one.second - two.second);
}

pair<int, int> doors[2][_];
pair<int, int> next_door[2][_];
int dist[2][2][_];

struct node {
	int dp[2][2];
	int L, R;

	node() {
		L = R = 0;
		F0R(i, 2) F0R(j, 2) dp[i][j] = INF;
	}

	node(int L, int R, int ndp[2][2]) : L(L), R(R) {
		F0R(i, 2) F0R(j, 2) dp[i][j] = ndp[i][j];
	}

	node(int id) {
		L = R = id;
		F0R(i, 2) F0R(j, 2) {
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = manhattan_distance(doors[i][id], doors[j][id]);
		}
	}
};

class seg_tree {
	private:
	int N;
	vector<node> st;

	public:
	void init(int N) {
		this->N = N;
		st.resize(N * 4 + 5);
		build(1, 1, N);
	}

	node unite(const node& left, const node& right) {
		assert(left.R + 1 == right.L);
		int best[2][2];
		F0R(i, 2) F0R(j, 2) best[i][j] = INF;

		F0R(from, 2) F0R(to, 2) F0R(i, 2) F0R(j, 2) {
			best[from][to] = min(best[from][to],
			left.dp[from][i] + dist[i][j][left.R] + right.dp[j][to]);
		}

		return node(left.L, right.R, best);
	}

	void build(int u, int tl, int tr) {
		if (tl == tr) {
			st[u] = node(tl);
		} else {
			int tm = (tl + tr) / 2;
			build(2 * u, tl, tm);
			build(2 * u + 1, tm + 1, tr);
			st[u] = unite(st[2 * u], st[2 * u + 1]);
		}
	}

	node query(int u, int tl, int tr, int ql, int qr) {
		if (tl == ql && tr == qr) {
			return st[u];
		}
		int mid = (tl + tr) / 2;
		if (qr <= mid)
			return query(2 * u, tl, mid, ql, qr);
		if (ql > mid)
			return query(2 * u + 1, mid + 1, tr, ql, qr);

		return unite(query(2 * u, tl, mid, ql, mid),
		query(2 * u + 1, mid + 1, tr, mid + 1, qr));
	}

	node query(int L, int R) {
		return query(1, 1, N, L, R);
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	FOR(level, 1, N - 1) {
		cin >> doors[0][level].first >> doors[0][level].second;
		next_door[0][level] = doors[0][level] + MP(1, 0);
		cin >> doors[1][level].first >> doors[1][level].second;
		next_door[1][level] = doors[1][level] + MP(0, 1);
	}

	FOR(i, 1, N - 2) {
		// dist[2][2][i] denotes calculations
		// for going from level[i] to level[i + 1]
		F0R(from, 2) F0R(to, 2) {
			dist[from][to][i] =
			1 + manhattan_distance(next_door[from][i], doors[to][i + 1]);
		}
	}

	seg_tree st;
	st.init(N - 1);

	int Q;
	cin >> Q;
	while (Q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int level1 = max(x1, y1);
		int level2 = max(x2, y2);

		if (level1 > level2) {
			swap(x1, x2);
			swap(y1, y2);
			swap(level1, level2);
		}

		if (level1 == level2) {
			cout << manhattan_distance({ x1, y1 }, { x2, y2 }) << '\n';
		} else {
			node range_ans = st.query(level1, level2 - 1);

			int ans = INF;

			F0R(from, 2) F0R(to, 2) {
				int cost = 0;
				cost += manhattan_distance({ x1, y1 }, doors[from][level1]);
				cost += range_ans.dp[from][to];
				cost += manhattan_distance(next_door[to][level2 - 1], { x2, y2 });
				cost += 1;

				ans = min(ans, cost);
			}

			assert(ans ^ INF);
			cout << ans << '\n';
		}
	}

	return 0;
}
