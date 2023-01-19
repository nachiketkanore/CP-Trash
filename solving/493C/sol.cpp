/*
Author: Nachiket Kanore
Created: Saturday 26 December 2020 05:09:16 PM IST
(ツ) We choose our joys and sorrows long before we experience them.
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

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	int m;
	cin >> m;
	vector<int> b(m);
	for (int& x : b)
		cin >> x;
	sort(ALL(a));
	sort(ALL(b));

	vector<int> vals;
	for (int x : a)
		vals.pb(x), vals.pb(x - 1), vals.pb(x + 1);
	for (int x : b)
		vals.pb(x), vals.pb(x - 1), vals.pb(x + 1);
	sort(ALL(vals));

	int best = -inf;
	int scoreA = -1, scoreB = -1;

	for (int d : vals) {
		int teamA = 0, teamB = 0;
		{
			int id = upper_bound(ALL(a), d) - a.begin();
			int cnt3 = n - id, cnt2 = n - cnt3;
			see("A", d, cnt2, cnt3);
			teamA = 3 * cnt3 + 2 * cnt2;
		}
		{
			int id = upper_bound(ALL(b), d) - b.begin();
			int cnt3 = m - id, cnt2 = m - cnt3;
			teamB = 3 * cnt3 + 2 * cnt2;
			see("B", d, cnt2, cnt3);
		}
		int diff = teamA - teamB;
		if (cmax(best, diff)) {
			scoreA = teamA;
			scoreB = teamB;
		}
	}

	cout << scoreA << ":" << scoreB;
}
