/*
Author: Nachiket Kanore
Created: Wednesday 18 November 2020 01:32:43 PM IST
(ツ) Be kind whenever possible. It is always possible.
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
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1000 + 5, inf = 1e18;

int one[N][N], two[N][N];
int n, m;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	bool which = 1;
	int id = 1;
	for (int row = n; row; row--) {
		if (which) {
			for (int col = m; col; col--)
				one[row][col] = id++;
			which ^= 1;
		}
		else {
			for (int col = 1; col <= m; col++)
				one[row][col] = id++;
			which ^= 1;
		}
	}

	id = 1;
	which = 1;

	for (int col = 1; col <= m; col++) {
		if (which) {
			for (int row = 1; row <= n; row++)
				two[row][col] = id++;
			which ^= 1;
		}
		else {
			for (int row = n; row; row--)
				two[row][col] = id++;
			which ^= 1;
		}
	}

	int ans = 0;
	vector<int> ret;
	FOR (i,1,n) FOR (j,1,m) if (one[i][j] == two[i][j]) {
		++ans;
		ret.push_back(one[i][j]);
	}
	cout << ans << "\n";
	sort(ret.begin(), ret.end());
	for (int x : ret) cout << x << " ";
		cout << "\n";
}
