#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

char mat[110][110];
int n, m, ans;

bool inside(int i, int j) {
	return i >= 1 && i <= n && j <= m && j >= 1;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	FOR(i, 1, n) FOR(j, 1, m) {
		cin >> mat[i][j];
	}

	FOR(i, 1, n) FOR(j, 1, m) if (mat[i][j] == '.') {
		if (inside(i + 1, j) && mat[i + 1][j] == '.')
			++ans;
		if (inside(i, j + 1) && mat[i][j + 1] == '.')
			++ans;
		// if (inside(i - 1, j) && mat[i - 1][j] == '.') ++ans;
		// if (inside(i, j - 1) && mat[i][j - 1] == '.') ++ans;
	}
	cout << ans;
}