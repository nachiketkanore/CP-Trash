/**
 *    Author: Nachiket Kanore
 *    Created: Friday 08 July 2022 11:18:17 AM IST
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

const int MAX = 1e5 + 5;
mi fact[MAX + 1];

mi choose(int n, int r) {
	if (r > n)
		return mi(0);
	return fact[n] / fact[r] / fact[n - r];
}

mi pref[26][MAX + 1];

void solve() {
	string S;
	cin >> S;
	const int len = S.size();
	int f[26] = { 0 };
	F0R(ch, 26) F0R(j, len + 1) pref[ch][j] = 0;
	for (char ch : S) {
		f[ch - 'a']++;
	}
	F0R(ch, 26) {
		int X = f[ch];
		if (X == 0)
			continue;
		FOR(d, 0, X) {
			pref[ch][d] = choose(X, d) + (d ? pref[ch][d - 1] : 0);
		}
	}
	int Q;
	cin >> Q;
	while (Q--) {
		char ch;
		int N;
		cin >> ch >> N;

		int X = f[ch - 'a'];
		int Y = len - X;
		if (N > X) {
			cout << 0 << '\n';
		} else {
			mi ans = pref[ch - 'a'][X];
			if (N - 1 >= 0) {
				ans -= pref[ch - 'a'][N - 1];
			}
			mi other = pow(mi(2), Y);
			ans *= other;
			cout << ans << '\n';
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	FOR(i, 1, MAX) {
		fact[i] = fact[i - 1] * i;
	}

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
