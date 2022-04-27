/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 27 April 2022 08:21:56 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

long double nth_root(int A, int N) {
	long double xPre = rand() % 10;

	long double eps = 1e-6;

	long double delX = 1e18;

	long double xK;

	while (delX > eps) {
		xK = ((N - 1.0) * xPre + (long double)A / powl(xPre, N - 1)) / (long double)N;
		delX = abs(xK - xPre);
		xPre = xK;
	}

	return xK;
}

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

void solve() {
	int N;
	cin >> N;
	if (N == 1) {
		cout << "0\n";
		return;
	}
	if ((N + 1) % 2 == 0) {
		cout << "1\n";
		return;
	}
	int p2 = 0;
	F0R(i, 64) {
		if (N % (1LL << i) == 0)
			p2 = i;
	}
	assert(p2 > 0);
	if (p2 % 2 == 1) {
		cout << "-1\n";
		return;
	}
	int ans = 2;
	int root = sqrtl(1. * N);
	if (root * root == N) {
		ans = 1;
	}
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
