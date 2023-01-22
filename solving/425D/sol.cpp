/*
Author: Nachiket Kanore
Created: Saturday 26 December 2020 02:47:30 PM IST
(ツ) Reality is merely an illusion, albeit a very persistent one.
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

const int N = 1e5, inf = 1e18;
const int MAGIC = sqrt(N);

int n, ans;
vector<int> y_cords[N + 1];
vector<int> large_xs;

bool have(int x, int y) {
	vector<int>& look = y_cords[x];
	int id = lower_bound(ALL(look), y) - look.begin();
	if (id == sz(look))
		return false;
	return look[id] == y;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	FOR(i, 1, n) {
		int x, y;
		cin >> x >> y;
		y_cords[x].push_back(y);
	}

	FOR(x, 0, N) sort(ALL(y_cords[x]));

	FOR(x, 0, N) {
		if (sz(y_cords[x]) <= MAGIC) {
			// brute force for each pair
			for (int i = 0; i < sz(y_cords[x]); i++) {
				for (int j = i + 1; j < sz(y_cords[x]); j++) {
					int y1 = y_cords[x][i];
					int y2 = y_cords[x][j];
					int x2 = x;
					int x1 = x - (y2 - y1);
					if (x1 >= 0) {
						ans += have(x1, y1) && have(x1, y2);
					}
					x1 = x + (y2 - y1);
					if (x1 <= N && sz(y_cords[x1]) > MAGIC) {
						ans += have(x1, y1) && have(x1, y2);
					}
				}
			}
		} else {
			large_xs.push_back(x);
		}
	}

	for (int i = 0; i < sz(large_xs); i++) {
		for (int j = i + 1; j < sz(large_xs); j++) {
			int x1 = large_xs[i];
			int x2 = large_xs[j];
			for (int y1 : y_cords[x1]) {
				int len = x2 - x1;
				int y2 = y1 + len;
				ans += have(x2, y1) && have(x2, y2) && have(x1, y2);
			}
		}
	}

	cout << ans << "\n";
}
