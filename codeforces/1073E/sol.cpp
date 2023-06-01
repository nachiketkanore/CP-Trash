/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 01 June 2023 11:21:44 AM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int MOD = 998244353;
struct mi {
	using ll = long long;
	ll v;
	explicit operator ll() const {
		return v;
	}
	mi() {
		v = 0;
	}
	mi(ll _v) {
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0)
			v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) {
		return a.v == b.v;
	}
	friend bool operator!=(const mi& a, const mi& b) {
		return !(a == b);
	}
	friend bool operator<(const mi& a, const mi& b) {
		return a.v < b.v;
	}
	mi& operator+=(const mi& m) {
		if ((v += m.v) >= MOD)
			v -= MOD;
		return *this;
	}
	mi& operator-=(const mi& m) {
		if ((v -= m.v) < 0)
			v += MOD;
		return *this;
	}
	mi& operator*=(const mi& m) {
		v = v * m.v % MOD;
		return *this;
	}
	mi& operator/=(const mi& m) {
		return (*this) *= inv(m);
	}

	friend mi pow(mi a, ll p) {
		mi ans = 1;
		assert(p >= 0);
		for (; p; p /= 2, a *= a)
			if (p & 1)
				ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) {
		assert(a.v != 0);
		return pow(a, MOD - 2);
	}

	mi operator-() const {
		return mi(-v);
	}
	mi& operator++() {
		return *this += 1;
	}
	mi& operator--() {
		return *this -= 1;
	}
	mi operator++(int32_t) {
		mi temp;
		temp.v = v++;
		return temp;
	}
	mi operator--(int32_t) {
		mi temp;
		temp.v = v--;
		return temp;
	}
	friend mi operator+(mi a, const mi& b) {
		return a += b;
	}
	friend mi operator-(mi a, const mi& b) {
		return a -= b;
	}
	friend mi operator*(mi a, const mi& b) {
		return a *= b;
	}
	friend mi operator/(mi a, const mi& b) {
		return a /= b;
	}
	friend ostream& operator<<(ostream& os, const mi& m) {
		os << m.v;
		return os;
	}
	friend istream& operator>>(istream& is, mi& m) {
		ll x;
		is >> x;
		m.v = x;
		return is;
	}
};

string S;
int n, K;
pair<mi, mi> dp[18][2][2][1 << 10];
bool vis[18][2][2][1 << 10];

// { sum, count }
pair<mi, mi> go(int id, bool small_taken, bool nonzero_taken, int mask) {
	if (id == n) {
		return __builtin_popcount(mask) <= K ? make_pair(0, 1) : make_pair(0, 0);
	}
	if (vis[id][small_taken][nonzero_taken][mask]) {
		return dp[id][small_taken][nonzero_taken][mask];
	}
	vis[id][small_taken][nonzero_taken][mask] = true;
	mi sum = 0, count = 0;
	const int8_t max_digit_here = small_taken ? 9 : S[id] - '0';
	for (int8_t digit = 0; digit <= max_digit_here; digit++) {
		bool small_taken_next = small_taken || (digit < S[id] - '0');
		bool nonzero_taken_next = nonzero_taken || digit > 0;
		int mask_next = mask | (nonzero_taken_next ? (1 << digit) : 0);
		auto [next_sum, next_count] = go(id + 1, small_taken_next, nonzero_taken_next, mask_next);

		sum += next_sum + next_count * digit * pow(mi(10), n - id - 1);
		count += next_count;
	}
	return dp[id][small_taken][nonzero_taken][mask] = { sum, count };
}

mi solve(int N) {
	::S = to_string(N);
	n = sz(S);
	memset(vis, false, sizeof(vis));
	return go(0, false, false, 0).first;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int L, R;
	cin >> L >> R >> K;
	cout << solve(R) - solve(L - 1) << '\n';

	return 0;
}
