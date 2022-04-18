/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 05:08:47 PM IST
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

const int MX = 1000;
vector<int> divs[MX + 1];

void solve() {
	// writing a brute force first
	int N, M;
	cin >> N >> M;
	vector<mi> dp(M + 1, mi(1));
	dp[0] = 0;
	F0R(i, N - 1) {
		vector<mi> ndp(M + 1, mi(0));
		FOR(prev, 1, M) {
			// we need to add 'dp[prev]' to multiples of prev
			// also..
			for (int multiple = 2 * prev; multiple <= M; multiple += prev) {
				ndp[multiple] += dp[prev];
			}
			for (const int& divisor : divs[prev]) {
				ndp[divisor] += dp[prev];
			}
			/* FOR(now, 1, M) {
				if (prev % now == 0 || now % prev == 0) {
					ndp[now] += dp[prev];
				}
			} */
		}
		dp = ndp;
	}
	mi ans = 0;
	FOR(last, 1, M) ans += dp[last];
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	FOR(i, 1, MX) {
		FOR(j, 1, i) {
			if (i % j == 0) {
				divs[i].push_back(j);
			}
		}
	}
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
