#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 1e6 + 5, mod = 1e9 + 7;

int n, dp[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	dp[0] = 1;
	FOR(i,1,n) {
		int val;
		cin >> val;
		vector<int> divs;
		for (int d = 1; d * d <= val; d++) if (val % d == 0) {
			divs.push_back(d);
			if (val / d != d)
				divs.push_back(val / d);
		}
		sort(divs.rbegin(), divs.rend());
		for (int pos : divs) {
			dp[pos] = (dp[pos] + dp[pos - 1]) % mod;
		}
	}
	int ans = 0;
	FOR(i,1,n) ans = (ans + dp[i]) % mod;
	cout << ans;
}