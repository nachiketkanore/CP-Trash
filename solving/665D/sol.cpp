/*
Author: Nachiket Kanore
Created: Wednesday 14 October 2020 07:55:42 PM IST
(ツ) The world is but a canvas to the imagination.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e6 + 5, inf = 1e18;

bool prime[N + 5];
int n, a[N], cnt[N];

void pre() {
	fill(prime + 2, prime + N + 1, true);
	FOR(i, 2, N) if (prime[i]) for (int j = 2 * i; j <= N; j += i) prime[j] = false;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	pre();

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	int ans = cnt[1];
	vector<int> ret;
	FOR(i, 1, ans) {
		ret.push_back(1);
	}

	FOR(i, 2, N) if (prime[i + 1] && cnt[i]) {
		ans = ans + 1;
		ret.push_back(i);
		break;
	}

	FOR(i, 1, n) if (sz(ret) == 0) {
		ret = { a[i] };
		ans = 1;
	}

	FOR(i, 1, n) FOR(j, i + 1, n) {
		assert(sz(ret) == ans);
		if (prime[a[i] + a[j]] && sz(ret) < 2) {
			ret = { a[i], a[j] };
			ans = 2;
		}
	}

	assert(sz(ret) == ans);
	cout << ans << '\n';
	for (int x : ret)
		cout << x << ' ';
}
