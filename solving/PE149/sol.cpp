/*
Author: Nachiket Kanore
Created: Wednesday 16 December 2020 10:56:51 PM IST
(ツ) Fears are nothing more than a state of mind.
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

const int N = 4e6, inf = 1e18;
const int M = 2000;

int a[N + 1];
int mat[M + 1][M + 1];
int dp[M + 1][M + 1][8];
bool vis[M + 1][M + 1][8];

int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, -1, 1, 1, -1, 1, -1 };

inline bool inside(int i, int j) {
	return i >= 1 && j >= 1 && i <= M && j <= M;
}

int go(int i, int j, int where) {
	if (!inside(i, j))
		return 0;

	if (vis[i][j][where])
		return dp[i][j][where];
	vis[i][j][where] = true;

	int ans = -inf;

	int ni = i + dx[where];
	int nj = j + dy[where];
	ans = max(ans, mat[i][j] + go(ni, nj, where));

	return dp[i][j][where] = ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int k = 1; k <= N; k++) {
		if (k <= 55)
			a[k] = (100003 - 200003 * k + 300007 * k * k * k) % 1000000 - (500000);
		else
			a[k] = (a[k - 24] + a[k - 55] + 1000000) % 1000000 - (500000);
	}

	see(a[10], a[100]);
	int id = 1;

	FOR(i, 1, M) {
		FOR(j, 1, M) {
			mat[i][j] = a[id++];
		}
	}

	int ans = 0;

	FOR(i, 1, M) {
		FOR(j, 1, M) {
			FOR(k, 0, 7) {
				ans = max(ans, go(i, j, k));
			}
		}
	}

	see(ans);
}
