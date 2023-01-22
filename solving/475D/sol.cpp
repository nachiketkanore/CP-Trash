/*
Author: Nachiket Kanore
Created: Wednesday 16 December 2020 06:37:19 PM IST
(ツ) Happiness cannot be travelled to, owned, earned, worn or consumed. Happiness is the spiritual experience of living every minute with love, grace and gratitude.
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

const int N = 1e5 + 5, inf = 1e18;

int n, a[N];

// can be used for Range min/max/gcd range query in O(1)
class sparseTable {
	public:
	int RMQ[20][N];
	int floorlog[N];

	void precompute(int n) {
		for (int i = 0; (1 << i) < N; i++) {
			for (int j = (1 << i); j < N && j < (1 << (i + 1)); j++)
				floorlog[j] = i;
		}

		for (int i = n; i >= 1; i--) {
			RMQ[0][i] = a[i];			   // leaf value
			int mxj = floorlog[n - i + 1]; // 2^j <= n-i+1
			int pw = 1;
			for (int j = 1; j <= mxj; j++) {
				RMQ[j][i] = __gcd(RMQ[j - 1][i], RMQ[j - 1][i + pw]); // operation
				pw <<= 1;
			}
		}
	}

	int query(int L, int R) {
		int k = floorlog[R - L + 1];					   // 2^k <= R-L+1
		return __gcd(RMQ[k][L], RMQ[k][R - (1 << k) + 1]); // operation
	}
} T;

map<int, int> answers;

void precompute() {
	// for a fixed L, gcd (L, L+1, ... , n) is sharply non-increasing array
	// sharply meaning atmost log(MAX) distinct values

	FOR(L, 1, n) {
		// finding max R s.t gcd[L ... R] is same for any gcd[L ... i] i <= R

		int from = L;

		while (from <= n) {
			// finding next_from for which gcd[from ... next_from] is same
			assert(L <= from);
			int want = T.query(L, from);

			int next_from = -1;
			int lo = from, hi = n;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (T.query(L, mid) == want) {
					next_from = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}

			assert(~next_from);
			assert(T.query(L, next_from) == want);

			int len = next_from - from + 1;
			answers[want] += len;
			from = next_from + 1;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	FOR(i, 1, n)
	cin >> a[i];

	T.precompute(n);

	precompute();

	int Q;
	cin >> Q;
	while (Q--) {
		int u;
		cin >> u;
		cout << answers[u] << "\n";
	}
}
