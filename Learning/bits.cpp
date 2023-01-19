/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 18 September 2021 11:13:46 AM IST
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

void decodePacket(string s) {
	const int N = s.size();
	if (N % 8 != 0) {
		cout << "Invalid Packet\n";
		return;
	}
	if (N / 8 == 1) {
		cout << "Invalid Packet\n";
		return;
	}
	vector<int> vals;
	for (int i = 0; i < N; i += 8) {
		int val = 0;
		for (int j = i; j < i + 8; j++) {
			val |= (s[j] - '0') * (1 << (7 - (j - i)));
		}
		vals.push_back(val);
	}
	const int len = vals[1];
	const int key = vals[0];
	for (int i = 2; i < sz(vals); i++) {
		cout << (char)((key ^ vals[i]));
	}
	cout << '\n';
}

int32_t main() {
	string s;
	cin >> s;
	decodePacket(s);
}
