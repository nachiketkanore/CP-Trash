/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 19 April 2022 10:01:24 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

int MOD = 1e9 + 7;
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
void solve() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, sum, bugs;
	cin >> n >> sum >> bugs >> MOD;
	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
	}
	// mi dp[bugs + 1][sum + 1];
	vector<vector<mi>> dp(bugs + 1, vector<mi>(sum + 1));
	for (int i = 0; i * a[0] <= bugs && i <= sum; i++) {
		dp[i * a[0]][i] = 1;
	}
	FOR(i, 1, n - 1) {
		// mi ndp[bugs + 1][sum + 1];
		vector<vector<mi>> ndp(bugs + 1, vector<mi>(sum + 1));
		vector<vector<bool>> sum_dp_vis(bugs + 1, vector<bool>(sum + 1));
		vector<vector<mi>> sum_dp(bugs + 1, vector<mi>(sum + 1));
		function<mi(int, int, int)> compute_sum = [&](int b, int s, int x) {
			if (b < 0 || s < 0)
				return mi(0);
			if (sum_dp_vis[b][s])
				return sum_dp[b][s];
			sum_dp_vis[b][s] = true;
			return sum_dp[b][s] = dp[b][s] + compute_sum(b - x, s - 1, x);
		};
		FOR(b, 0, bugs) {
			FOR(s, 0, sum) {
				ndp[b][s] += compute_sum(b, s, a[i]);
				/* for (int k = 0; k * a[i] <= b && s - k >= 0; k++) {
					ndp[b][s] += dp[b - k * a[i]][s - k];
				} */
			}
		}
		F0R(j, bugs + 1) F0R(k, sum + 1) dp[j][k] = ndp[j][k];
	}
	mi ans = 0;
	F0R(b, bugs + 1) ans += dp[b][sum];
	cout << ans << '\n';
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
	char *stack, *send;
	stack = (char*)malloc(stsize);
	send = stack + stsize - 16;
	send = (char*)((uintptr_t)send / 16 * 16);
	asm volatile("mov %%rsp, (%0)\n"
				 "mov %0, %%rsp\n"
				 :
				 : "r"(send));
	func();
	asm volatile("mov (%0), %%rsp\n" : : "r"(send));
	free(stack);
}
int32_t main() {
	run_with_stack_size(solve, 1024 * 1024 * 240);
	return 0;
}
