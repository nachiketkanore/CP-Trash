/**
 *    Author: Nachiket Kanore
 *    Created: Friday 18 March 2022 12:31:41 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = 998244353;
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

const int _ = 55;
int N, M, K, W[_];
mi prob[_], fact[55];
bool vis[_][_][_];
mi dp[_][_][_];

mi go(int id, int uniq, int len) {
	if (len > K || uniq > M)
		return mi(0);
	if (id == N) {
		if (uniq == M && len == K) {
			return mi(1);
		}
		return mi(0);
	}
	if (vis[id][uniq][len])
		return dp[id][uniq][len];
	vis[id][uniq][len] = true;
	mi ans = 0;
	ans += go(id + 1, uniq, len);
	for (int take = 1; take <= K; take++) {
		ans += (pow(prob[id], take) / fact[take]) * go(id + 1, uniq + 1, len + take);
	}
	dp[id][uniq][len] = ans;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	mi D = 0;
	for (int i = 0; i < N; i++) {
		cin >> W[i];
		D += W[i];
	}
	for (int i = 0; i < N; i++) {
		prob[i] = mi(W[i]) / mi(D);
	}
	fact[0] = 1;
	for (int i = 1; i < 55; i++) {
		fact[i] = i * fact[i - 1];
	}
	mi ans = fact[K] * go(0, 0, 0);
	cout << ans.v << '\n';
	return 0;
}
