/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 12 April 2022 06:52:04 PM IST
 **/
#include <bits/stdc++.h>

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int MOD = 1e9 + 7;
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
int N, dp[1000002][21][2];

int multiples(int p2, int p3) {
	int ret = N / ((1LL << p2) * (p3 ? 3 : 1));
	return ret;
}

int go(int id, int p2, int p3) {
	assert(p2 >= 0 && p3 >= 0);
	if (id == N + 1) {
		return !p2 && !p3;
	}
	// current GCD = 2^p2.3^p3
	int& ans = dp[id][p2][p3];
	if (~ans)
		return ans;
	ans = 0;
	// choice 1: keep GCD constant by inserting a multiple of GCD
	ans += 1ll * go(id + 1, p2, p3) * max(0, multiples(p2, p3) - (id - 1)) % MOD;
	if (ans >= MOD)
		ans -= MOD;
	// choice 2: reduce GCD by 2 by inserting a multiple of GCD / 2
	if (p2 > 0) {
		ans += 1ll * go(id + 1, p2 - 1, p3) * (multiples(p2 - 1, p3) - multiples(p2, p3)) % MOD;
		if (ans >= MOD)
			ans -= MOD;
	}
	// choice 3: reduce GCD by 3 by inserting a multiple of GCD / 3
	if (p3 > 0) {
		ans += go(id + 1, p2, p3 - 1) * 1ll * (multiples(p2, p3 - 1) - multiples(p2, p3)) % MOD;
		if (ans >= MOD)
			ans -= MOD;
	}
	// memo = ans.v;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	int p2 = 0;
	cin >> N;
	F0R(bit, 22) {
		if ((1LL << bit) <= N)
			p2 = bit;
	}
	// choosing what to put at 1st index
	int ans = go(2, p2, 0);
	if ((1LL << (p2 - 1)) * 3 <= N) {
		ans += go(2, p2 - 1, 1);
		if (ans < 0)
			ans = (ans + MOD) % MOD;
	}
	cout << ans << '\n';

	return 0;
}
