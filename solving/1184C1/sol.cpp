/*
Author: Nachiket Kanore
Created: Tuesday 17 November 2020 11:33:37 AM IST
(ツ) Choose a job you love, and you will never have to work a day in your life.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

vector<array<int,2>> pts;

bool chk(vector<array<int,2>>& a, int cx, int cy) {
	int mnX = inf, mxX = -inf;
	int mnY = inf, mxY = -inf;
	for (auto &[x,y] : a) {
		mnX = min(mnX, x);
		mxX = max(mxX, x);
		mnY = min(mnY, y);
		mxY = max(mxY, y);
	}
	if (cx == mnX) {
		if (mnY <= cy && cy <= mxY) return false;
	} if (cx == mxX) {
		if (mnY <= cy && cy <= mxY) return false;
	} if (cy == mnY) {
		if (mnX <= cx && cx <= mxX) return false;
	} if (cy == mxY) {
		if (mnX <= cx && cx <= mxX) return false;
	}
	return (mxX - mnX) == (mxY - mnY);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	n = (n << 2) + 1;
	FOR (i,1,n) {
		int x, y;
		cin >> x >> y;
		pts.push_back({x, y});
	}
	FOR (i,1,n) {
		vector<array<int,2>> rem;
		FOR (j,1,n) if (i^j) rem.push_back(pts[j-1]);
		if (chk(rem, pts[i-1][0], pts[i-1][1])) {
			cout << pts[i-1][0] << ' ' << pts[i-1][1] << "\n";
			return 0;
		}
	}

	assert(false);
}
