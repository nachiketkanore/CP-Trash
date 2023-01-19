/**
 *    Author: Nachiket Kanore
 *    Created: Monday 23 August 2021 05:19:48 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

int32_t main() {
	int N, X, M;
	while (cin >> N >> X >> M) {
		vector<int> mods;
		vector<bool> vis(M);
		while (1) {
			if (vis[X] || X == 0)
				break;
			vis[X] = true;
			mods.push_back(X);
			X = X * X % M;
		}
		int sum = 0;
		for (int x : mods)
			sum += x;
		if (mods.back() == 0) {
			mods.pop_back();
			if (N > sz(mods)) {
				cout << sum << '\n';
				continue;
			}
		}
		/* for (int mod: mods) cerr << mod << ' '; cerr << '\n'; */
		/* if (N > sz(mods)) { */
		/* 	cout << sum << '\n'; */
		/* 	continue; */
		/* } */
		int cycle = N / sz(mods);
		N %= sz(mods);
		int ans = cycle * sum;
		F0R(i, N) if (i < sz(mods)) ans += mods[i];
		cout << ans << '\n';
	}
}
