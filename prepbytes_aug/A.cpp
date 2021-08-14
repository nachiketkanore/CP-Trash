/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 14 August 2021 12:08:04 AM IST
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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int ans = 0;
		auto calc = [](int &N, int v) {
			int ret = N / v;
			N %= v;
			return ret;
		};
		ans += calc(N, 100);
		ans += calc(N, 20);
		ans += calc(N, 10);
		ans += calc(N, 5);
		ans += calc(N, 1);
		assert(!N);
		cout << ans << '\n';
	}
}
