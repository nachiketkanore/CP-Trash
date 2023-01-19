#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int sum = 0;
	int ans = -inf;
	int id = 0;
	FOR(i, 1, n) {
		int u;
		cin >> u;
		sum += u;
		if (sum > ans) {
			ans = sum;
			id = i;
		}
	}
	if (ans <= 0)
		cout << 0;
	else
		cout << id;
}