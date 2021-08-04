/*
Author: NK
Created: Sunday 25 October 2020 04:31:07 PM IST
(ツ) Better to have loved and lost, than to have never loved at all.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <map>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> startRow(n);
	vector<vector<int>> rows(n), cols(m);

	FOR(i,1,n) {
		vector<int> row(m);
		for (int &x : row) cin >> x;
		rows[i - 1] = row;
	}

	FOR(i,1,m) {
		vector<int> col(n);
		for (int &x : col) cin >> x;
		cols[i - 1] = col;
	}

	bool done = false;
	
	FOR(i,0,n-1) FOR(j,0,m-1) {
		if (done) break;
		if (rows[i][0] == cols[j][0]) {

			done = true;
			FOR(rowId,1,n) {
				startRow[rowId - 1] = cols[j][rowId - 1];
			}
		}
	}

	map<int,vector<int>> get;

	FOR(i,1,n) get[rows[i - 1][0]] = rows[i - 1];

	FOR(i,1,n) {
		vector<int> pr = get[startRow[i - 1]];
		assert(sz(pr) == m);
		for (int x : pr) 
			cout << x << " ";
		cout << "\n";
	}

}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) solve();
}
