/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 12 August 2021 09:26:34 PM IST
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

int brute(vector<int> A) {
	const int N = A.size();
	int ans = 1e9;
	F0R(i, N) {
		int val = A[i];
		int req = 0;
		for (int j = i; j >= 0; j--) {
			req += abs(A[j] - val);
			val--;
		}
		val = A[i] + 1;
		for (int j = i + 1; j < N; j++) {
			req += abs(A[j] - val);
			val++;
		}
		cmin(ans, req);
	}
	assert(ans != 1e9);
	return ans;
}

int32_t main() {
	srand(time(0));
	FOR(tc, 1, 1000) {
		int N = rand() % 105 + 1;
		vector<int> A(N);
		F0R(i, N) {
			A[i] = rand() % 100 + 1;
			// cout << A[i] << " \n"[i==N-1];
		}
		auto cost = [&](int fi) {
			int ret = 0;
			F0R(i, N) {
				ret += abs(A[i] - fi);
				fi++;
			}
			return ret;
		};
		int lo = -1000, hi = 1000;
		vector<int> costs;
		FOR(fi, lo, hi) {
			costs.push_back(cost(fi));
		}
		while (sz(costs) >= 2 && costs.back() > costs[sz(costs) - 2]) {
			costs.pop_back();
		}
		reverse(ALL(costs));
		while (sz(costs) >= 2 && costs.back() > costs[sz(costs) - 2]) {
			costs.pop_back();
		}
		sort(ALL(costs));
		assert(costs.front() == costs.back());
		int ans = costs.back();
		int brute_ans = brute(A);
		assert(ans == brute_ans);
		cout << "OK " << tc << '\n';
		// cout << ans << ' ' << brute_ans << '\n';
	}
}
