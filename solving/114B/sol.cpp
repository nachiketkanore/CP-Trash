/*
Author: Nachiket Kanore
Created: Thursday 15 October 2020 07:44:50 PM IST
(ツ) It is the greatest of all mistakes to do nothing because you can only do little - do what you can.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 20, inf = 1e18;

int n, m;
string a[N];
map<string, int> id;
bool bad[N][N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	FOR(i,0,n-1) {
		cin >> a[i];
		id[a[i]] = i;
	}
	FOR(i,0,m-1) {
		string u, v;
		cin >> u >> v;
		bad[id[u]][id[v]] = 1;
		bad[id[v]][id[u]] = 1;
	}
	vector<int> ans;
	for (int mask = 0; mask < (1 << n); mask++) {
		vector<int> taken;
		for (int i = 0; i < n; i++) if (mask >> i & 1) taken.push_back(i);
		bool good = true;
		FOR(i,0,sz(taken)-1) FOR(j,i+1,sz(taken)-1) good &= !bad[taken[i]][taken[j]];
		if (good) {
			if (sz(taken) > sz(ans)) ans = taken;
		}
	}

	cout << sz(ans) << '\n';
	vector<string> ret;
	for (int idx : ans) ret.push_back(a[idx]);
	sort(ret.begin(), ret.end());
	for (string ss : ret) cout << ss << '\n'; 
}
