/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 27 April 2022 08:06:50 PM IST
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
	int N, R;
	cin >> N >> R;
	vector<array<int, 3>> A(N);
	F0R(i, N) cin >> A[i][1];
	F0R(i, N) cin >> A[i][2];
	F0R(i, N) A[i][0] = A[i][2] - A[i][1];
	sort(ALL(A));
	reverse(ALL(A));
	int ans = 0;
	F0R(i, N) {
		assert(A[i][0] < 0);
		int net = abs(A[i][0]);
		int cost = A[i][1];
		int k = (R - cost) / net;
		if (k < 0)
			continue;
		ans += k;
		R -= k * net;
		if (R >= cost) {
			++ans;
			R -= net;
		}
		assert(R >= 0);
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
