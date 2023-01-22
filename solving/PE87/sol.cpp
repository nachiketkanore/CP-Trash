/*
Author: Nachiket Kanore
Created: Wednesday 16 December 2020 07:58:51 PM IST
(ツ) Your vision will become clear only when you can look into your own heart. Who looks outside, dreams; who looks inside, awakes.
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

const int N = 50e6, inf = 1e18;

vector<int> primes;
bool prime[N + 1];
bool ok[N + 1];

pair<bool, int> power(int val, int b) {
	int ret = 1;
	while (b--) {
		ret *= val;
		if (ret > N)
			return { false, -1 };
	}
	if (ret <= N)
		return { true, ret };
	return { false, -1 };
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(prime + 2, prime + N + 1, true);
	for (int i = 2; i <= N; i++)
		if (prime[i]) {
			primes.push_back(i);
			for (int j = 2 * i; j <= N; j += i)
				prime[j] = false;
		}

	// see(primes);

	for (int i = 0; i < sz(primes); i++) {
		auto one = power(primes[i], 2);
		if (!one.first)
			break;
		for (int j = 0; j < sz(primes); j++) {
			auto two = power(primes[j], 3);
			if (!two.first)
				break;
			for (int k = 0; k < sz(primes); k++) {
				auto three = power(primes[k], 4);
				if (!three.first)
					break;
				int val = one.second + two.second + three.second;
				if (val <= N)
					ok[val] = 1;
			}
		}
	}

	int ans = 0;
	FOR(i, 1, N) ans += ok[i];
	see(ans);
}
