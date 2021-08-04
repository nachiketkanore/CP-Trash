#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 1e6 + 5, inf = 1e18;
const int mod = 1e9 + 7;

int n;
string s;
int dp[6][N];

int go(int id, int rem) {
	if (id == n)
		return rem == 0;
	int &ans = dp[rem][id];
	if (~ans) return ans;
	ans = go(id + 1, rem);
	ans = (ans + go(id + 1, (rem * 10 + (s[id] - '0')) % 6)) % mod;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		cin >> s;
		n = sz(s);
		memset(dp, -1, sizeof(dp));
		cout << (go(0,0) - 1 + mod) % mod << '\n';
	}	
}