/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 16 April 2022 11:31:34 AM IST
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
template <typename T, size_t size> ostream& operator<<(ostream& os, const array<T, size>& arr) {
	os << '{';
	string sep;
	for (const auto& x : arr)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

const int MX = 1e5 + 5;
const int MOD = 998244353;

void trim(vector<int>& A) {
	while (sz(A) > MX) {
		A.pop_back();
	}
	while (!A.empty() && A.back() == 0) {
		A.pop_back();
	}
}

void print_polynomial(vector<int> P) {
	// cout << sz(P) << '\n';
	F0R(i, sz(P)) if (P[i]) {
		cout << P[i] << ".x^" << i << " + ";
		if (i == sz(P) - 1)
			cout << '\n';
	}
	cout << '\n';
	cout << '\n';
}

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

void print_B(vector<int> sums) {
	cout << "B = [";
	F0R(i, sz(sums)) if (sums[i] > 0) {
		int cnt = sums[i];
		while (cnt--) {
			cout << i << ", ";
		}
	}
	cout << "]\n";
}
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	vector<int> A(N), sums(MX);
	for (int& x : A) {
		cin >> x;
		sums[x]++;
	}
	sums[0] = 0;
	// print_polynomial(sums);
	F0R(i, K - 1) {
		vector<int> nsums(MX);
		F0R(i, sz(sums)) if (sums[i] > 0) {
			for (int a : A) {
				if (i + a < MX) {
					nsums[i + a] += sums[i];
					nsums[i + a] %= MOD;
				}
			}
		}
		sums = nsums;
		// print_polynomial(sums);
	}
	// trim(sums);
	print_polynomial(sums);
	print_B(sums);
	for (int i = 1; i < MX; i++) {
		sums[i] += sums[i - 1];
		sums[i] %= MOD;
	}
	mi deno = pow(mi(N), K);
	int Q;
	cin >> Q;
	while (Q--) {
		int L, R;
		cin >> L >> R;
		assert(L <= R);
		mi nume = mi(sums[R]) - mi(sums[L - 1]);
		// cout << nume << ' ' << deno << '\n';
		mi ans = nume / deno;
		cout << ans << '\n';
	}
	return 0;
}
