/**
 *    Author: Nachiket Kanore
 *    Created: Monday 16 May 2022 01:35:11 AM IST
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

void solve() {
	int K;
	cin >> K;
	int A[8] = {};
	int sum = 0;
	FOR(i, 1, 7) cin >> A[i], sum += A[i];
	int ans = -1;
	auto okay = [&](int days) {
		FOR(start, 1, 7) {
			int len = 7 - start + 1;
			if (len > days)
				len = days;
			// if (len > days)
			// 	continue;
			int get = 0;
			int days_rem = days;
			FOR(i, start, start + len - 1) get += A[i], days_rem--;
			int full = days_rem / 7;
			get += sum * full;
			days_rem %= 7;
			int id = 1;
			while (days_rem--) {
				get += A[id];
				id++;
			}
			// see(days, start, get);
			if (get >= K)
				return true;
		}
		return false;
	};
	int lo = 1, hi = 1e12;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (okay(mid)) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	assert(~ans);
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
