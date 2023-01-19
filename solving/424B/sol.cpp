/*
Author: Nachiket Kanore
Created: Tuesday 15 December 2020 06:36:53 PM IST
(ツ) Good instincts usually tell you what to do long before your head has figured it out.
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

const int N = 1000 + 5, inf = 1e18;

int n, p[N];
array<int, 2> a[N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	using ld = double;

	const int MILL = 1e6;
	cin >> n >> p[0];

	int tot = p[0];
	a[0][0] = a[0][1] = 0;

	FOR(i, 1, n) {
		cin >> a[i][0] >> a[i][1];
		cin >> p[i];
		tot += p[i];
	}

	if (tot < MILL) {
		cout << "-1\n";
		return 0;
	}

	ld ans = 1e9;
	ld lo = 0, hi = 1e9;

	auto dist = [&](int x, int y) {
		ld ret = 1.0 * x * x + 1.0 * y * y;
		ret = (ld)sqrt(ret);
		return ret;
	};

	auto poss = [&](ld radius) {
		int gathered = 0;
		for (int i = 0; i <= n; i++) {
			ld far = dist(a[i][0], a[i][1]);
			if (far <= radius) {
				gathered += p[i];
			}
		}
		return gathered >= MILL;
	};

	for (int itr = 0; itr < 100; itr++) {
		ld mid = (lo + hi) / 2.0;
		if (poss(mid)) {
			ans = mid;
			hi = mid;
		} else {
			lo = mid;
		}
	}

	printf("%0.8lf\n", ans);
}
