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

int n, k, sum, a[N];
vector<int> vals;

int power(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1)
			ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}

void gather() {
	if (k == -1) {
		vals.pb(1);
		vals.pb(-1);
		return;
	}

	if (k == 1) {
		vals.pb(1);
		return;
	}

	for (int p = 0;; p++) {
		int expo = power(k, p);
		if (abs(expo) > sum)
			break;
		vals.pb(expo);
	}
}

void UNIQUE() {
	vector<int> ret;
	sort(ALL(vals));
	for (int x : vals) {
		if (ret.empty() || ret.back() != x)
			ret.push_back(x);
	}
	vals = ret;
}

int cntSubs(int k) {
	int ret = 0;
	map<int, int> freq;
	freq[0] = 1;
	int sum = 0;

	FOR(i, 1, n) {
		sum += a[i];
		ret += freq[sum - k];
		freq[sum]++;
	}
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i];
		sum += abs(a[i]);
	}
	gather();

	see(vals);

	int ans = 0;

	UNIQUE();

	for (int k : vals) {
		ans += cntSubs(k);
	}

	cout << ans << "\n";
}
