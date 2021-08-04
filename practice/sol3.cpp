#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 200 + 5, inf = 1e12;

int n, k, twos, fives, a[N];
int dp[N][N * 30];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	FOR(i,0,N-1) FOR(j,0,N*30-1) dp[i][j] = -inf;
	dp[0][0] = 0;

	FOR(i,1,n) {
		cin >> a[i];
		int val = a[i];
		twos = fives = 0;
		while (val % 2 == 0) { val /= 2, twos++; }
		while (val % 5 == 0) { val /= 5, fives++; }

		for (int take = min(k, i); take >= 1; take--) {
			for (int want_fives = 30 * n; want_fives >= fives; want_fives--) {
				// Take or don't take a number in our subsequence
				dp[take][want_fives] = max(dp[take][want_fives], twos + dp[take - 1][want_fives - fives]);
			}
		}
	}

	int ans = 0;
	FOR(five,0,N*30-1) ans = max(ans, min(five, dp[k][five]));
	cout << ans;
}

/*
	
	fives can be atmost 26 * 200 in any subset
	twos can be atmost 63 * 200 in any subset

	int five = 5;
	int cnt = 1;
	while (five <= inf) {
		cnt += 1;
		five *= 5;
	}
	cnt = 26;
	
	
	4 * 10000 * 26 * 200
	We can't store index as a state
	So we just store the previous layer answers
*/