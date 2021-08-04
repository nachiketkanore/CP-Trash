/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 24 July 2021 04:02:34 PM IST
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
#include <queue>

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int N = 1010;
int n;
char mat[N][N];
bool vis[N][N];

int32_t main() {
	cin >> n;
	FOR (i,1,n) FOR (j,1,n) cin >> mat[i][j];
	cout << n * n << '\n';
	FOR (i,1,n) {
		if (i&1) FOR (j,1,n) cout << i << ' ' << j << '\n';
		else for (int j = n; j; j--) cout << i << ' ' << j << '\n';
	}
}
