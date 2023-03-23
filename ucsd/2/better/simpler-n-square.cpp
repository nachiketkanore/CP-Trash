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

inline int rand(int l, int r) {
	static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
int solve1(int k, vector<Segment> ranges) {
	const int N = ranges.size();
	sort(ranges.begin(), ranges.end(), [](Segment a, Segment b) { return a.start < b.start; });

	int ans = 0;
	vector<int> nxt(N, -1);

	for (int i = 0; i < N; i++) {
		int which = -1, best_right = ranges[i].end;
		int L = ranges[i].start, R = ranges[i].end;
		for (int j = i + 1; j < N; j++) {
			if (ranges[j].start <= R) {
				if (best_right < ranges[j].end) {
					best_right = ranges[j].end;
					which = j;
				}
			} else
				break;
		}
		if (which != -1) {
			nxt[i] = which;
		}
	}

	for (int i = 0; i < N; i++) {
		vector<int> chosen;
		int curr = i;
		while (curr != -1 && sz(chosen) < k) {
			chosen.push_back(curr);
			curr = nxt[curr];
		}

		int l = chosen[0], r = chosen.back();

		if (sz(chosen) == k) {
			ans = max(ans, ranges[r].end - ranges[l].start);
		} else if (sz(chosen) < k) {

			int UL = ranges[l].start;
			int UR = ranges[r].end;
			int required = k - sz(chosen);

			// try adding `required` ranges that lie inside the union
			for (int i = 0; i < N && required > 0; i++) {
				if (!binary_search(chosen.begin(), chosen.end(), i)) {
					if (UL <= ranges[i].start && ranges[i].end <= UR) {
						required -= 1;
					}
				}
			}
			if (required <= 0) {
				ans = max(ans, UR - UL);
			}
		}
	}

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
		int N = rand(15, 19), K = rand(1, N);
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
