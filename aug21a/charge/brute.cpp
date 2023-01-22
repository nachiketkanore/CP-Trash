/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 10 August 2021 07:25:19 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int M = 105;
int N;
pair<int, int> A[10000];
int dp[M][M];

bool compare(const pair<int, int>& one, const pair<int, int>& two) {
	return one.first < two.first;
	return one.second < two.second;
}

int go(int id, int from) {
	if (id == N)
		return 0;
	int& ans = dp[id][from];
	if (~ans)
		return ans;
	ans = 0;
	ans = max(ans, go(id + 1, from));

	auto [want, leaves] = A[id];

	if (from + want <= leaves) {
		ans = max(ans, 1 + go(id + 1, from + want));
	}

	return ans;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	F0R(i, N) cin >> A[i].first;  // A[i]
	F0R(i, N) cin >> A[i].second; // T[i]
	sort(A, A + N, compare);
	cout << go(0, 0) << '\n';
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
