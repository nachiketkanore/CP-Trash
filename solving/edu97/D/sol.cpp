/*
Author: Nachiket Kanore
Created: Tuesday 27 October 2020 08:34:12 PM IST
(ツ) If you spend too much time thinking about a thing, you'll never get it done.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <queue>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

const int N = 2e5 + 5, inf = 1e18;

int a[N];
vector<int> g[N];
int mx;

void dfs(int u, int h) {
	mx = max(mx, h);
	for (int v : g[u]) dfs(v, h + 1);
}

void solve() {
	int n;
	cin >> n;
	FOR (i,1,n) cin >> a[i], g[i].clear();

	queue<int> pars;
	assert(a[1] == 1);
	pars.push(1);

	for (int i = 2; i <= n; ) {
		int j = i;
		while (1) {
			if (j == n) break;
			if (a[j] > a[j + 1]) break;
			if (a[j] < a[j + 1]) j++;
		}

		vector<int> childs;
		FOR(k,i,j) childs.push_back(a[k]);

		int par = pars.front();
		pars.pop();

		see(par, childs);

		for (int child : childs) g[par].push_back(child);
		for (int child : childs) pars.push(child);

		i = j + 1;
	}
	see("\n");

	mx = 0;
	dfs(1, 0);
	cout << mx << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;
	while (T--) solve();
}
