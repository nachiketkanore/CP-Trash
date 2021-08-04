/*
Author: Nachiket Kanore
Created: Sunday 22 November 2020 05:25:17 PM IST
(ツ) A life spent making mistakes is not only more honourable, but more useful than a life spent doing nothing.
*/
#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2000 + 5, inf = 1e18;

int n, m;
char mat[N][N];
int best1[26], best2[26];
using pii = pair<int,int>;
std::vector<pii> g[N*N];

int node(int i, int j) {
	return (i-1) * m + j;
}

void add(int u, int v) {
	cerr << u << " " << v << "\n";
	g[u].push_back({v, 1});
}

bool inside(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dijkstra(int s, vector<int> & d) {

    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : g[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	int A = -1, B = -1;

	FOR (i,1,n) FOR (j,1,m) cin >> mat[i][j];
	FOR (i,1,n) FOR (j,1,m) {
		int u = node(i, j);
		if (mat[i][j] == 'S') A = u;
		if (mat[i][j] == 'G') B = u;
		if (mat[i][j] == '#') continue;

		FOR (k,0,3) {
			int ni = i + dx[k];
			int nj = j + dy[k];
			if (!inside(ni, nj)) continue;
			if (mat[ni][nj] == '#') continue;
			int v = node(ni, nj);
			add(u, v);
		}
	}

	vector<int> one(n*m + 5, inf), two(n*m + 5, inf);

	dijkstra(A, one);
	dijkstra(B, two);

	for (int i = 0; i < 26; i++) best1[i] = best2[i] = inf;

	FOR (i,1,n) FOR (j,1,m) {
		char ch = mat[i][j];
		if (ch >= 'a' && ch <= 'z') {
			best1[ch - 'a'] = min(best1[ch - 'a'], two[node(i, j)]);
			best2[ch - 'a'] = min(best2[ch - 'a'], one[node(i, j)]);
		}
	}

	int ans = inf;
	ans = min(ans, one[B]);
	ans = min(ans, two[A]);

	FOR (i,1,n) FOR (j,1,m) if (mat[i][j] != '#') {
		int mid = node(i, j);
		int get = one[mid] + two[mid];
		ans = min(ans, get);

		char ch = mat[i][j];
		if (ch >= 'a' && ch <= 'z') {
			
		}
	}


	if (ans >= inf)
		ans = -1;
	cout << ans << "\n";
}
