/*
Author: Nachiket Kanore
Created: Monday 19 April 2021 12:04:47 PM IST
(ツ) Logic will get you from A to B. Imagination will take you everywhere.
*/
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
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;

int go(vector<int> D) {
	int n = sz(D);
	int best = 0;

	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && D[i] == D[j])
			j++;

		best = max(best, j - i + 1);

		if (j < n)
			best = max(best, j - i + 2);

		if (j < n - 1 && D[j] + D[j + 1] == 2 * D[i]) {
			int end = j + 2;

			while (end < n && D[end] == D[i])
				end++;

			best = max(best, end - i + 1);
		}
	}

	return best;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), diff(n-1);

	F0R (i,n) cin >> a[i];
	
	for (int i = 1; i < n; i++) {
		diff[i-1] = a[i] - a[i-1];
	}
	
	int ans = go(diff);
	reverse(ALL(diff));
	cmax(ans, go(diff));
	
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	FOR (tc,1,T) {
		cout << "Case #" << tc << ": ";
		solve();
	}
}
