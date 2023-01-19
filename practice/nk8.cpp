#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int tot = 0;
	for (int& x : a) {
		cin >> x;
		tot += x;
	}
	sort(a.begin(), a.end());

	int kept = 1;
	int curr_height = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] > curr_height) {
			curr_height++;
		}
		kept++;
	}
	assert(curr_height <= a.back());
	int add = a.back() - curr_height;
	kept += add;
	int ans = tot - kept;
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T = 1;
	while (T--)
		solve();
}

https :				   // web.evanchen.cc/FAQs/raqs.html
		https :		   // usamo.wordpress.com/2019/01/31/math-contest-platitudes-v3/
				https: // sendtoaryansh.gitbook.io/informatics-notes/preparing-for-contests