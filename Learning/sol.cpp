/**
 *	Author: Nachiket Kanore
 *	Created: Thursday 29 July 2021 04:55:25 PM IST
 **/

// For heavy recursions
// #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2")

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Use pair<int,int> to support multiset like features
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

const int N = 1e5 + 5;
oset curr[N];

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

int n, val[N], ans[N];
std::vector<int32_t> g[N];

void merge(int u, int v) {
	if (sz(curr[u]) < sz(curr[v]))
		swap(curr[u], curr[v]);
	for (int x : curr[v]) {
		curr[u].insert(x);
	}
	curr[v].clear();
}

void dfs(int u, int par) {
	curr[u].insert(val[u]);
	for (int v : g[u]) {
		if (v ^ par) {
			dfs(v, u);
			merge(u, v);
		}
	}
	int lo = 0, hi = 1e9;
	int my_ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int cnt_less = (int)curr[u].order_of_key(mid);
		if (cnt_less == mid)
			my_ans = mid, lo = mid + 1;
		else
			hi = mid - 1;
	}
	ans[u] = my_ans;
}

int32_t main() {
	cin >> n;
	FOR(i, 2, n) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	FOR(i, 1, n) cin >> val[i];
	dfs(1, 1);
	FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
}
