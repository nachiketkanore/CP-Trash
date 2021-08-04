/*
Author: Nachiket Kanore
Created: Sunday 22 November 2020 04:01:44 PM IST
(ツ) History will be kind to me for I intend to write it.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, Q, a[N];
using pii = pair<int,int>;
vector<pii> sod_pos[100];

int SOD(int x) {
	return (x == 0 ? 0 : x%10 + SOD(x/10));
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> Q;

	FOR (i,1,n) {
		cin >> a[i];
		int sod = SOD(a[i]);
		sod_pos[sod].push_back({a[i], i});
	}	

	FOR (i,0,99) sort(sod_pos[i].begin(), sod_pos[i].end());

	while (Q--) {
		int id;
		cin >> id;
		int ans = -1;

		FOR (j,id+1,n) if (SOD(a[id]) > SOD(a[j]) && a[id] < a[j]) { ans = j; break; }

		cout << ans << "\n";
	}
}
