/*
Author: Nachiket Kanore
Created: Friday 20 November 2020 02:29:09 PM IST
(ツ) Sometimes our fate resembles a fruit tree in winter. Who would think that those branches would turn green again and blossom, but we hope it, we know it.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e5+1, mod = 30;
const int inf = 1e9;

int n;
vector<int> a;
int dp[mod][N];
vector<int> ans;

int go(int id, int rem) {
	if (id == n)
		return (rem == 0? 0 : -inf);
	int &ans = dp[rem][id];
	if (~ans) return ans;
	ans = -inf;
	ans = max(ans, go(id+1, rem));
	ans = max(ans, 1 + go(id+1, (rem*10 + a[id])%mod));
	return ans;
}

void trace(int id, int rem) {
	if (id == n) {
		assert(!rem);
		return;
	}
	int best = go(id, rem);
	assert(best);
	int c1 =  1 + go(id+1, (rem*10 + a[id])%mod);
	if (c1 == best) {
		ans.push_back(a[id]);
		return trace(id+1, (rem*10 + a[id])%mod);
	}
	int c2 = go(id+1, rem);
	if (c2 == best) {
		return trace(id+1, rem);
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	a.resize(n);
	for (int &x : a) cin >> x;

	memset(dp, -1, sizeof(dp));
	sort(a.rbegin(), a.rend());
	
	int mxLen = go(0, 0);
	if (mxLen <= 0) 
		cout << "-1\n";
	else {
		trace(0, 0);
		reverse(ans.begin(), ans.end());
		while (sz(ans) > 1 && ans.back() == 0) ans.pop_back();
		reverse(ans.begin(), ans.end());
		for (int x : ans) cout << x;	cout << "\n";
	}
}
