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

	/* for (Segment s : ranges) {
		cout << s.start << ' ' << s.end << '\n';
	} */

	// cout << string(30, '-') << '\n';
	int ans = 0;

	for (int i = 0; i < N; i++) {
		vector<int> chosen = { i };
		int rightmost = ranges[i].end;

		while ((int)chosen.size() < k) {
			int best_id = -1;
			int id = chosen.back();
			auto [L, R] = ranges[id];
			for (int j = id + 1; j < N; j++) {
				if (ranges[j].start <= R) {
					if (ranges[j].end >= rightmost) {
						rightmost = ranges[j].end;
						best_id = j;
					}
				}
			}
			if (best_id != -1) {
				// see("choosing", best_id, " for ", id);
				chosen.push_back(best_id);
			} else {
				break;
			}
		}
		// see(chosen);
		if ((int)chosen.size() == k) {
			int l = chosen[0], r = chosen.back();
			ans = max(ans, ranges[r].end - ranges[l].start);
		} else {
			assert(!chosen.empty());
			// sort(chosen.begin(), chosen.end()); it will be already sorted only

			int UL = ranges[chosen[0]].start;
			int UR = ranges[chosen.back()].end;
			int required = k - (int)chosen.size();

			// try adding `required` ranges that lie inside the union
			for (int i = 0; i < N && required > 0; i++) {
				if (!binary_search(chosen.begin(), chosen.end(), i)) {
					if (UL <= ranges[i].start && ranges[i].end <= UR) {
						required -= 1;
					}
				}
			}
			if (required == 0) {
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

	cout << solve1(3, ranges) << '\n'; */
	// return 0;

	// cout << solve2(3, ranges) << '\n';

	const int MX = 1000;

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
