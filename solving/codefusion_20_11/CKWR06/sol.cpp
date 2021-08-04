/*
Author: Nachiket Kanore
Created: Tuesday 01 December 2020 12:43:17 PM IST
(ツ) The things that one most wants to do are the things that are probably most worth doing.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <map>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;


//Use pair<int,int> to support multiset like features
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> container;

/*
1. Number of elements strictly greater than a[i]
int cnt = sz(curr) - (int)curr.order_of_key({a[i]+1,0});

2. Number of elements strictly less than a[i]
int cnt = (int)curr.order_of_key({a[i],i});

3. Use insert like this : curr.insert({a[id], id});

4. Finding the k -th smallest element in the set using * because 
    find_by_order returns an iterator 
    auto k-th_smallest_value =  *(o_set.find_by_order(k - 1))  
    It is (k - 1) since it uses zero indexes

5. Erasing : curr.erase({a[i], i});
*/

const int N = 2e5 + 5, inf = 1e18;
vector<int> g[N];
int tin[N], tout[N], timer;
int old[N];

void dfs(int u, int par) {
	tin[u] = ++timer;
	for (int v : g[u]) if (v^par) dfs(v, u);
	tout[u] = timer;
}

void solve() {
	int n, Q;	cin >> n >> Q;

	FOR (i,1,n) { g[i].clear(); tin[i] = tout[i] = 0; }

	FOR (i,1,n-1) {
		int u, v;	cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	map<int, container> f;
	// color => ids with that color
	// initially all 0s
	FOR (i,1,n) {
		f[0].insert(i);
		old[i] = 0;
	}

	timer = 0;
	dfs(1,1);

	while (Q--) {
		int tc, u, col;	cin >> tc >> u >> col;
		if (tc == 0) {
			if (!f.count(col)) cout << "0\n";
			else {
				int ans = (int)f[col].order_of_key(tout[u]+1) - (int)f[col].order_of_key(tin[u]);
				cout << ans << "\n";
			}
		} else {
			f[old[u]].erase(tin[u]);
			old[u] = col;
			f[old[u]].insert(tin[u]);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;	while (T--)	solve();
}
