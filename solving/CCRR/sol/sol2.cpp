/*
Author: Nachiket Kanore
Created: Monday 22 February 2021 03:38:56 PM IST
(ツ) I do not believe in a fate that falls on men however they act; but I do believe in a fate that falls on them unless they act.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

inline int rand(int l, int r){
    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> uid(l, r); return uid(rng);
}

const int inf = 1e17;

void solve(int tc) {
	int n;	
	cin >> n;
	int ans = -inf;
	vector<int> a(n+2), pref(n+2), left(n+2, -inf), right(n+2, -inf);
	FOR (i,1,n) {
		cin >> a[i];
		pref[i] = pref[i-1] + a[i];
		cmax(ans, pref[i]);
	}
	int sum = 0, min_behind = inf;
	FOR (i,1,n) {
		sum += a[i];
		int best_here = max(sum, sum - min_behind);
		cmax(left[i], best_here);
		cmin(min_behind, sum);
	}
	sum = 0, min_behind = inf;
	for (int i = n; i; --i) {
		sum += a[i];
		int best_here = max(sum, sum - min_behind);
		cmax(right[i], best_here);
		cmin(min_behind, sum);
	}
	int max_left = -inf;
	FOR (i,1,n) {
		cmax(ans, right[i+1] + max_left);
		cmax(max_left, left[i]);
		if (i > 1 && i < n)
			cmax(ans, left[i-1] + right[i+1]);
	}
	FOR (i,1,n) cmax(ans, left[i]);
	FOR (i,1,n) cmax(ans, right[i]);
	assert(ans != -inf);
	if (ans < 0) ans = 0;
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;	cin >> T;
	FOR (t,1,T) solve(t);
}
