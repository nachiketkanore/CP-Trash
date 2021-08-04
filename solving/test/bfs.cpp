#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;

void prep() {
	const int M = 1e6;
	int *A = new int[M+1];
	for (int i = 0; i <= M; i++) i[A] = i;
}

int32_t main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> mat(n+1);
	vector<vector<int>> dist(n+1, vector<int> (m+1, inf));
	vector<vector<bool>> vis(n+1, vector<bool> (m+1, false));
	FOR (i,1,n) {
		cin >> mat[i];
		mat[i] = "$" + mat[i];
	}
	auto inside = [&](int i, int j) {
		return i >= 1 && i <= n && j >= 1 && j <= m;
	};
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	assert(mat[x1][y1]^'#' && mat[x2][y2]^'#');
	queue<pair<int,int>> Q;
	Q.push(make_pair(x1, y1));
	vis[x1][y1] = 1;
	dist[x1][y1] = 0;
	while (!Q.empty()) {
		auto [x, y] = Q.front();
		Q.pop();

		int i = x - 1, j = y;
		int skip = 0;
		while (inside(i, j) && skip < k && mat[i][j] == '.' && dist[i][j] >= dist[x][y] + 1) {
			if (vis[i][j]) {
				skip++;
				i--;	
				continue;
			} 
			vis[i][j] = 1;
			dist[i][j] = dist[x][y] + 1;
			Q.push(make_pair(i, j));
			i--;
			skip++;
		}
		i = x + 1, j = y;
		skip = 0;
		while (inside(i, j) && skip < k && mat[i][j] == '.' && dist[i][j] >= dist[x][y] + 1) {
			if (vis[i][j]) {
				skip++;
				i++;
				continue;
			} 
			vis[i][j] = 1;
			dist[i][j] = dist[x][y] + 1;
			Q.push(make_pair(i, j));
			i++;
			skip++;
		}
		i = x, j = y + 1;
		skip = 0;
		while (inside(i, j) && skip < k && mat[i][j] == '.' && dist[i][j] >= dist[x][y] + 1) {
			if (vis[i][j]) {
				skip++;
				j++;
				continue;
			} 
			vis[i][j] = 1;
			dist[i][j] = dist[x][y] + 1;
			Q.push(make_pair(i, j));
			j++;	
			skip++;
		}
		i = x, j = y - 1;
		skip = 0;
		while (inside(i, j) && skip < k && mat[i][j] == '.' && dist[i][j] >= dist[x][y] + 1) {
			if (vis[i][j]) {
				skip++;
				j--;
				continue;
			} 
			vis[i][j] = 1;
			dist[i][j] = dist[x][y] + 1;
			Q.push(make_pair(i, j));
			j--;
			skip++;
		}
	}
	int ans = dist[x2][y2];
	if (ans >= inf) ans = -1;
	cout << ans << '\n';
}

