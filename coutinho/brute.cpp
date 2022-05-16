/**
 *    Author: Nachiket Kanore
 *    Created: Monday 16 May 2022 12:52:21 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T, size_t size>
ostream& operator<<(ostream& os, const array<T, size>& arr) {
	os << '{';
	string sep;
	for (const auto& x : arr)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() {
	cout << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cout << ' ' << H;
	dbg_out(T...);
}

#ifdef DEBUG
#define see(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

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
const int _ = 5e5 + 5;
const int MAX = 1e5;
int N, Q, cnt[_];
vector<pair<int, int>> B;
int spf[MAX + 1];
const int PRIMES = 9592;
const int Y_MAX = 1e4;
bool vis[PRIMES][Y_MAX + 1];
mi dp[PRIMES][Y_MAX + 1];

mi go(int id, int rem) {
	if (rem == 0)
		return mi(1);
	if (id == N)
		return rem == 0 ? mi(1) : mi(0);
	if (vis[id][rem])
		return dp[id][rem];
	vis[id][rem] = true;
	mi& ans = dp[id][rem];
	ans = 0;

	int prime = B[id].first;
	int cnt = B[id].second;
	F0R(take, rem + 1) {
		if (take <= cnt) {
			ans += pow(mi(prime), take) * go(id + 1, rem - take);
		}
	}
	return ans;
}

void precompute() {
	FOR(p, 2, MAX) {
		if (!spf[p]) {
			for (int m = p; m <= MAX; m += p) {
				if (!spf[m]) {
					spf[m] = p;
				}
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// TODO: Optimize with polynomials?
	// HOWTO ?????
	precompute();
	cin >> N >> Q;
	FOR(i, 1, N) {
		int u;
		cin >> u;
		while (u > 1) {
			int p = spf[u];
			while (u % p == 0) {
				cnt[p]++;
				u /= p;
			}
		}
	}
	FOR(i, 2, MAX) {
		if (spf[i] == i) {
			// i is prime number
			if (cnt[i] > 0) {
				B.push_back(make_pair(i, cnt[i]));
			}
		} else {
			assert(cnt[i] == 0);
		}
	}
	N = B.size();
	// see(B);
	while (Q--) {
		int Y;
		cin >> Y;
		cout << go(0, Y) << '\n';
	}
	return 0;
}
