/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 07 August 2021 11:49:20 PM IST
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
		int N, p, K;
		cin >> N >> p >> K;
		int id = 1, ans = -1;
		F0R (i,K) {
			for (int j = i; j < N; j += K) {
				if (j == p) {
					if (ans == -1) ans = id;
				}
				id++;
			}
		}
		assert(~ans);
		cout << ans << '\n';
	}
}
