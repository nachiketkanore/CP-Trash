/*
Author: Nachiket Kanore
Created: Friday 20 November 2020 01:49:55 PM IST
(ツ) Always bear in mind that your own resolution to succeed is more important than any one thing.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define F0R (i,R) for (int i = 0; i < R; i++)
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n;
set<int> ans;

int digs(int n) {
	return (!n ? 0 : 1+digs(n/10));
}

bool isPrime(int n) {
	if (n < 2) return false;
	for (int d = 2; d * d <= n; d++)
		if (n % d == 0)
			return false;
	return true;
}

void dfs(int val) {
	if (!isPrime(val)) return;
	if (digs(val) == n) {
		ans.insert(val);
		return;
	}

	FOR (d,0,9) dfs(val*10 + d);
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	F0R (i,n) cin >> a[i];
	sort(ALL(a));
	for (int i = 1; i < n; i++) {
		a[i] += a[i-1];
	}
	F0R (i,n) cout << a[i] << " \n"[i+1 == n];
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	dfs(2);
	dfs(3);
	dfs(5);
	dfs(7);

	for (int x : ans)
		cout << x << "\n";
}
