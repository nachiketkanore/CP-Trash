/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 01 June 2022 12:38:44 AM IST
 **/
#include <array>
#include <iostream>
#include <set>
#include <vector>
#define NDEBUG
#include <assert.h>
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

struct Points {
	set<int> pts;
	multiset<int> gaps;

	int find_small(int x) {
		if (sz(pts) == 0)
			return -1;
		auto it = pts.lower_bound(x);
		if (it == pts.begin())
			return -1;
		--it;
		return *it;
	}

	int find_large(int x) {
		if (sz(pts) == 0)
			return -1;
		auto it = pts.upper_bound(x);
		if (it == pts.end())
			return -1;
		return *it;
	}

	void add_point(int x) {
		pts.insert(x);

		int L = find_small(x), R = find_large(x);

		if (~L && ~R) {
			int rem = R - L;
			assert(gaps.count(rem));
			gaps.erase(gaps.find(rem));
			gaps.insert(x - L);
			gaps.insert(R - x);
		} else if (~L) {
			gaps.insert(x - L);
		} else if (~R) {
			gaps.insert(R - x);
		} else {
			assert(sz(pts) == 1);
		}
	}

	void remove_point(int x) {
		int L = find_small(x), R = find_large(x);

		if (~L && ~R) {
			assert(gaps.count(x - L));
			gaps.erase(gaps.find(x - L));
			assert(gaps.count(R - x));
			gaps.erase(gaps.find(R - x));
			gaps.insert(R - L);
		} else if (~L) {
			assert(gaps.count(x - L));
			gaps.erase(gaps.find(x - L));
		} else if (~R) {
			assert(gaps.count(R - x));
			gaps.erase(gaps.find(R - x));
		} else {
		}

		pts.erase(x);
	}

	int answer() {
		if (sz(pts) <= 2)
			return 0;

		int lo = *pts.begin(), hi = *pts.rbegin();
		int max_gap = *gaps.rbegin();
		int ans = hi - lo;
		ans = min(ans, hi - lo - max_gap);
		return ans;
	}
} solution;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, Q;
	cin >> N >> Q;

	F0R(i, N) {
		int x;
		cin >> x;
		solution.add_point(x);
	}

	cout << solution.answer() << '\n';

	while (Q--) {
		int type, x;
		cin >> type >> x;

		if (type == 0) {
			solution.remove_point(x);
		} else {
			solution.add_point(x);
		}

		cout << solution.answer() << '\n';
	}

	return 0;
}
