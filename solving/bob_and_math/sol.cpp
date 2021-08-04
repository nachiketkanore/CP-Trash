/*
Author: Nachiket Kanore
Created: Friday 11 December 2020 04:47:49 PM IST
(ツ) Do good by stealth, and blush to find it fame.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e6+5;
const int mod = 1e9+7;
const int cmod = mod-1;

bool prime[N+1];
int dp[2002][2002];

int power(int a, int b, int p) {
	int ret = 1;
	a %= p;
	while (b > 0) {
		if (b & 1) 
			ret = ret * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ret;
}

int nCr(int n, int r) {
	if (r < 0) return 0;
	if (n == 0) return r == 0;
	int &ans = dp[n][r];
	if (~ans) return ans;
	ans = 0;
	ans = (ans + nCr(n-1,r)) % cmod;
	ans = (ans + nCr(n-1,r-1)) % cmod;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	fill(prime+2, prime+N, true);
	for (int i = 2; i <= N; i++) if (prime[i]) for (int j = 2*i; j <= N; j += i) prime[j] = false;
	memset(dp, -1, sizeof(dp));

	int T;	cin >> T;
	while (T--) {
		int n;	cin >> n;
		int P = 0, NP = 0;
		FOR (i,1,n) {
			int u;	cin >> u;
			P += prime[u];
			NP += !prime[u];
		}

		int ans = 1;
		FOR (i,0,P) {
			int up = nCr(P, i) * power(2, NP, cmod);
			up %= cmod;
			int mul = power(i+2, up, mod);
			ans = (ans * mul) % mod;
		}
		cout << ans << "\n";
	}

}
