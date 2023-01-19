/*
Author: Nachiket Kanore
Created: Wednesday 02 December 2020 03:40:02 PM IST
(ツ) We are all inclined to judge ourselves by our ideals; others, by their acts.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("collectingofficer.in","r",stdin);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = -1;
		for (int i = 0; i < n; i++) {
			char want = 'A';
			int where = -1;
			for (int j = i; j < n; j++) {
				if (want <= 'Z' && s[j] == want) {
					want++;
					if (want > 'Z') {
						where = j;
						break;
					}
				}
			}
			if (~where) {
				assert(want > 'Z');
				if (ans == -1 || ans > (where - i + 1))
					ans = where - i + 1;
			}
		}
		assert(~ans);
		cout << ans << "\n";
	}
}
