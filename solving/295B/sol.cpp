/*
Author: Nachiket Kanore
Created: Monday 09 November 2020 01:06:28 PM IST
(ツ) There is not one big cosmic meaning for all, there is only the meaning we each give to our life.
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

const int N = 505, inf = 1e18;

int n, dist[N][N], rem[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	FOR (i,1,n) FOR (j,1,n) dist[i][j] = inf;
	FOR (i,1,n) FOR (j,1,n) cin >> dist[i][j];

	FOR (i,1,n) cin >> rem[i];
	reverse(rem + 1, rem + n + 1);

	vector<int> answers;

	FOR (i,1,n) {
		int add_node = rem[i];

		// update distances
		FOR (a,1,n) FOR (b,1,n) {
			// add_node is the in between node
			// from floyd warshall
			dist[a][b] = min(dist[a][b], dist[a][add_node] + dist[add_node][b]);
		}

		// get sum over all pairs
		int sum = 0;
		FOR (a,1,n) FOR (b,1,n) sum += dist[a][b];
		answers.push_back(sum);
	}

	while (sz(answers)) {
		cout << answers.back() << " ";
		answers.pop_back();
	}
}
