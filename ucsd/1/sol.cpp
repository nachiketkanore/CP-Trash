#include <bits/stdc++.h>
using namespace std;

const int _ = 200;
int n, dp[_][_][_];

// A segment is defined by its start and end points
struct Segment {
	int start, end;
	Segment(int l, int r) {
		start = l;
		end = r;
	}
};

int go(int index, int rightmost_index, int remain, const vector<Segment>& A) {
	if (remain == 0)
		return 0;
	if (index == n)
		return -1e9;

	// if (this state is visited) {
	// 	return memoized answer;
	// }
	int ans = 0;
	int union_extend = 0;

	if (rightmost_index != -1 && A[index].start <= A[rightmost_index].end) { // a choice based on overlapping or not
		union_extend = max(0, A[index].end - A[rightmost_index].end);
	} else {
		union_extend = A[index].end - A[index].start;
	}

	// choice 1: consider index-th range in our subset
	{
		int new_rightmost_index = 0;
		if (rightmost_index == -1) {
			new_rightmost_index = index;
		} else {
			new_rightmost_index = (A[index].end > A[rightmost_index].end ? index : rightmost_index);
		}
		ans = max(ans, union_extend + go(index + 1, new_rightmost_index, remain - 1, A));
	}

	// choice 2: don't consider
	ans = max(ans, 0 + go(index + 1, rightmost_index, remain, A));

	// Memoize the answer
	return ans;
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
			int get = 0;
			for (auto [L, R] : chk) {
				get += R - L;
			}
			ans = max(ans, get);
		}
	}
	return ans;
}

inline int rand(int l, int r) {
	static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int MX = 1000;

	for (int tc = 1;; tc++) {
		int N = rand(18, 22), K = rand(1, N);
		::n = N;
		vector<Segment> A;
		for (int i = 0; i < N; i++) {
			int l = rand(1, MX);
			int r = rand(l, MX);
			Segment add = Segment(l, r);
			A.push_back(add);
		}
		sort(A.begin(), A.end(), [](Segment a, Segment b) { return a.start < b.start; });
		int my_solution = go(0, -1, K, A);
		if (my_solution < 0)
			my_solution = 0;
		int best_solution = brute(A, K);

		if (my_solution == best_solution) {
			cout << "OK Test : " << tc << " -> answer union range = " << my_solution << '\n';
			cout.flush();
		} else {
			cout << "FAILED Test : " << tc << '\n';
			cout << "K = " << K << '\n';
			cout << "my = " << my_solution << ", best = " << best_solution << '\n';
			cout << string(30, '-') << '\n';

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
