/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 22 May 2022 04:25:10 PM IST
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

mi fact[1000];
int N;
string S;
/*
mi go(int L, int R, int len) {
	if (L > R)
		return fact[len] * fact[N - len] / fact[N];

	mi ans = 0;

	if (S[L] == S[R]) {
		ans += go(L + 1, R, len) + go(L, R - 1, len);
	} else {
		ans += go(L + 1, R, len) + go(L, R - 1, len) - go(L + 1, R - 1, len + 2);
	}

	return ans;
} */

bool pal(const string& T) {
	int i = 0, j = T.size() - 1;
	while (i < j) {
		if (T[i] != T[j])
			return false;
		i++;
		j--;
	}
	return true;
}

const int _ = 405;
mi dp[_][_][_];
bool vis[_][_][_];

mi go(int i, int j, int k) {
	if (k == 0)
		return 1;
	if (i > j)
		return 0;
	if (i == j) {
		return k == 1;
	}

	if (vis[i][j][k]) {
		return dp[i][j][k];
	}

	vis[i][j][k] = 1;

	if (k == 1) {
		return dp[i][j][k] = j - i + 1;
	}

	mi ans = (S[i] == S[j]) * go(i + 1, j - 1, k - 2);

	// if (i < j && S[i] == S[j]) {
	// 	ans = go(i + 1, j - 1, k - 1);
	// }

	ans += go(i + 1, j, k) + go(i, j - 1, k) - go(i + 1, j - 1, k);

	return dp[i][j][k] = ans;
}

void solve() {
	cin >> N >> S;
	/* mi brute_ans = 0;
	FOR(mask, 1, (1 << N)) {
		string T;
		F0R(i, N) {
			if (mask >> i & 1)
				T += S[i];
		}
		if (T.empty() || T == S)
			continue;
		if (pal(T)) {
			// cout << T << '\n';
			brute_ans += (fact[sz(T)] * fact[N - sz(T)]) / fact[N];
		}
	}
	brute_ans += 1; */

	F0R(i, N) F0R(j, N) F0R(k, N + 1) vis[i][j][k] = false;
	mi ans = 0;
	FOR(len, 1, N - 1) {
		mi cnt = go(0, N - 1, len);
		// mi cnt = dp2[1][N][len];
		ans += (cnt * fact[len] * fact[N - len]) / fact[N];
	}
	ans += 1;
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < 1000; i++) {
		fact[i] = i * fact[i - 1];
	}

	int T;
	cin >> T;

	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}

	return 0;
}
