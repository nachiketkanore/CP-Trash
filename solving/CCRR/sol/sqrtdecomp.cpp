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

const int N = 2e5 + 5;
const int SZ = sqrt(N);
int n, a[N];

// Supports range add and range queries
struct Bucket {
	int L, R;
	int values[SZ];
	bool lazy = false;
	int sumBlock = 0, lazyAdd = 0;

	void init(int l, int r) {
		for (int i = l; i <= r; i++) {
			values[i - L] = a[i];
		}
		L = l, R = r;
		sumBlock = lazyAdd = 0;
	}

	void semiUpdate(int l, int r, int val) {
		if (l > r)
			return;
		if (lazy) {
			for (int i = L; i <= R; i++) {
				values[i - L] += lazyAdd;
			}
			lazy = false;
			lazyAdd = 0;
		}
		for (int i = l; i <= r; i++) {
			sumBlock += abs(val - col[i - L]);
			contrib[i - L] += abs(val - col[i - L]);
			col[i - L] = val;
		}
	}

	void fullUpdate(int val) {
		if (lazy) {
			sumBlock += (abs(val - lazyValue) * (R - L + 1));
			extra += abs(val - lazyValue);
		} else {
			for (int i = L; i <= R; i++) {
				contrib[i - L] += abs(col[i - L] - val);
				sumBlock += abs(col[i - L] - val);
				col[i - L] = val;
			}
		}
		lazy = 1;
		lazyValue = val;
	}

	void update(int l, int r, int val) {
		if (l <= L && r >= R)
			fullUpdate(val);
		else
			semiUpdate(max(l, L), min(r, R), val);
	}

	int semiQuery(int l, int r) {
		if (l > r)
			return 0;
		if (lazy) {
			for (int i = L; i <= R; i++) {
				contrib[i - L] += extra;
				col[i - L] = lazyValue;
			}
			lazy = 0;
			extra = 0;
		}
		int answer = 0;
		for (int i = l; i <= r; i++)
			answer += contrib[i - L];
		return answer;
	}

	int fullQuery() {
		return sumBlock;
	}

	int query(int l, int r) {
		if (l <= L && r >= R)
			return fullQuery();
		else
			return semiQuery(max(l, L), min(r, R));
	}
};

Bucket blocks[SZ + 5];

void init() {
	int blcks = n / SZ + 1;
	int curL = 1, curR = SZ;
	for (int i = 1; i <= blcks; i++) {
		curR = min(curR, n);
		blocks[i].init(curL, curR);
		curL += SZ;
		curR += SZ;
	}
}

void update(int l, int r, int x) {
	int left = (l - 1) / SZ + 1;
	int right = (r - 1) / SZ + 1;
	for (int i = left; i <= right; i++)
		blocks[i].update(l, r, x);
}

int query(int l, int r) {
	int left = (l - 1) / SZ + 1;
	int right = (r - 1) / SZ + 1;
	int answer = 0;
	for (int i = left; i <= right; i++)
		answer += blocks[i].query(l, r);
	return answer;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
}