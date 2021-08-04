/*
Author: Nachiket Kanore
Created: Monday 16 November 2020 04:09:36 PM IST
(ツ) Sometimes by losing a battle you find a new way to win the war.
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

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, k, oneone[N], onezero[N], zeroone[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;

	int _11 = 0, _01 = 0, _10 = 0;

	FOR (i,1,n) {
		int t, a, b;
		cin >> t >> a >> b;
		if (!a && !b) continue;
		if (a && b) {
			oneone[++_11] = t;
		} else if (a && !b) {
			onezero[++_10] = t;
		} else if (!a && b) {
			zeroone[++_01] = t;
		} else assert(false);
	}

	sort(oneone + 1, oneone + _11 + 1);
	sort(onezero + 1, onezero + _10 + 1);
	sort(zeroone + 1, zeroone + _01 + 1);

	FOR (i,1,_11) oneone[i] += oneone[i-1];
	FOR (i,1,_10) onezero[i] += onezero[i-1];
	FOR (i,1,_01) zeroone[i] += zeroone[i-1];

	int ans(-1);

	FOR (take11,0,k) {
		if (take11 > _11) continue;
		int want01 = k - take11;
		int want10 = k - take11;
		if (want10 > _10) continue;
		if (want01 > _01) continue;
		
		int get = oneone[take11] + onezero[want10] + zeroone[want01];
		if (ans == -1 || ans > get)
			ans = get;
	}

	cout << ans << "\n";
}
