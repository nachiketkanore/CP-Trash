/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 14 August 2021 12:20:44 AM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <set>
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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int& x : A) {
			cin >> x;
		}
		sort(ALL(A));
		int ans = 0;
		multiset<int> diffs;
		deque<int> stk;
		int l = 0;
		F0R(r, N) {
			int M = A[r];
			if (r > 0) {
				stk.push_back(abs(A[r] - A[r - 1]));
				diffs.insert(abs(A[r] - A[r - 1]));
			}
			while (sz(diffs) && *diffs.begin() < M) {
				assert(sz(stk));
				diffs.erase(diffs.find(stk.front()));
				stk.pop_front();
				l++;
			}
			cmax(ans, r - l + 1);
		}
		cout << ans << '\n';
	}
}
