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

const bool operator==(const Segment& lhs, const Segment& rhs) {
	return lhs.start == rhs.start && lhs.end == rhs.end;
}
inline int rand(int l, int r) {
	static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

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

int solve1(int k, vector<Segment> ranges) {
	const int N = ranges.size();
	// see(k);
	sort(ranges.begin(), ranges.end(), [](Segment a, Segment b) { return a.start < b.start; });

	vector<int> nxt(N, -1);
	vector<vector<int>> adj(N, vector<int>());

	// cout << "start\n";
	segTree T;
	T.init(N, ranges);

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

		if (idx == -1)
			continue;

		auto [best_right, which] = T.query(i + 1, idx);

		if (best_right >= R && which >= 1 && which <= N && (which - 1 != i)) {
			nxt[i] = which - 1;
			adj[which - 1].push_back(i);
			// see(i, which - 1);
		}
	}

	vector<int> parents;
	vector<bool> vis(N, false);

	vector<pair<int, int>> chk1, chk2;
	int ans1 = 0;
	function<void(int)> dfs = [&](int u) {
		parents.push_back(u);
		assert(!vis[u]);
		vis[u] = true;

		// see(u, parents);

		// same process of updating the answer
		int M = sz(parents);
		if (M >= k) {
			// int l = parents.back();
			// int r = parents[(M - 1) - k + 1];
			// chk1.push_back({ l, r });
			int l = M - 1, r = (M - 1) - k + 1;
			// see("index: ", l, r);
			l = parents[l], r = parents[r];
			// see("checking -> ", l, r);
			ans1 = max(ans1, ranges[r].end - ranges[l].start);
			// assert(l <= r);
			// while (r >= 0) {
			// 	ans1 = max(ans1, ranges[parents[r]].end - ranges[parents[l]].start);
			// 	l--, r--;
			// }
		} else {
			int l = parents.back();
			int r = parents[0];
			assert(l <= r);
			assert(ranges[u] == ranges[l]);
			// see("checking -> ", l, r);
			// chk1.push_back({ l, r });
			int required = k - M;
			int in_between = (r - l + 1) - M;
			required -= in_between;
			// try adding `required` ranges that lie inside the union
			auto checker = parents;
			sort(checker.begin(), checker.end());
			int UL = ranges[l].start;
			int UR = ranges[r].end;

			// count ranges after index `r` which lie in [UL, UR]
			// we will optimize what this for loop is doing
			/* for (int i = r + 1; i < N && required > 0; i++) {
				if (!binary_search(checker.begin(), checker.end(), i)) {
					if (UL <= ranges[i].start && ranges[i].end <= UR) {
						required -= 1;
					}
				}
			} */

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

			if (~max_id) {
				int cnt = (max_id - (r + 1) + 1); // max_id - r
				required -= cnt;
			}

			if (required <= 0) {
				ans1 = max(ans1, UR - UL);
			}
		}

		// same process of updating the answer

		for (int nxt : adj[u]) {
			dfs(nxt);
		}

		parents.pop_back();
	};

	for (int i = N - 1; i >= 0; i--) {
		if (!vis[i]) {
			assert(parents.empty());
			dfs(i);
			// see("dfs: ", i);
			// see(vis);
		}
	}

	int ans2 = 0;
	for (int i = 0; i < N; i++) {
		vector<int> chosen;
		int curr = i;
		while (curr != -1 && sz(chosen) < k) {
			chosen.push_back(curr);
			curr = nxt[curr];
		}

		int l = chosen[0], r = chosen.back();
		// chk2.push_back({ l, r });

		// notice that we only need the last element from `chosen` array
		// we can find that using binary lifting technique

		if (sz(chosen) == k) {
			ans2 = max(ans2, ranges[r].end - ranges[l].start);
		} else if (sz(chosen) < k) {
			assert(!chosen.empty());
			// sort(chosen.begin(), chosen.end()); it will be already sorted only

			int UL = ranges[l].start;
			int UR = ranges[r].end;
			int required = k - sz(chosen);

			int in_between = (r - l + 1) - sz(chosen);
			required -= in_between;

			// try adding `required` ranges that lie inside the union
			for (int i = r + 1; i < N && required > 0; i++) {
				if (!binary_search(chosen.begin(), chosen.end(), i)) {
					if (UL <= ranges[i].start && ranges[i].end <= UR) {
						required -= 1;
					}
				}
			}
			if (required <= 0) {
				ans2 = max(ans2, UR - UL);
			}
		}
	}

	// sort(chk1.begin(), chk1.end());
	// sort(chk2.begin(), chk2.end());
	// see(chk1);
	// see(chk2);
	see(ans1, ans2);
	return ans1;
}

vector<Segment> merge(vector<Segment> ins) {
	if (ins.empty())
		return vector<Segment>{};
	vector<Segment> res;
	sort(ins.begin(), ins.end(), [](Segment a, Segment b) { return a.start < b.start; });
	res.push_back(ins[0]);
	for (int i = 1; i < ins.size(); i++) {
		if (res.back().end < ins[i].start)
			res.push_back(ins[i]);
		else
			res.back().end = max(res.back().end, ins[i].end);
	}
	return res;
}

int brute(vector<Segment> segments, int k) {
	const int N = segments.size();
	int ans = 0;
	for (int mask = 0; mask < (1 << N); mask++) {
		if (__builtin_popcount(mask) == k) {
			vector<Segment> chk;
			for (int i = 0; i < N; i++) {
				if (mask >> i & 1) {
					chk.push_back(segments[i]);
				}
			}
			chk = merge(chk);
			if ((int)chk.size() == 1) {
				ans = max(ans, chk[0].end - chk[0].start);
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	/* vector<Segment> ranges = {
		Segment(1, 5),
		Segment(3, 8),
		Segment(6, 10),
		Segment(7, 11),
		Segment(9, 12),
	};

	cout << solve1(3, ranges) << '\n';
	return 0; */

	// cout << solve2(3, ranges) << '\n';

	const int MX = 100;

	for (int tc = 1;; tc++) {
		// int N = rand(15, 19), K = rand(1, N);
		int N = rand(10, 18), K = rand(1, N);
		vector<Segment> A;
		for (int i = 0; i < N; i++) {
			int l = rand(1, MX);
			int r = rand(l, MX);
			Segment add = Segment(l, r);
			A.push_back(add);
		}
		int my_solution = solve1(K, A);
		int best_solution = brute(A, K);

		if (my_solution == best_solution) {
			cout << "OK Test : " << tc << " -> answer union range = " << my_solution << '\n';
			cout.flush();
		} else {
			cout << "FAILED Test : " << tc << '\n';
			cout << "my answer = " << my_solution << '\n';
			cout << "best answer = " << best_solution << '\n';

			for (Segment s : A) {
				cout << s.start << ' ' << s.end << '\n';
			}

			cout << string(30, '-') << '\n';
			return 0;
		}

		// cout << "Case #tc -> " << solve1(K, A) << " " << brute(A, K) << '\n';
	}

	return 0;
}
