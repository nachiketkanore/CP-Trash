/**
 *    Author: Nachiket Kanore
 *    Created: Monday 06 June 2022 12:55:52 AM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int_fast64_t
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

/* bool vis[51][51][10001];
mi dp[51][51][10001];

mi go(int steps, int rem, int stop) {
	if (rem < stop)
		return 0;
	if (steps == 0)
		return rem == stop ? 1 : 0;

	if (vis[rem][stop][steps])
		return dp[rem][stop][steps];
	vis[rem][stop][steps] = true;

	mi& prob = dp[rem][stop][steps];
	prob = 0;

	for (int take = 0; take <= rem; take++) {
		prob += inv_mod[rem + 1] * go(steps - 1, rem - take, stop);
	}

	return prob;
} */

/* mi inv_mod[51];
mi dp[10001][51];

void init(int K = 10000, int alpha = 50) {
	// dp[k][j] = probability that after k steps
	// p^alpha becomes p^j
	F0R(i, K + 1) F0R(j, alpha + 1) dp[i][j] = 0;
	dp[0][alpha] = 1;

	FOR(step, 1, K) {
		for (int curr = 0; curr <= alpha; curr++) {
			for (int take = 0; take <= curr; take++) {
				dp[step][curr - take] += dp[step - 1][curr] * inv_mod[curr + 1];
			}
		}
	}
} */

mi inv_mod[51];

vector<mi> init(int K, int alpha) {
	// dp[k][j] = probability that after k steps
	// p^alpha becomes p^j
	vector<mi> dp(alpha + 1);
	dp[alpha] = 1;

	FOR(step, 1, K) {
		vector<mi> ndp(alpha + 1);
		for (int curr = 0; curr <= alpha; curr++) {
			mi add = dp[curr] * inv_mod[curr + 1];
			// ndp[curr - 0] += add;
			// ndp[curr - 1] += add;
			// 	.
			// 	.
			// 	.
			// ndp[curr - curr] += add;
			ndp[0] += add;
			if (curr + 1 <= alpha)
				ndp[curr + 1] -= add;
			// ^^ applying static range updates
			// O(alpha) speedup

			/* for (int take = 0; take <= curr; take++) {
				ndp[curr - take] += dp[curr] * inv_mod[curr + 1];
			} */
		}
		FOR(i, 1, alpha) ndp[i] += ndp[i - 1];
		dp = ndp;
	}
	return dp;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	FOR(i, 1, 50) {
		inv_mod[i] = mi(1) / i;
	}

	vector<array<int, 2>> pf;

	for (int d = 2; d * d <= N; d++) {
		if (N % d)
			continue;
		int cnt = 0;
		while (N % d == 0)
			++cnt, N /= d;
		pf.push_back({ d, cnt });
	}

	if (N > 1) {
		pf.push_back({ N, 1 });
	}

	mi ans = 1;

	for (const auto it : pf) {
		int p = it[0], alpha = it[1];
		const vector<mi>& dp = init(K, alpha);

		mi result = 0, val = 1;
		for (int j = 0; j <= alpha; j++) {
			result += val * dp[j];
			val *= p;
		}
		ans *= result;
	}

	cout << ans << '\n';

	return 0;
}
