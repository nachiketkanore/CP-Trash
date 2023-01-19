/**
 *    Author: Nachiket Kanore
 *    Created: Monday 23 May 2022 12:11:16 PM IST
 **/
#include "bits/stdc++.h"

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

	// A[i] = A[j] * A[k]
	// Iterate on A[i]
	// Then A[j] | A[i]
	// Iterate on A[j]: divisor of A[i]
	// A[i] and A[j] are fixed
	// Increment answer by count of A[k]

	int N;
	cin >> N;
	const int MAX = 2e5 + 1;
	int freq[MAX] = {};

	int A[N];
	F0R(i, N) {
		cin >> A[i];
		freq[A[i]]++;
	}

	int ans = 0;

	F0R(i, N) {
		for (int d = 1; d * d <= A[i]; d++) {
			if (A[i] % d == 0) {
				int one = d, two = A[i] / d;
				ans += freq[one] * freq[A[i] / one];
				// see(A[i], one, A[i] / one);
				if (one ^ two) {
					ans += freq[two] * freq[A[i] / two];
				}
			}
		}
	}

	cout << ans;

	return 0;
}
