/**
 *    Author: Nachiket Kanore
 *    Created: Friday 23 July 2021 01:22:30 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

int32_t main() {
	auto ask = [](const vector<int>& a, const vector<int>& b) {
		cout << sz(a) << ' ' << sz(b) << ' ';
		for (int x : a)
			cout << x << ' ';
		for (int x : b)
			cout << x << ' ';
		cout << endl;
		cout.flush();
		int best;
		cin >> best;
		assert(~best);
		return best;
	};
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> one = { 1 }, two;
		FOR(i, 2, n) two.push_back(i);
		int dist = ask(one, two);

		// finding farthest node end1 from start
		// which is first index i s.t subset[two[0...i]] gives qry_ans = dist
		int end1 = -1;
		int lo = 0, hi = sz(two) - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			vector<int> subset;
			FOR(i, lo, mid) subset.push_back(two[i]);
			int get_dist = ask(one, subset);
			if (get_dist == dist) {
				end1 = two[mid];
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		// now find farthest from end1
		assert(~end1);
		one = { end1 };
		two.clear();
		FOR(i, 1, n) if (i ^ end1) two.push_back(i);

		int diameter = ask(one, two);
		cout << "-1 " << diameter << endl;
		cout.flush();
	}
}
