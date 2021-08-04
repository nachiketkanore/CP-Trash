/*
Author: Nachiket Kanore
Created: Friday 16 October 2020 01:35:42 PM IST
(ツ) Through perseverance many people win success out of what seemed destined to be certain failure.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <map>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e3 + 5, mod = 998244353;

int n, k;
map<int,int> cnt;
std::vector<int> freqs;
int dp[N][N];

int go(int id, int taken) {
	if (taken > k) return 0;
	if (id == sz(freqs)) {
		return (taken == k ? 1 : 0);
	}
	int &ans = dp[id][taken];
	if (~ans) return ans;
	ans = 0;

	int c1 = freqs[id] * go(id + 1, taken + 1);
	c1 %= mod;
	int c2 = go(id + 1, taken);
	c2 %= mod;

	ans = c1 + c2;
	ans %= mod;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	FOR(i,1,n) {
		int val;
		cin >> val;
		cnt[val]++;
	}

	for (auto it : cnt) {
		freqs.push_back(it.second);
	}

	sort(freqs.begin(), freqs.end());

	if (sz(freqs) < k) {
		cout << 0;
		return 0;
	}

	memset(dp, -1, sizeof(dp));
	int ans = go(0, 0);
	cout << ans << '\n';
}

