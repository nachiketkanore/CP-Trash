/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 08 August 2021 03:50:38 PM IST
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

#define sz(x) (int)(x.size())
#define int int64_t
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

#ifndef DEBUG
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

int32_t main() {
	const int N = 10500;
	int cnt0 = 0, bad_cnt = 0;
	;
	FOR(i, 1, N) {
		int u = i;
		int len = 0;
		int prod = 1;
		bool has0 = false;
		while (u > 0) {
			len++;
			prod *= u % 10;
			has0 |= u % 10 == 0;
			u /= 10;
		}
		if (has0)
			cnt0++;
		int fact = 1;
		while (len > 1) {
			fact *= len;
			len--;
		}
		if (prod >= fact) {
			// see(i, prod, fact);
		} else {
			bad_cnt++;
			// see("BAD..", i);
			if (!has0)
				see("BAD.. ", i);
		}
	}
	see(cnt0, bad_cnt);
}
