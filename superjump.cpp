/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 03:20:26 PM IST
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
const int _ = 1002;
int N, M, mat[_][_], row_sum[_][_], col_sum[_][_];
vector<pair<int, int>> next_right[_][_];
mi dp[_][_];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			char ch;
			cin >> ch;
			mat[i][j]	  = ch - '0';
			row_sum[i][j] = mat[i][j] + row_sum[i][j - 1];
			col_sum[i][j] = mat[i][j] + col_sum[i - 1][j];
		}
	}
	dp[1][1] = mat[1][1] != 1;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (i == 1 && j == 1)
				continue;
			if (mat[i][j])
				continue;
			// from left
			{
				int lo = 1, hi = j - 1, col = -1;
				while (lo <= hi) {
					int mid = (lo + hi) / 2;
					int len = j - 1 - mid + 1;
					int sum = row_sum[i][j - 1] - row_sum[i][mid - 1];
					if (sum != len) {
						col = mid;
						lo	= mid + 1;
					} else {
						hi = mid - 1;
					}
				}
				if (~col) {
					assert(mat[i][col] == 0);
					dp[i][j] += dp[i][col];
				}
			}
			// from up
			{
				int lo = 1, hi = i - 1, row = -1;
				while (lo <= hi) {
					int mid = (lo + hi) / 2;
					int len = i - 1 - mid + 1;
					int sum = col_sum[i - 1][j] - col_sum[mid - 1][j];
					if (len != sum) {
						row = mid;
						lo	= mid + 1;
					} else {
						hi = mid - 1;
					}
				}
				if (~row) {
					assert(mat[row][j] == 0);
					dp[i][j] += dp[row][j];
				}
			}
		}
	}
	cout << dp[N][M];
	return 0;
}
