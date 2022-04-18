/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 11:57:22 AM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int MOD = 1e9 + 7;
const int _	  = 5002;
int N;
string S;

/* int go(int id, int prev) {
	if (id == N - 1)
		return 1;
	int& ans = dp[id][prev];
	if (~ans)
		return ans;
	ans = 0;
	if (S[id] == '=') {
		// ans += sum of go(id + 1, [prev, prev])
		ans += go(id + 1, prev);
		// ans += get_sum(id + 1, prev, prev);
		if (ans >= MOD) {
			ans -= MOD;
		}
	}
	if (S[id] == '>') {
		// ans += sum of go(id + 1, [1, prev - 1])
		// ans += get_sum(id + 1, 1, prev - 1);
		FOR(put, 1, N) {
			if (put >= prev)
				break;
			ans += go(id + 1, put);
			if (ans >= MOD) {
				ans -= MOD;
			}
		}
	}
	if (S[id] == '<') {
		// ans += sum of go(id + 1, [prev + 1, N])
		// ans += get_sum(id + 1, prev + 1, N);
		for (int put = N; put >= 1; put--) {
			if (put <= prev)
				break;
			ans += go(id + 1, put);
			if (ans >= MOD) {
				ans -= MOD;
			}
		}
	}
	return ans;
} */

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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	/* int ans = 0;
	memset(dp, -1, sizeof(dp));
	FOR(first, 1, N) {
		ans += go(0, first);
		if (ans >= MOD) {
			ans -= MOD;
		}
	}
	cout << ans << '\n'; */
	// dp for length 1
	// all values are possible
	vector<mi> dp(N + 2, mi(1));
	dp[0] = 0;
	for (int i = 0; i < sz(S); i++) {
		// FOR(i, 1, N) {
		// 	dp[i] += dp[i - 1];
		// }
		char ch = S[i];
		vector<mi> ndp(N + 2, mi(0));
		FOR(prev, 1, N) {
			if (ch == '=') {
				// prev == put
				// add dp[prev] to range [prev, prev]
				ndp[prev] += dp[prev];
				ndp[prev + 1] -= dp[prev];
				/* FOR(put, prev, prev) {
					ndp[put] += dp[prev];
				} */
			}
			if (ch == '<') {
				// prev < put
				// add dp[prev] to range [prev + 1, N]
				if (prev + 1 <= N) {
					ndp[prev + 1] += dp[prev];
					ndp[N + 1] -= dp[prev];
				}
				/* FOR(put, prev + 1, N) {
					ndp[put] += dp[prev];
				} */
			}
			if (ch == '>') {
				// prev > put
				// add dp[prev] to range[1, prev - 1]
				if (1 <= prev - 1) {
					ndp[1] += dp[prev];
					ndp[prev] -= dp[prev];
				}
				/* FOR(put, 1, prev - 1) {
					ndp[put] += dp[prev];
				} */
			}
		}
		FOR(i, 1, N) ndp[i] += ndp[i - 1];
		dp = ndp;
	}
	mi ans = 0;
	FOR(last, 1, N) ans += dp[last];
	cout << ans << '\n';
	return 0;
}
