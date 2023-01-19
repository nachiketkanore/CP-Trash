/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 05 May 2022 07:54:19 PM IST
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
	/* int N, K;
	cin >> N >> K;
	string S;
	cin >> S;
	if (K >= 25) {
		cout << string(N, 'a') << '\n';
		return;
	}
	int mx_dist = 0;
	F0R(i, N) {
		int dist = S[i] - 'a';
		if (dist > K) {
			char L = S[i] - (K - mx_dist);
			char R = S[i];
			F0R(j, N) {
				if (L <= S[j] && S[j] <= R) {
					S[j] = L;
				}
			}
			break;
		} else {
			mx_dist = max(mx_dist, dist);
		}
	}
	F0R(i, N) {
		int dist = S[i] - 'a';
		if (dist <= mx_dist) {
			S[i] = 'a';
		}
	}
	cout << S << '\n'; */
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
