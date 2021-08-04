/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 25 July 2021 04:34:29 PM IST
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
		int N, D;
		cin >> N >> D;
		vector<pair<int,int>> a(N);
		vector<int> pref(N);
		F0R (i,N) cin >> a[i].first; // price
		F0R (i,N) cin >> a[i].second; // sweetness
		sort(ALL(a));
		F0R (i,N) {
			pref[i] = a[i].second;
			if (i) cmax(pref[i], pref[i-1]);
		}
		int ans = 0;
		F0R (i,N) {
			auto [cost, get] = a[i];
			if (cost <= D) cmax(ans, get);
			else continue;
			int rem = D - cost;
			int id = -1;
			int lo = 0, hi = i - 1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (a[mid].first <= rem) id = mid, lo = mid + 1;
				else hi = mid - 1;
			}
			if (id >= 0 && id < N) {
				int best = pref[id];
				cmax(ans, get + best);
			}
		}
		cout << ans << '\n';
	}
}
