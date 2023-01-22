/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 15 June 2021 09:55:10 PM IST
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
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

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

const int inf = 1e18;
const int N = 5e5 + 5;

int spf[N + 10]; // Can go upto N = 1e7

void SPF() {

	spf[1] = 1;

	for (int i = 2; i <= N; i++)
		if (spf[i] == 0) {
			spf[i] = i;
			for (int j = 2 * i; j <= N; j += i)
				if (spf[j] == 0)
					spf[j] = i;
		}
}

int digs(int u) {
	return (u == 0 ? 0 : 1 + digs(u / 10));
}

bool chk(int u) {
	if (u == 1)
		return true;
	string s = to_string(u);
	int t = 0;
	while (u > 1) {
		int p = spf[u];
		int e = 0;
		while (u % p == 0) {
			u /= p;
			e++;
		}
		if (e == 1)
			t += digs(p);
		else
			t += digs(e) + digs(p);
	}
	return sz(s) == t;
}

int dp[N + 1];

int32_t main() {
	{
		if (false) {
			int x;
			cin >> x;
		}
	}
	SPF();
	vector<int> jumps;
	FOR(len, 1, 20005) {
		if (chk(len)) {
			jumps.push_back(len);
		}
	}

	dp[0] = 0;
	FOR(i, 1, N) dp[i] = inf;

	for (int d = 1; d <= 40000; d++) {
		for (int j : jumps) {
			if (d >= j)
				cmin(dp[d], dp[d - j] + 1);
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << dp[b - a] << '\n';
	}
}
