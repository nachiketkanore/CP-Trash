/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 07 May 2022 06:31:49 PM IST
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

struct choice {
	vector<pair<char, int>> C;
	choice operator+(pair<char, int> add) {
		choice nxt;
		nxt.C = C;
		nxt.C.push_back(add);
		return nxt;
	}
};

string A, B, C;
int N, M, K;

int solve(int i, int j, int k, bool ataken, bool btaken, choice my) {
	if (k == K) {
		if (ataken && btaken && i == N && j == M) {
			see(my.C);
			return 1;
		}
		return 0;
	}
	int ans = 0;

	// take C[k] from A[i]
	if (i < N && C[k] == A[i]) {
		ans += solve(i + 1, j, k + 1, 1, btaken, my + make_pair(A[i], 1));
	}
	// don't take A[i]
	if (i < N)
		ans += solve(i + 1, j, k, ataken, btaken, my);

	// take C[k] from B[j]
	if (j < M && C[k] == B[j]) {
		ans += solve(i, j + 1, k + 1, ataken, 1, my + make_pair(B[j], 2));
	}
	// don't take B[j]
	if (j < M)
		ans += solve(i, j + 1, k, ataken, btaken, my);

	return ans;
}

int go(int i, int j, int k, int at, int bt) {
	if (k == K) {
		return at && bt;
	}
	int ans = 0;
	// take from A
	for (int id = i; id < N; id++) {
		if (C[k] == A[id]) {
			ans += go(id + 1, j, k + 1, at | 1, bt);
		}
	}

	// take from B
	for (int id = j; id < M; id++) {
		if (C[k] == B[id]) {
			ans += go(i, id + 1, k + 1, at, bt | 1);
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B >> C;
	N = A.length();
	M = B.length();
	K = C.length();
	see(A);
	see(B);
	see(C);
	// cout << solve(0, 0, 0, 0, 0, C);
	int ans = 0;
	F0R(i, N) {
		if (A[i] == C[0]) {
			ans += go(i + 1, 0, 1, 1, 0);
		}
	}
	F0R(j, M) {
		if (B[j] == C[0]) {
			ans += go(0, j + 1, 1, 0, 1);
		}
	}
	cout << ans;
	return 0;
}
