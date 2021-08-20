/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 21 August 2021 12:48:01 AM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int _ = 1e5 + 5;
int N, C[_], have[_];
vector<int> g[_], answer;

void dfs(int u, int par) {
	if (!have[C[u]]) answer.push_back(u);
	have[C[u]]++;
	for (int v: g[u]) if (v^par) dfs(v, u);
	have[C[u]]--;
}

int32_t main() {
	cin >> N;
	FOR (i,1,N) cin >> C[i];
	FOR (i,2,N) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	sort(ALL(answer));
	for (int x: answer) 
		cout << x << '\n';
}
