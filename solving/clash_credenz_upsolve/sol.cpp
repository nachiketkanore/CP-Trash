/*
Author: Nachiket Kanore
Created: Wednesday 02 December 2020 12:46:14 AM IST
(ツ) Wisdom begins in wonder.
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

const int N = 600 + 5, inf = 1e18;
const int mod = 1e9 + 7;

vector<int> g[N];
int n, m;
int u, v;
int dp[N][502];


int go(int curr, int rem) {
	if (rem == 0) {  return curr == v; }
	int &ans = dp[curr][rem];
	if (~ans) return ans;
	ans = 0;
	for (int to : g[curr]) ans = (ans + go(to, rem-1)) % mod;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	FOR (i,1,m) {
		char ch;	cin >> ch;
		int a, b;	cin >> a >> b;
		g[a].push_back(b);
		if (ch == 'U') {
			g[b].push_back(a);
		}
	}
	memset(dp, -1, sizeof(dp));
	cin >> u >> v;
	int Q;	cin >> Q;
	while (Q--) {
		int k;	cin >> k;
		cout << go(u, k) << "\n";
	}
}
