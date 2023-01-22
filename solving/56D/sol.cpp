/*
Author: Nachiket Kanore
Created: Monday 02 November 2020 09:58:56 AM IST
(ツ) He who fears being conquered is sure of defeat.
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

const int N = 1000 + 5, inf = 1e17;

string s, t;
int n, m, dp[N][N];

int go(int i, int j) {
	if (i == n)
		return m - j;
	if (j == m)
		return n - i;

	int& ans = dp[i][j];
	if (~ans)
		return ans;
	ans = inf;

	// insert
	int c1 = 1 + go(i, j + 1);
	ans = min(ans, c1);

	// delete
	int c2 = 1 + go(i + 1, j);
	ans = min(ans, c2);

	// replace
	int c3 = (s[i] != t[j]) + go(i + 1, j + 1);
	ans = min(ans, c3);

	return ans;
}

void trace(int i, int j, int add) {
	if (i == n) {
		for (int id = j; id < m; id++) {
			cout << "INSERT " << i + add + 1 << " " << t[id] << "\n";
			add++;
		}
		return;
	}
	if (j == m) {
		for (int id = i; id < n; id++) {
			cout << "DELETE " << i + add + 1 << "\n";
		}
		return;
	}

	int ans = go(i, j);

	// insert
	int c1 = 1 + go(i, j + 1);
	if (c1 == ans) {
		cout << "INSERT " << i + add + 1 << " " << t[j] << "\n";
		return trace(i, j + 1, add + 1);
	}

	// delete
	int c2 = 1 + go(i + 1, j);
	if (c2 == ans) {
		cout << "DELETE " << i + add + 1 << "\n";
		return trace(i + 1, j, add - 1);
	}

	// replace
	int c3 = (s[i] != t[j]) + go(i + 1, j + 1);
	if (c3 == ans) {
		if (s[i] != t[j]) {
			cout << "REPLACE " << i + add + 1 << " " << t[j] << "\n";
			return trace(i + 1, j + 1, add);
		}
		return trace(i + 1, j + 1, add);
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;
	n = sz(s), m = sz(t);
	see(n, m);

	memset(dp, -1, sizeof(dp));
	int ans = go(0, 0);
	cout << ans << "\n";
	trace(0, 0, 0);
}
