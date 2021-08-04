/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 02:42:38 PM IST
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

const int N = 1e6;
int pos[N];

int32_t main() {
	int T;
	cin >> T;
	int L = -1, R = -1;
	while (T--) {
		int type, x; cin >> type >> x;
		if (type == 1) {
			if (L == -1) {
				L = N / 2, R = N / 2;
				pos[x] = L;
			} else {
				L--;
				pos[x] = L;
			}
		} else if (type == 2) {
			if (R == -1) {
				L = N / 2, R = N / 2;
				pos[x] = R;
			} else {
				R++;
				pos[x] = R;
			}
		} else {
			assert(pos[x]);
			cout << min(R - pos[x], pos[x] - L) << '\n';
		}
	}
	
}
