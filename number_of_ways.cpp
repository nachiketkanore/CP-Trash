/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 12:49:50 PM IST
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

void solve() {
	int N, M;
	cin >> N >> M;
	char mat[N][M];
	F0R(i, N) F0R(j, M) cin >> mat[i][j];
	vector<vector<mi>> dp(N, vector<mi>(M));
	dp[0][0] = mat[0][0] != '*';

	// first column
	for (int i = 1; i < N; i++) {
		if (mat[i][0] == '*')
			continue;
		for (int row = i - 1; row >= 0 && mat[row][0] != '*'; row--) {
			dp[i][0] += dp[row][0];
		}
	}

	// first row
	for (int j = 1; j < M; j++) {
		if (mat[0][j] == '*')
			continue;
		for (int col = j - 1; col >= 0 && mat[0][col] != '*'; col--) {
			dp[0][j] += dp[0][col];
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (mat[i][j] == '*')
				continue;
			for (int row = i - 1; row >= 0 && mat[row][j] != '*'; row--) {
				dp[i][j] += dp[row][j];
			}
			for (int col = j - 1; col >= 0 && mat[i][col] != '*'; col--) {
				dp[i][j] += dp[i][col];
			}
		}
	}

	cout << dp[N - 1][M - 1] << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
