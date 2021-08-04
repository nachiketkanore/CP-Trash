/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 03:32:55 PM IST
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

#define see(x) cerr << #x << " = " << x << endl
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
		int n, p;
		cin >> n >> p;
		int best_r = -1, best_val = -1;

		auto get_power = [](int n, int p) {
			int ret = 0;
			while (n > 0) {
				ret += n / p;
				n /= p;
			}
			return ret;
		};

		FOR (r,0,n) {
			int val = get_power(n, p) - get_power(n - r, p) - get_power(r, p);
			// see(n); see(r); see(val);
			if (val >= best_val) {
				best_val = val;
				best_r = r;
			}
		}

		assert(~best_r && ~best_val);
		cout << best_r << ' ' << best_val << '\n';
	}
}
