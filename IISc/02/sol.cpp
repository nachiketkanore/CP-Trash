/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 28 June 2022 10:41:05 PM IST
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
int get_mask(int val) {
	int mask = 0;
	while (val) {
		mask |= (1 << (val % 10));
		val /= 10;
	}
	return mask;
}

bool maskA[1 << 10], maskB[1 << 10], yes[1 << 10];
bool vis[2][2][20][1 << 10];
mi dp[2][2][20][1 << 10];
string S;

mi go(int id, int mask, bool nz, bool st) {
	if (id == sz(S)) {
		if (yes[mask] || (yes[mask | (1 << 0)])) {
			// see(val);
			return 1;
		}
		return 0;
	}

	if (vis[nz][st][id][mask])
		return dp[nz][st][id][mask];
	vis[nz][st][id][mask] = true;

	int L = 0, R = 9;
	if (!st)
		R = S[id] - '0';
	mi& ans = dp[nz][st][id][mask];
	ans = 0;

	FOR(dig, L, R) {
		int nmask = mask;
		if (nz || dig > 0) {
			nmask |= 1 << dig;
		}
		ans += go(id + 1, nmask, nz || (dig > 0), st || (dig < S[id] - '0'));
	}
	return ans;
}
/*
bool maskA[1 << 10], maskB[1 << 10], yes[1 << 10];
bool vis[2][20][1 << 10];
mi dp[2][20][1 << 10];
string S;

mi go(int id, int mask, bool st) {
	if (id == sz(S)) {
		return yes[mask];
	}

	if (vis[st][id][mask])
		return dp[st][id][mask];
	vis[st][id][mask] = true;

	int L = 0, R = 9;
	if (!st)
		R = S[id] - '0';
	mi& ans = dp[st][id][mask];
	ans = 0;

	FOR(dig, L, R) {
		int nmask = mask | (1 << dig);

		ans += go(id + 1, nmask, st || (dig < S[id] - '0'));
	}
	return ans;
}
*/
mi solve(int R) {
	S = to_string(R);
	memset(vis, false, sizeof(vis));
	// see(S, go(0, 0, false));
	return go(0, 0, false, false);
}

void solve() {
	int N, M;
	cin >> N >> M;
	F0R(i, 1 << 10) {
		maskA[i] = maskB[i] = yes[i] = false;
	}
	F0R(i, N) {
		int u;
		cin >> u;
		maskA[get_mask(u)] = true;
	}
	F0R(i, M) {
		int u;
		cin >> u;
		maskB[get_mask(u)] = true;
	}
	FOR(one, 1, (1 << 10) - 1) if (maskA[one]) {
		FOR(two, 1, (1 << 10) - 1) if (maskB[two]) {
			// see(one, two);
			yes[one | two] = true;
		}
	}
	int L, R;
	cin >> L >> R;
	if (L > R)
		swap(L, R);
	mi ans = solve(R) - solve(L - 1);

	cout << ans << '\n';
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
