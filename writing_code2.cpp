/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 19 April 2022 10:01:24 PM IST
 **/
#include <bits/stdc++.h>

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

int MOD = 1e9 + 7;
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

const int N = 505;
mi dp[N][N], ndp[N][N], sum_dp[N][N];
bool sum_dp_vis[N][N];

inline mi compute_sum(int b, int s, int x) {
	if (b < 0 || s < 0)
		return mi(0);
	if (sum_dp_vis[b][s])
		return sum_dp[b][s];
	sum_dp_vis[b][s] = true;
	return sum_dp[b][s] = dp[b][s] + compute_sum(b - x, s - 1, x);
};

int32_t main() {
	// turns out global arrays are much faster
	// instead of multiple allocation / deallocation processes
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, sum, bugs;
	cin >> n >> sum >> bugs >> MOD;
	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
	}
	for (int i = 0; i * a[0] <= bugs && i <= sum; i++) {
		dp[i * a[0]][i] = 1;
	}
	FOR(i, 1, n - 1) {
		F0R(j, bugs + 1) F0R(k, sum + 1) {
			ndp[j][k] = 0;
			sum_dp_vis[j][k] = false;
		}
		FOR(b, 0, bugs) {
			FOR(s, 0, sum) {
				ndp[b][s] += compute_sum(b, s, a[i]);
			}
		}
		F0R(j, bugs + 1) F0R(k, sum + 1) dp[j][k] = ndp[j][k];
	}
	mi ans = 0;
	F0R(b, bugs + 1) ans += dp[b][sum];
	cout << ans << '\n';
	return 0;
}
