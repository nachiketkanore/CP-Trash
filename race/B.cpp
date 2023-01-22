/**
 *    Author: Nachiket Kanore
 *    Created: Monday 16 May 2022 01:18:35 AM IST
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N), has(N + 1, 0);
	for (int& x : A) {
		cin >> x;
		has[x] = 1;
	}
	reverse(ALL(A));
	F0R(i, N) {
		int which;
		cin >> which;
		if (!has[which]) {
			cout << "0 ";
		} else {
			int cnt = 1;
			// see(A);
			while (sz(A) && A.back() != which) {
				has[A.back()] = 0;
				A.pop_back();
				++cnt;
			}
			assert(A.back() == which);
			has[A.back()] = 0;
			A.pop_back();
			cout << cnt << " ";
		}
	}
	return 0;
}
