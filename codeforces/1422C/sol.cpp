/**
 *    Author: Nachiket Kanore
 *    Created: Friday 29 September 2023 08:19:10 PM IST
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

const int MAX = 1e5;
string S;
int N;
mi pow10sum[MAX + 1], suff[MAX + 1], suff_sum[MAX + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// precompute power 10 sums
	pow10sum[0] = 1;
	mi p10 = 1;
	FOR(i, 1, MAX) {
		p10 *= 10;
		pow10sum[i] = pow10sum[i - 1] + p10;
	}

	cin >> S;
	N = sz(S);
	S = "$" + S;

	mi ans = 0;

	// precompute suffix value sums
	suff[N] = suff_sum[N] = mi(int(S[N] - '0'));
	p10 = 1;
	for (int i = N - 1; i >= 1; i--) {
		int digit = S[i] - '0';
		p10 *= 10;
		mi curr_suff = digit * p10 + suff[i + 1];
		suff[i] = curr_suff;
		// see(curr_suff);
		suff_sum[i] = curr_suff + suff_sum[i + 1];
	}

	mi pref_value = 0;
	FOR(i, 1, N) {
		int digit = S[i] - '0';
		pref_value = pref_value * 10 + digit;
		// see(pref_value);
		ans += pref_value * pow10sum[N - i] + suff_sum[i + 1];
	}

	ans -= (N + 1) * pref_value;
	ans += suff_sum[1];

	cout << ans << '\n';

	return 0;
}
