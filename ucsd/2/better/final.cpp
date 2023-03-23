#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)x.size()

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

// A segment is defined by its start and end points
struct Segment {
	int start, end;
	Segment(int l, int r) {
		start = l;
		end = r;
	}
};

class segTree {

	private:
	const int INF = 1e9;
	int n;
	vector<pair<int, int>> st;
	vector<int> a;

	public:
	// Keeping it 1-based
	void init(int _n, const vector<Segment>& given) {
		n = _n;
		st = vector<pair<int, int>>(4 * n + 5, make_pair(-INF, -1));
		a.resize(n + 10);
		for (int i = 0; i < n; i++) {
			a[i + 1] = given[i].end;
		}
		// cout << "init.......\n";
		build(1, 1, n);
	}

	void build(int node, int tl, int tr) {
		if (tl == tr)
			st[node] = make_pair(a[tl], tl); // leaf value from global array 'a'
		else {
			int mid = (tl + tr) / 2;
			build(2 * node, tl, mid);
			build(2 * node + 1, mid + 1, tr);
			st[node] = max(st[2 * node], st[2 * node + 1]); // operation
		}
	}

	void pointUpdate(int node, int tl, int tr, int pos, int val) {
		if (tl == tr) {
			st[node] = { val, pos };
		} else {
			int mid = (tl + tr) / 2;
			if (pos <= mid)
				pointUpdate(2 * node, tl, mid, pos, val);
			else
				pointUpdate(2 * node + 1, mid + 1, tr, pos, val);
			st[node] = max(st[2 * node], st[2 * node + 1]); // operation
		}
	}

	pair<int, int> rangeQuery(int node, int tl, int tr, int l, int r) {
		if (l > r)
			return { -INF, -1 }; // handle this value carefully
		if ((l == tl) && (r == tr))
			return st[node];
		int mid = (tl + tr) / 2;
		pair<int, int> left_ans = rangeQuery(2 * node, tl, mid, l, min(r, mid));
		pair<int, int> right_ans = rangeQuery(2 * node + 1, mid + 1, tr, max(l, mid + 1), r);
		return max(left_ans, right_ans); // operation
	}

	void update(int pos, int val) {
		assert(pos >= 0 && pos < n);
		pointUpdate(1, 1, n, pos + 1, val);
	}

	pair<int, int> query(int l, int r) {
		assert(l >= 0 && l < n);
		assert(r >= 0 && r < n);
		assert(l <= r);
		return rangeQuery(1, 1, n, l + 1, r + 1);
	}
};

int solve(int k, vector<Segment> ranges) {
	const int N = ranges.size();
	sort(ranges.begin(), ranges.end(), [](Segment a, Segment b) { return a.start < b.start; });

	vector<vector<int>> adj(N, vector<int>());

	segTree T;
	T.init(N, ranges);
	// segment[idx] = { val, idx }
	// returns the maximum value along with it's index in some given query range

	for (int i = 0; i < N; i++) {
		int L = ranges[i].start, R = ranges[i].end;

		int idx = -1;
		int lo = i + 1, hi = N - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (ranges[mid].start <= R) {
				idx = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		// all ranges in the range [i + 1, idx] start within the i-th segment
		if (idx == -1)
			continue;

		auto [best_right, which] = T.query(i + 1, idx);

		if (best_right >= R && which >= 1 && which <= N && (which - 1 != i)) {
			adj[which - 1].push_back(i);
		}
	}

	vector<int> parents;
	vector<bool> vis(N, false);

	int ans = 0;
	function<void(int)> dfs = [&](int u) {
		parents.push_back(u);
		assert(!vis[u]);
		vis[u] = true;

		// same process of updating the answer
		int M = sz(parents);
		if (M >= k) {
			int l = parents[M - 1], r = parents[(M - 1) - k + 1];
			ans = max(ans, ranges[r].end - ranges[l].start);
		} else {
			int l = parents.back();
			int r = parents[0];
			assert(l <= r);

			int required = k - M;

			// try adding `in_between` ranges that lie inside the union and
			// within indices [l, r] which we didn't choose in the subset
			int in_between = (r - l + 1) - M;

			int UL = ranges[l].start;
			int UR = ranges[r].end;

			int lo = r + 1, hi = N - 1;
			int max_id = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (UL <= ranges[mid].start && ranges[mid].end <= UR) {
					max_id = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			// all ranges from indices [r + 1, max_id] lie within our union UL...UR

			int after_r = 0;
			if (~max_id) {
				after_r = (max_id - (r + 1) + 1);
			}

			// if we have sufficient, update the answer
			if (in_between + after_r >= required) {
				ans = max(ans, UR - UL);
			}
		}

		for (int nxt : adj[u]) {
			dfs(nxt);
		}
		parents.pop_back();
	};

	for (int i = N - 1; i >= 0; i--) {
		if (!vis[i])
			dfs(i);
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<Segment> ranges = {
		Segment(1, 5),
		Segment(3, 8),
		Segment(6, 10),
		Segment(7, 11),
		Segment(9, 12),
	};

	cout << solve(3, ranges);

	return 0;
}
