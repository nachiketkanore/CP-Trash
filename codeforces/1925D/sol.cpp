/** - saw the solution, but understood completely then only submitting
 *    Author: Nachiket Kanore
 *    Created: Tuesday 13 February 2024 02:56:02 PM IST
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

const int MAX = 2e5;
mi fact[MAX + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	FOR(i, 1, MAX) fact[i] = fact[i - 1] * i;

	auto nCr = [&](int n, int r) { return fact[n] / fact[n - r] / fact[r]; };

	int T, N, M, K, a, b, f;
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		mi fsum = 0;
		mi total_ways = N * (N - 1) / 2;
		F0R(i, M) {
			cin >> a >> b >> f;
			fsum += f;
		}
		mi ans = (K * fsum) / total_ways;
		mi contribution = 0;
		F0R(choose, K + 1) {
			mi add = choose * (choose - 1) / 2;
			add *= nCr(K, choose);
			add *= mi(1) / pow(total_ways, choose);
			add *= pow(total_ways - 1, K - choose) / pow(total_ways, K - choose);
			contribution += add;
		}
		ans += M * contribution;
		cout << ans << '\n';
	}

	return 0;
}
