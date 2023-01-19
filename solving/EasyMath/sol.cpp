/*
Author: Nachiket Kanore
Created: Tuesday 10 November 2020 02:42:52 PM IST
(ツ) Difficulties are things that show a person what they are.
*/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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

const int mod = (int)1e9;

int n, r, dp[1002][1002];

int go(int id, int chosen) {
	if (chosen > r)
		return 0;
	if (id == n + 1)
		return chosen == r;
	int& ans = dp[id][chosen];
	if (~ans)
		return ans;
	ans = 0;

	ans = (ans + go(id + 1, chosen)) % mod;
	ans = (ans + go(id + 1, chosen + 1)) % mod;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		FOR(i, 1, n) FOR(j, 0, n) dp[i][j] = -1;
		FOR(i, 0, n) r = i, cout << go(1, i) << " \n"[i == n];
	}
}
