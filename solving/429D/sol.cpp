/*
Author: Nachiket Kanore
Created: Saturday 26 December 2020 12:08:14 AM IST
(ツ) The bird of paradise alights only upon the hand that does not grasp.
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

const int N = 2e5 + 5, inf = 1e18;

struct Point {
	int x, y;

	Point operator-(Point p) {
		return { x - p.x, y - p.y };
	}

	int dist() {
		return x * x + y * y;
	}
};

bool by_x(Point& a, Point& b) {
	return a.x < b.x;
}

bool by_y(Point& a, Point& b) {
	return a.y < b.y;
}

int n, ans = 1e18;
int a[N], pref[N];
Point pt[N];

int solve(int L, int R) {
	if (L == R)
		return 1e18;
	int M = (L + R) / 2;

	sort(pt + L, pt + R + 1, by_x);
	int d = min(solve(L, M), solve(M + 1, R));
	int midx = pt[L + (R - L + 1) / 2].x;

	vector<Point> v;
	for (int i = L; i <= R; i++) {
		if (Point{ pt[i].x - midx, 0 }.dist() < d) {
			v.push_back(pt[i]);
		}
	}
	sort(v.begin(), v.end(), by_y);
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (Point{ 0, v[i].y - v[j].y }.dist() > d)
				break;
			d = min(d, (v[i] - v[j]).dist());
		}
	}
	return d;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1, u; i <= n; i++) {
		cin >> u;
		sum += u;
		pt[i].x = i;
		pt[i].y = sum;
	}

	cout << solve(1, n) << "\n";
}
