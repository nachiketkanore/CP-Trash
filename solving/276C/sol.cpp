/*
Author: Nachiket Kanore
Created: Monday 02 November 2020 09:46:57 AM IST
(ツ) Translation is the paradigm, the exemplar of all writing. It is translation that demonstrates most vividly the yearning for transformation that underlies every act involving speech, that supremely human gift.
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

const int N = 2e5 + 5, inf = 1e18;

int n, q, a[N], cnt[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;

	FOR (i,1,n) cin >> a[i];

	while (q--) {
		int L, R;
		cin >> L >> R;
		++R;
		cnt[L]++, cnt[R]--;
	}

	FOR (i,1,n) cnt[i] += cnt[i - 1];

	sort(a + 1, a + n + 1);
	sort(cnt + 1, cnt + n + 1);

	int ans = 0;
	FOR (i,1,n) ans += cnt[i] * a[i];

	cout << ans << "\n";
}
