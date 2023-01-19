/**
 *    Author: Nachiket Kanore
 *    Created: Monday 14 March 2022 11:36:41 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
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

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int n = 1; n <= 15; n++) {
		vector<int> a;
		for (int i = 1; i <= n; i++) {
			a.push_back(i);
		}
		int ans = 0;
		vector<int> b;
		for (int i = 1; i <= n; i++) {
			b.push_back(i);
		}
		do {
			bool ok = true;
			for (int i = 0; i < n && ok; i++) {
				ok &= a[i] != b[i];
			}
			ans += ok;
		} while (next_permutation(b.begin(), b.end()));
		see(n, ans);
	}
	return 0;
}
