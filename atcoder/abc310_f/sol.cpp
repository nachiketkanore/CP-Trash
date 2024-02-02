/**
 *    Author: Nachiket Kanore
 *    Created: Friday 02 February 2024 10:28:40 AM IST
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

const int MAX = 100;
int N, A[MAX];
bool vis[MAX][1 << 11];
mi dp[MAX][1 << 11];

mi go(int id, int mask) {
	if (id == N) {
		return mi(mask >> 10 & 1);
	}
	if (vis[id][mask])
		return dp[id][mask];
	vis[id][mask] = true;
	int above = max(int(0), A[id] - 10);
	mi ans = above * go(id + 1, mask);
	FOR(put, 1, 10) if (put <= A[id]) {
		int nmask = mask;
		nmask |= 1 << put;
		F0R(j, 10) if (mask >> j & 1) {
			int add = j + put;
			if (add <= 10)
				nmask |= 1 << add;
		}

		ans += go(id + 1, nmask);
	}
	return dp[id][mask] = ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	mi total = 1;
	F0R(i, N) {
		cin >> A[i];
		total *= A[i];
	}
	mi ways = go(0, 1 << 0);

	mi ans = ways / total;
	cout << ans;
	return 0;
}
