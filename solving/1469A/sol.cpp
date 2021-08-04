/*
Author: Nachiket Kanore
Created: Monday 04 January 2021 06:05:20 PM IST
(ツ) Man is equally incapable of seeing the nothingness from which he emerges and the infinity in which he is engulfed.
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

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int offset = 200;
string s;
int n;
bool dp[100][300];
bool vis[100][300];

bool chk(int id, int bal) {
	if (bal < 0) return false;
	if (id == sz(s)) return bal == 0;

	if (vis[id][offset + bal])
		return dp[id][offset + bal];

	vis[id][offset + bal] = true;

	bool poss = false;
	if (s[id] == '?') {
		poss |= chk(id+1, bal+1);
		poss |= chk(id+1, bal-1);
	} else {
		if (s[id] == '(')
			poss |= chk(id+1, bal+1);
		else
			poss |= chk(id+1, bal-1);
	}
	dp[id][offset + bal] = poss;
	return poss;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		cin >> s;
		n = s.size();
		memset(vis, false, sizeof(vis));
		cout << (chk(0,0) ? "YES\n" : "NO\n");
	}
}
