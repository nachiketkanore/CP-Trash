/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 11 November 2021 02:58:11 PM IST
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

int32_t main() {
	int N, L, R; cin >> N >> L >> R;
	vector<int> one, two;
	F0R (i,N) {
		int u; cin >> u;
		if (i < N / 2) one.push_back(u);
		else two.push_back(u);
	}
	vector<int> A, B;
	F0R (mask,1<<sz(one)) {
		int sum = 0;
		F0R (i,sz(one)) if (mask >> i & 1) sum += one[i];
		A.push_back(sum);
	}
	F0R (mask,1<<sz(two)) {
		int sum = 0;
		F0R (i,sz(two)) if (mask >> i & 1) sum += two[i];
		B.push_back(sum);
	}
	sort(ALL(A));
	sort(ALL(B));
	auto compute = [&](int X) {
		int ans = 0;
		for (int x: A) {
			// x + y <= X
			// y <= X - x
			ans += upper_bound(ALL(B), X - x) - B.begin();
		}
		return ans;
	};
	cout << compute(R) - compute(L - 1) << '\n';
}
