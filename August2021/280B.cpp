/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 01 September 2021 03:08:17 PM IST
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
	int N, ans = 0;
	cin >> N;
	vector<int> A(N); 
	for (int &x: A) cin >> x;
	auto cal = [&](){
		vector<int> stk;
		F0R (i,N) {
			int u = A[i];
			while (stk.size() && stk.back() < u) stk.pop_back();
			if (stk.size()) cmax(ans, stk.back() ^ u);
			stk.push_back(u);
		}
		reverse(ALL(A));
	};
	cal(); cal();
	cout << ans << '\n';
}
