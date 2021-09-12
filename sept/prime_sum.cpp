/**
 *    Author: Nachiket Kanore
 *    Created: Friday 10 September 2021 02:48:50 PM IST
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

const int _ = 1e7;
bool prime[_ + 1];

int32_t main() {
	fill(prime + 2, prime + _ + 1, true);
	FOR (i,2,_) {
		if (prime[i])
			for (int j = i<<1; j <= _; j += i)
				prime[j] = false;
	}
	int N;
	cin >> N;
	int ans = 0;
	FOR (i,1,N) {
		if (prime[i] && i + 2 <= N && prime[i + 2])
			++ans;
	}
	cout << ans << '\n';
}
