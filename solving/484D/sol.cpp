/*
Author: Nachiket Kanore
Created: Saturday 26 December 2020 12:57:06 AM IST
(ツ) The key to transforming our hearts and minds is to have an understanding of how our thoughts and emotions work.
*/
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
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

const int N = 1e6, inf = 1e18;

int n, a[N + 1];
int dp[N + 1];
vector<int> peaks;

int get_next_peak(int from) {
	int id = upper_bound(ALL(peaks), from) - peaks.begin();
	if (id == sz(peaks))
		return n;
	return peaks[id];
}

int go(int id) {
	// start = id, end = next_peak, next_peak_prev
	if (id >= n)
		return 0;
	int& ans = dp[id];
	if (~ans)
		return ans;
	ans = 0;

	int nxt = get_next_peak(id);
	assert(nxt > id);

	int c1 = abs(a[nxt] - a[id]) + go(nxt + 1);
	int c2 = abs(a[nxt - 1] - a[id]) + go(nxt);

	ans = max(c1, c2);
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 2, n - 1) {
		if ((a[i - 1] >= a[i] && a[i] <= a[i + 1]) || (a[i - 1] <= a[i] && a[i] >= a[i + 1]))
			peaks.push_back(i);
	}
	memset(dp, -1, sizeof(dp));
	cout << go(1);
}
