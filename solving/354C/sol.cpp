/*
Author: Nachiket Kanore
Created: Tuesday 15 December 2020 04:48:11 PM IST
(ツ) In the end we retain from our studies only that which we practically apply.
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

int n, k;
int a[N + 1];
int cnt[4 * N + 1];
int ans = 0, mn = inf;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i];
		ans = __gcd(ans, a[i]);
		cnt[a[i]]++;
		cmin(mn, a[i]);
	}

	FOR(i, 1, 4 * N) cnt[i] += cnt[i - 1];

	auto chk = [&](int L, int R) {
		if (L > R)
			return true;
		int here = cnt[R] - cnt[L - 1];
		return here == 0;
	};

	for (int get = mn; get >= 2; --get) {
		// Trying to make get as gcd of array
		bool ok = true;
		for (int m = get; m <= N; m += get) {
			int next_m = m + get;
			int L = m + k + 1;
			int R = next_m - 1;
			ok &= chk(L, R);
		}

		if (ok) {
			cout << get << "\n";
			return 0;
		}
	}

	cout << ans << "\n";
}
