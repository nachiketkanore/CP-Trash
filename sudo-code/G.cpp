/**
 *    Author: Nachiket Kanore
 *    Created: Monday 08 November 2021 08:11:59 PM IST
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
	int N, K;
	cin >> N >> K;
	int A[N]; F0R (i,N) cin >> A[i];
	int sum = 0;
	vector<int> costs;
	F0R (i,N-1) {
		sum += A[i] > 0 ? +1 : -1;
		if (sum == 0) {
			costs.push_back(abs(abs(A[i]) - abs(A[i+1])));
		}
	}
	sort(ALL(costs));
	int ans = 0;
	for (int cost: costs) {
		if (cost <= K) {
			K -= cost;
			++ans;
		}
	}
	cout << ans;
}
