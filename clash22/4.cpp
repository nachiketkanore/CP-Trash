/**
 *    Author: Nachiket Kanore
 *    Created: Friday 15 April 2022 10:22:19 AM IST
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

const int mod = 1e9 + 7;
const int N = 1e5;
int factmod[N];

void pre() {
	factmod[0] = 1;
	for (int i = 1; i < N; i++)
		factmod[i] = factmod[i - 1] * i % mod;
}

int power(int a, int b) {
	int ret = 1;
	a %= mod;
	while (b > 0) {
		if (b % 2)
			ret = ret * a % mod;
		b /= 2;
		a = a * a % mod;
	}
	return ret;
}

int nCr(int n, int r) {
	if (r > n)
		return 0;
	int num = factmod[n];
	int deno = factmod[n - r] * factmod[r] % mod;
	deno = power(deno, mod - 2);
	int ans = num * deno % mod;
	return ans;
}
int n, m, k;

int go(int id, int rem) {
	if (rem < 0)
		return 0;
	if (id == -1)
		return rem == 0;
	int ans = 0;
	FOR(xi, 0, min(n, rem)) {
		ans += nCr(n, xi) * go(id - 1, rem - xi);
	}
	return ans;
}

int power(int a, int b, int mod) {
	int ret = 1;
	a %= mod;
	while (b > 0) {
		if (b % 2)
			ret = ret * a % mod;
		b /= 2;
		a = a * a % mod;
	}
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	pre();
	cin >> n >> m >> k;
	vector<int> vals;
	F0R(i, n) {
		int P = 0;
		F0R(x1, n + 1) {
			// F0R(i, n) {
			int get = nCr(n, x1) * go(i - 1, k - x1);
			P += get;
		}
		vals.push_back(P);
	}
	const int MOD = 1e9 + 7;
	int P = vals.back();
	see(vals);
	see(P);
	int ans = power(P, m / n, MOD);
	see(vals[m % n] % MOD);
	cout << ans;
	return 0;
}
