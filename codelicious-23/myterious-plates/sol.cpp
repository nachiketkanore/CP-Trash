/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 26 October 2023 05:08:21 PM IST
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

const int _ = 1005;
int N, K, A[_];
mi fact[_];

int compute_minimum_count() {
	int ans = 0;
	int id = 1;
	int remain = K;
	while (remain > 0 && id <= N) {
		++ans;
		remain -= A[id++];
	}

	return ans;
}

mi go(int id, int height_remain, int take) {
	if (id > N) {
		return height_remain <= 0 && take == 0;
	}

	mi ans = 0;

	ans += go(id + 1, height_remain, take);

	if (height_remain > 0 && take > 0) {
		ans += go(id + 1, height_remain - A[id], take - 1);
	}

	return ans;
}

void solve() {
	cin >> N >> K;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	sort(A + 1, A + N + 1);
	reverse(A + 1, A + N + 1);

	int M = compute_minimum_count();

	mi ans = go(1, K, M);
	if (ans == 0) {
		ans = fact[M] * fact[N - M];
	} else {
		ans *= fact[M] * fact[N - M];
	}

	cout << ans << '\n';
}

void solve2() {
	cin >> N >> K;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	sort(A + 1, A + N + 1);
	reverse(A + 1, A + N + 1);

	int M = compute_minimum_count();

	mi dp[N + 1][K + 1][M + 1];

	dp[0][0][0] = 1;

	FOR(id, 1, N) {
		FOR(w, 0, K) {
			FOR(cnt, 0, M) {
				dp[id][w][cnt] += dp[id - 1][w][cnt];
				if (w > 0 && cnt > 0)
					dp[id][w][cnt] += dp[id - 1][max(int(0), w - A[id])][cnt - 1];
			}
		}
	}

	// mi ans = go(1, K, M);
	mi ans = dp[N][K][M];
	if (ans == 0) {
		ans = fact[M] * fact[N - M];
	} else {
		ans *= fact[M] * fact[N - M];
	}

	cout << ans << '\n';
}

// O(N^3) time and O(N^2) memory
void solve3() {
	cin >> N >> K;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	sort(A + 1, A + N + 1);
	reverse(A + 1, A + N + 1);

	int M = compute_minimum_count();

	mi dp[K + 1][M + 1];
	dp[0][0] = 1;

	FOR(id, 1, N) {

		mi ndp[K + 1][M + 1];

		FOR(w, 0, K) {
			FOR(cnt, 0, M) {
				ndp[w][cnt] += dp[w][cnt];
				if (w > 0 && cnt > 0)
					ndp[w][cnt] += dp[max(int(0), w - A[id])][cnt - 1];
			}
		}

		F0R(i, K + 1) F0R(j, M + 1) dp[i][j] = ndp[i][j];
	}

	// mi ans = go(1, K, M);
	mi ans = dp[K][M];
	if (ans == 0) {
		ans = fact[M] * fact[N - M];
	} else {
		ans *= fact[M] * fact[N - M];
	}

	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	FOR(i, 1, _ - 1) fact[i] = fact[i - 1] * i;

	int T;
	cin >> T;

	while (T--) {
		solve3();
	}

	return 0;
}
