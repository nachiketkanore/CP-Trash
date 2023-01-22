/*
Author: Nachiket Kanore
Created: Thursday 17 December 2020 12:23:38 AM IST
(ツ) The least movement is of importance to all nature. The entire ocean is affected by a pebble.
*/
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
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
template <typename T> ostream& operator<<(ostream& os, const set<T>& v) {
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
template <typename A, typename B> ostream& operator<<(ostream& os, const map<A, B>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
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

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) {
	return uniform_int_distribution<int>(a, b)(mt_rng);
}

template <int D, typename T> struct vec : public vector<vec<D - 1, T>> {
	static_assert(D >= 1, "Dimensions invalid");
	template <typename... Args> vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {
	}
};
template <typename T> struct vec<1, T> : public vector<T> {
	vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
	}
};

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 2e5 + 5, inf = 5e18;

vector<int> a;

int mod;
int dp[2][2][2][2][2][20];

int go(int id, int c0, int c1, int c10, bool smallTaken, bool started) {
	if (id == sz(a))
		return c0 > 0 && c1 > 0 && c10 > 0;

	int& ans = dp[c0 > 0][c1 > 0][c10 > 0][smallTaken][started][id];
	if (~ans)
		return ans;
	ans = 0;
	int curr = a[id];
	int from = 0, to = 15;
	if (!smallTaken)
		from = 0, to = curr;

	FOR(d, from, to) {
		int nc0 = 0, nc1 = 0, nc10 = 0;
		if (started || d > 0) {
			nc0 = c0 + (d == 0);
			nc1 = c1 + (d == 1);
			nc10 = c10 + (d == 10);
		}
		int get = go(id + 1, nc0, nc1, nc10, smallTaken || (d < curr), started || (d > 0));
		ans += get;
		if (ans > inf) {
			see("overflow");
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	FOR(i, 1, 16) a.pb(15);
	mod = LLONG_MAX - 10;
	// see(LLONG_MAX);
	// see(inf);

	memset(dp, -1, sizeof(dp));
	int ans = go(0, 0, 0, 0, 0, 0);
	see("Decimal answer:", ans);

	string answer;

	while (ans > 0) {
		int d = ans % 16;
		char add;
		if (d <= 9)
			add = (char)(d + '0');
		else
			add = (char)('A' + (d - 10));
		answer.pb(add);
		ans /= 16;
	}

	reverse(ALL(answer));
	see(answer);
}

// Decimal answer: 4420408745587516162
// (answer): 3D58725572C62302

// answer almost overflowing (too big number)
// 4420408745587516162
// 4420408745587516162

// wrong
// 4041301415130921870