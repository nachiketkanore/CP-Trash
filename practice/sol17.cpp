#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

int n;
array<int, 3> mat[N];
int suf[N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		FOR(i, 0, 2) FOR(j, 1, n) cin >> mat[j][i];

		sort(mat + 1, mat + n + 1, [&](array<int, 3> one, array<int, 3> two) { return one[0] * two[1] * two[2] < two[0] * one[1] * one[2]; });

		suf[n] = mat[n][1] * mat[n][2] % mod;
		for (int i = n - 1; i >= 1; i--) {
			suf[i] = suf[i + 1] + mat[i][1] * mat[i][2];
			suf[i] %= mod;
		}
		int ans = 0;
		FOR(i, 1, n - 1) {
			ans = (ans + mat[i][0] * suf[i + 1] % mod) % mod;
		}
		FOR(i, 0, n + 1) {
			suf[i] = 0;
		}
		cout << ans << '\n';
	}
}