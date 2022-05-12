/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 10 May 2022 08:01:20 PM IST
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
	int N, K;
	cin >> N >> K;
	int A[N];
	F0R(i, N) cin >> A[i];
	sort(A, A + N);
	vector<int> vals;
	for (int i = 0; i < N;) {
		int j = i + 1, cnt = 1;
		while (j < N && A[i] == A[j]) {
			cnt++;
			j++;
		}
		if (cnt >= K) {
			vals.push_back(A[i]);
		}
		i = j;
	}
	const int M = vals.size();
	// see(vals);
	int ans = 0;
	int l = -1, r = -1;
	for (int i = 0; i < M;) {
		int L = vals[i];
		int R = L;
		int prev = vals[i];
		int j = i + 1;
		while (j < M && prev + 1 == vals[j]) {
			R++;
			prev = vals[j];
			j++;
		}
		if (R - L >= r - l) {
			r = R;
			l = L;
		}
		i = j;
	}
	if (r == -1 || l == -1) {
		cout << "-1\n";
	} else {
		cout << l << ' ' << r << '\n';
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
