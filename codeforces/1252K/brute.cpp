/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 02 June 2022 10:07:59 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

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

struct Matrix {
	mi mat[2][2];

	Matrix(bool identity = false) {
		memset(mat, 0, sizeof(mat));
		if (identity) {
			F0R(i, 2) mat[i][i] = 1;
		}
	}

	friend Matrix operator*(const Matrix& A, const Matrix& B) {
		Matrix res;
		F0R(i, 2) F0R(j, 2) F0R(k, 2) res.mat[i][j] += A.mat[i][k] * B.mat[k][j];
		return res;
	}
};

char S[100000];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, Q;
	cin >> N >> Q;
	FOR(i, 1, N) cin >> S[i];
	Matrix T[2];

	T[0].mat[0][0] = T[0].mat[0][1] = T[0].mat[1][1] = 1;
	T[1].mat[0][0] = T[1].mat[1][0] = T[1].mat[1][1] = 1;

	while (Q--) {
		int type, L, R;
		cin >> type >> L >> R;

		if (type == 1) {
			FOR(i, L, R) S[i] = S[i] ^ 'A' ^ 'B';
		} else {
			mi A, B;
			cin >> A >> B;
			Matrix ans(1);
			for (int i = R; i >= L; i--) {
				ans = ans * T[S[i] - 'A'];
			}

			mi ans_A = ans.mat[0][0] * A + ans.mat[0][1] * B;
			mi ans_B = ans.mat[1][0] * A + ans.mat[1][1] * B;

			cout << ans_A << ' ' << ans_B << '\n';
		}
	}

	return 0;
}
