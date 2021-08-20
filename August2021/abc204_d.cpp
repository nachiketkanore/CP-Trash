/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 21 August 2021 12:56:33 AM IST
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

const int _ = 105;
int N, sum, ans = 1e18;

int32_t main() {
	vector<bool> poss(100001); poss[0] = 1;
	cin >> N;
	FOR (i,1,N) {
		int u; cin >> u;
		sum += u;
		vector<bool> nposs = poss;
		FOR (sum,0,100000) 
			if (poss[sum])
				nposs[sum + u] = true;
		poss = nposs;
	}
	FOR (one,1,100000) {
		if (poss[one]) {
			int two = sum - one;
			cmin(ans, max(one, two));
		}
	}
	assert(ans < 1e18);
	cout << ans << '\n';
}
