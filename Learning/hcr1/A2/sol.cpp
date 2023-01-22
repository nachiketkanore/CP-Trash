/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 12 September 2021 02:29:18 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

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
	cout << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cout << ' ' << H;
	dbg_out(T...);
}

#ifndef DEBUG
#define see(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
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

const int MOD = 1e9 + 7;
struct mod_int {
	int64_t val;
	mod_int() {
		val = 0;
	}
	mod_int(int64_t v) {
		val = v;
		if (val >= MOD)
			val %= MOD;
	}
	void operator=(mod_int other) {
		val = other.val;
	}
	void operator=(int64_t v) {
		this->val = mod_int(v).val;
	}
	bool operator==(mod_int other) const {
		return val == other.val;
	}
	bool operator!=(mod_int other) const {
		return val != other.val;
	}
	void operator+=(int64_t add) {
		add %= MOD;
		val += add;
		if (val >= MOD)
			val -= MOD;
	}
	void operator-=(int64_t sub) {
		sub %= MOD;
		sub = (sub + MOD) % MOD;
		val += sub;
		if (val < 0)
			val += MOD;
	}
	void operator*(int64_t mul) {
		mul %= MOD;
		val *= MOD;
		if (val >= MOD)
			val %= MOD;
	}
};

const int _ = 8e5 + 5;
int N;
string S;
int pref[_][26];

void add(int& x, int y) {
	y %= MOD;
	x += y;
	if (x >= MOD)
		x -= MOD;
}

bool check(int L, int R, char ch) {
	return (pref[R][ch - 'A'] - (L ? pref[L - 1][ch - 'A'] : 0)) > 0;
}

int go(int from) {
	if (from >= N)
		return 0;
	int ans = 0;
	int lo = from, hi = N - 1;
	int to = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		bool chk = check(from, mid, 'O') && check(from, mid, 'X');
		if (chk) {
			hi = mid - 1;
		} else {
			to = mid;
			lo = mid + 1;
		}
	}
	if (to == -1)
		ans = 1;
	else {
		ans = 1 + go(to + 1);
	}
	return ans;
}

void solve() {
	int ans = 0;
	cin >> N >> S;
	F0R(i, N) {
		pref[i][S[i] - 'A'] = 1;
		F0R(ch, 26) if (i > 0) {
			pref[i][ch] += pref[i - 1][ch];
		}
	}
	F0R(L, N) {
		int parts = go(L);
		assert(parts > 0);
		add(ans, parts - 1);
	}
	cout << ans << '\n';
}

int32_t main() {
	int T;
	cin >> T;
	FOR(i, 1, T) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
