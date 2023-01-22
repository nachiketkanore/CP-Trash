/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 May 2022 07:54:07 PM IST
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

void solve() {
	int N;
	cin >> N;
	vector<int> even, odd;
	F0R(i, N) {
		int u;
		cin >> u;
		if (u & 1)
			odd.push_back(u);
		else
			even.push_back(u);
	}
	if (N == 2) {
		cout << "YES\n";
		return;
	}
	assert(sz(even) == sz(odd));
	const int M = even.size();
	sort(ALL(even));
	sort(ALL(odd));
	F0R(i, M - 1) {
		even[M - 1] += even[i];
		even[i] = 0;
	}
	F0R(i, M - 1) {
		odd[M - 1] += odd[i] - 1;
		odd[i] = 1;
	}
	// see(odd);
	// see(even);
	int E = even.back();
	int O = odd.back();
	int req = O - 1;
	E += req;
	if (E % (2 * M) == 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
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
