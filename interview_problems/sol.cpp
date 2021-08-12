/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 12 August 2021 09:26:34 PM IST
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
	int N;
	cin >> N;
	vector<int> A(N);
	F0R (i,N) cin >> A[i];
	auto cost = [&](int fi) {
		int ret = 0;
		F0R (i,N) {
			ret += abs(A[i] - fi);
			fi++;
		}
		return ret;
	};
	int lo = -1e9, hi = 1e9;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (cost(mid - 1) >= cost(mid)) {
			ans = cost(mid);
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	assert(~ans);
	cout << ans;
}
