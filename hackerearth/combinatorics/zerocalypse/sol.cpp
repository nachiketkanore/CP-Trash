/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 24 February 2024 09:23:20 PM IST
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

mi fact[1000005];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	FOR(i, 1, 1000000) fact[i] = i * fact[i - 1];

	auto nCr = [&](int n, int r) {
		if (r > n)
			return mi(0);
		return fact[n] / fact[n - r] / fact[r];
	};

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int A[N];
		F0R(i, N) cin >> A[i];
		bool bad = false;
		F0R(i, N - 1) if (A[i] && A[i + 1] && A[i] > A[i + 1]) bad = true;
		if (bad) {
			cout << "0\n";
			continue;
		}
		mi ans = 1;
		bool zeros = false;
		for (int i = 0; i < N;) {
			if (A[i] != 0) {
				i++;
			} else {
				zeros = true;
				int j = i, count = 0;
				while (j < N && A[j] == 0) {
					++count;
					++j;
				}
				if (j == N) {
					cout << "-1\n";
					goto done;
				}
				int L = i ? A[i - 1] + 1 : 1, R = A[j] - 1;
				ans *= nCr(R - L + 1, count);
				if (ans == 0) {
					cout << "0\n";
					goto done;
				}
				i = j;
			}
		}
		if (!zeros)
			ans = 0;

		cout << ans << '\n';
	done:;
	}

	return 0;
}
