/**
 *    Author: Nachiket Kanore
 *    Created: Friday 06 August 2021 04:51:01 PM IST
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
	// N = 5, p = 2, K = 3
	// 0, 1, 2, 3, 4
	// 0, 3, 1, 4, 2
	// 0000 11111 222222 ... (k-1)(k-1)(k-1)
	int T;
	cin >> T;
	while (T--) {
		int N, p, K;
		cin >> N >> p >> K;
		if (K >= N) {
			cout << ++p << '\n';
			continue;
		}

		int x = (N - 1) / K + 1;
		int l1 = 0, r1 = -1;
		int lo = 0, hi = K - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int val = (N - 1 - mid) / K + 1;
			if (val == x) {
				r1 = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		assert(~r1);
		int l2 = r1 + 1, r2 = K - 1;

		auto intersection = [&](int x, int y, int L, int R) {
			if (x > y || L > R || L < 0 || R < 0) return int(0);
			if (y < L || x > R) return int(0);
			if (y > R) return R - L + 1;
			return y - L + 1;
		};

		auto count_previous = [&](int pos) {
			if (pos == 0) return int(0);
			return x * intersection(0, pos - 1, l1, r1) + 
				   (x - 1) * intersection(0, pos - 1, l2, r2);
		};

		auto count_self = [&](int pos) {
			return (p - pos) / K + 1;
		};

		int pos = p % K;
		int ans = count_previous(pos) + count_self(pos);
		cout << ans << '\n';
	}
}
