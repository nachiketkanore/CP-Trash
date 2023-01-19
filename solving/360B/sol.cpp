/*
Author: Nachiket Kanore
Created: Monday 09 November 2020 12:31:37 PM IST
(ツ) The universe is full of magical things, patiently waiting for our wits to grow sharper.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T, size_t size> ostream& operator<<(ostream& os, const array<T, size>& arr) {
	os << '{';
	string sep;
	for (const auto& x : arr)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

const int N = 2e3 + 5, inf = 2e10;

int n, k, a[N], D;

int go(int from) {
	if (from == n)
		return 0;

	int ans = inf;

	FOR(to, from + 1, n) {
		int diff = abs(a[to] - a[from]);
		if (diff <= D) {
			int changes = to - from - 1;
			ans = min(ans, changes + go(to));
		}
	}

	return ans;
}

bool possible(int diff) {
	::D = diff;
	int minUpdates = go(1);
	see(diff, minUpdates);
	return minUpdates <= k;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i];
	}

	int lo = 0, hi = inf;
	int ans = -1;

	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (possible(mid)) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	// assert(~ans);
	cout << ans << "\n";
}

/*
In final sequence, not all numbers will be changed
	Let's say we want to achieve diff = D

Say, _ _ _ _ a _ _ _ b c d e _ _ _ f g h i _ _ _ , _ ones are changed
		   x	   y             z             k
	 x x x	   y y           z z           k k
		   abs(y - x) <= D
		   abs(z - y) <= D
		   abs(k - z) <= D

	1 2 3 4 y
	1 1 1 1 y
	changes = 3
*/