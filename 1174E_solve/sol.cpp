/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 12 April 2022 09:51:30 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
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
int multiples[21][2];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// fuck memory constraints
	int N;
	cin >> N;
	F0R(i, 21) {
		F0R(j, 2) {
			multiples[i][j] = N / ((1LL << i) * (j ? 3 : 1));
		}
	}
	vector<vector<mi>> dp(21, vector<mi>(2, 0));
	int p2 = 0;
	F0R(bit, 22) {
		if ((1LL << bit) <= N)
			p2 = bit;
	}
	dp[p2][0] = 1;
	if ((1LL << (p2 - 1)) * 3 <= N) {
		dp[p2 - 1][1] = 1;
	}
	F0R(i, N - 1) {
		vector<vector<mi>> ndp(21, vector<mi>(2, 0));
		F0R(p2, 21) {
			F0R(p3, 2) {
				// choice 1: keep GCD constant by inserting a multiple of GCD
				{
					int mul = multiples[p2][p3] - (i + 1);
					if (mul < 0)
						mul = 0;
					ndp[p2][p3] += dp[p2][p3] * mul;
				}
				// choice 2: reduce GCD by 2 by inserting a multiple of GCD / 2
				if (p2 > 0) {
					int mul = multiples[p2 - 1][p3] - multiples[p2][p3];
					ndp[p2 - 1][p3] += dp[p2][p3] * mul;
				}
				// choice 3: reduce GCD by 3 by inserting a multiple of GCD / 3
				if (p3 > 0) {
					int mul = multiples[p2][p3 - 1] - multiples[p2][p3];
					ndp[p2][p3 - 1] += dp[p2][p3] * mul;
				}
			}
		}
		dp = ndp;
	}
	cout << dp[0][0] << '\n';
	return 0;
}
