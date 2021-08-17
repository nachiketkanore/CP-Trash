/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 08 August 2021 01:07:09 AM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

struct info {
	int id;
	int want, leaves;
	info(int id, int want, int leaves): id(id), want(want), leaves(leaves) {}
	bool operator <(const info& other) const {
		if (leaves - want == other.leaves - other.want)
			return want < other.want;
		return leaves - want < other.leaves - other.want;
		//if (leaves == other.leaves) {
			//return want < other.want;
		//}
		//return leaves < other.leaves;
		//return want < other.want;
	}
};

int32_t main() {
	// observations:
	// if A[i] > T[i] ignore that person
	// possible ideas:
	// each time take that person whose T[i] - A[i] is minimum
	// sort by some comparator?
	// maintaining custom set?
	// write brute + check?
	// DP + tracing?
	// i am assuming each person should be given contiguous timings
	// not discrete
	
	vector<int> ans_sizes;
	
	auto solve = [&]() -> void {
		int N;
		cin >> N;
		vector<int> A(N), T(N);
		vector<info> have;
		vector<array<int,3>> answer;
		for (int &x: A) cin >> x;
		for (int &x: T) cin >> x;
		F0R (i,N) {
			if (A[i] > T[i]) continue;
			have.push_back(info(i + 1, A[i], T[i]));
		}
		sort(ALL(have));
		//cerr << "--\n";
		//for (info curr: have) {
			//cerr << curr.want << ' ' << curr.leaves << endl;
		//}
		//cerr << "--\n";
		int from = 0;
		
		for (info curr: have) {
			int want = curr.want;
			int upto = curr.leaves;
			if (from + want <= upto) {
				answer.push_back({curr.id, from, from + want});
				from += want;
			}
		}

		assert(sz(answer) <= 2 * N);
		cout << sz(answer) << '\n';
		ans_sizes.push_back(sz(answer));
		for (auto [id, L, R]: answer) {
			cout << id << ' ' << L << ' ' << R << '\n';
		}
	};

	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
