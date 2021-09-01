/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 01 September 2021 02:15:19 PM IST
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
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	F0R (i,N) cin >> A[i];
	int lo = 1, hi = N << 1;
	int ans = -1;
	// returns true is there is a subarray
	// with length >= K and median >= x
	auto exists = [&](int x) {
		vector<int> B(N);
		F0R (i,N) {
			if (A[i] >= x) B[i] = 1;
			else B[i] = -1;
			if (i) B[i] += B[i-1];
		}
		// max sum subarray with length >= K
		int best = B[K-1];
		int j = 0;
		int small = 1e18;
		for (int i = K; i < N; i++) {
			cmin(small, B[j++]);
			cmax(best, B[i]);
			cmax(best, B[i] - small);
		}
		return best > 0;
	};
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (exists(mid)) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	assert(~ans);
	cout << ans << '\n';
}
