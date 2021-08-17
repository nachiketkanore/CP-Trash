/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 08 August 2021 12:11:09 AM IST
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

int lcm(int a, int b) {
	return a * b / __gcd(a, b);
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<pair<int,int>> a(M);
		for (auto &[x, y]: a) {
			cin >> x >> y;
		}
		sort(a.rbegin(), a.rend());
		//sort(ALL(a), [&](const auto& one, const auto& two) {
			//const auto [x1, y1] = one;
			//const auto [x2, y2] = two;
			////return x1 * (N - N / y1) > x2 * (N - N / y2);
			//return x1 > x2;
		//});
		int ans = 0;
		int LCM = 1, remain = N;
		for (auto [x, y]: a) {
			int common = N / lcm(LCM, y);
			int other = remain - common;

			ans += other * x;
			remain -= other;

			LCM = lcm(LCM, y);
			if (LCM > N) break;
		}
		cout << ans << '\n';
	}
}
