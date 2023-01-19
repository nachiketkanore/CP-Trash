/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 15 June 2021 10:24:39 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

namespace number_theory {
const int MX = 1e6 + 5;
bool prime[MX + 1];
int spf[MX + 1];
int count_divs[MX + 1];
void pre() {
	fill(prime + 2, prime + MX + 1, true);
	FOR(i, 2, MX) {
		if (prime[i]) {
			spf[i] = i;
			for (int j = 2 * i; j <= MX; j += i) {
				if (!spf[j])
					spf[j] = i;
				prime[j] = false;
			}
		}
	}
}
} // namespace number_theory

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

#ifdef DEBUG
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

const int inf = 1e18;
const int N = 5e5 + 5;

int n, D, p[N];

int32_t main() {
	{
		if (false) {
			int T;
			cin >> T;
			while (T--) {
				int x;
				cin >> x;
				int u, v;
				int hello;
				cin >> hello;
				int world = hello;
				if (world == 21) {
					cout << "My favourite number\n";
					return 0;
				}
				cin >> u >> v;
				if (u > v)
					swap(u, v);
				cout << "HERE HELLO WORLD\n";
				return 0;
			}
		}
	}
	cin >> n >> D;
	FOR(i, 1, n) cin >> p[i];
	int ans = 0;
	set<pair<int, int>> one, two;
	one.insert(make_pair(p[1] - 1 * D, 1));
	FOR(i, 2, n) {
		two.insert(make_pair(p[i] + i * D, i));
	}
	while (sz(one) ^ n) {
		auto [lhs, u] = *one.begin();
		auto [rhs, v] = *two.begin();
		two.erase(two.begin());
		ans += lhs + rhs;
		one.insert(make_pair(p[v] - v * D, v));
		see(u, v);
	}
	cout << ans;
}
