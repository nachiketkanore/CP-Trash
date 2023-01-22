/*
Author: Nachiket Kanore
Created: Tuesday 29 December 2020 07:12:07 PM IST
(ツ) Gratitude is not only the greatest of virtues, but the paren't of all the others.
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

const double PI = acos(-1);

namespace fft {
typedef complex<double> base;
void fft(vector<base>& v, bool inv) {
	vector<base> w(v.size());
	for (int i = 2; i <= sz(v); i <<= 1) {
		int bsz = v.size() / i;
		base ang(cos(2 * PI / i), sin(2 * PI / i));
		if (inv)
			ang = base(1, 0) / ang;
		for (int j = 0; j < bsz; j++) {
			for (int k = 0; k < i; k++) {
				w[k] = v[bsz * k + j];
			}
			base pw(1, 0);
			for (int k = 0; k < i / 2; k++) {
				base a = w[2 * k], b = w[2 * k + 1] * pw;
				v[bsz * k + j] = a + b;
				v[bsz * k + j + v.size() / 2] = a - b;
				pw *= ang;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < sz(v); i++) {
			v[i] /= v.size();
		}
	}
}
vector<int> multiply(vector<int>& v, vector<int>& w) {
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 1;
	while (n < max(sz(v), sz(w)))
		n <<= 1;
	n <<= 1;
	fv.resize(n);
	fw.resize(n);
	fft(fv, 0);
	fft(fw, 0);
	for (int i = 0; i < n; i++)
		fv[i] *= fw[i];
	fft(fv, 1);
	vector<int> ret(n);
	for (int i = 0; i < n; i++)
		ret[i] = (round(fv[i].real()) > 0);
	return ret;
}
} // namespace fft

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> p(1001, 0);

	FOR(i, 1, n) {
		int u;
		cin >> u;
		p[u] = 1;
	}

	vector<int> final(1001);
	final[0] = 1;

	// final(x) = (p(x))^k

	while (k > 0) {
		if (k & 1)
			final = fft::multiply(final, p);
		p = fft::multiply(p, p);
		for (int& x : p)
			x = min(1LL, x);
		for (int& x : final)
			x = min(1LL, x);
		k >>= 1;
	}

	for (int i = 0; i < sz(final); i++)
		if (final[i])
			cout << i << " ";
}
