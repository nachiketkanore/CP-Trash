/*
Author: Nachiket Kanore
Created: Saturday 17 October 2020 11:13:46 PM IST
(ツ) We are Divine enough to ask and we are important enough to receive.
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

const int N = 2e5 + 5, inf = 1e18;
#define get GET

int n, a[N];
pair<int, int> get[10];
int ret[10];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	FOR(i, 1, 5) {
		int val;
		cin >> val;
		get[i] = { val, i };
	}
	sort(get + 1, get + 5 + 1);

	int curr = 0;
	FOR(i, 1, n) {
		curr += a[i];
		while (curr >= get[1].first) {
			int which = -1;
			int price = -1;
			FOR(j, 1, 5) {
				if (get[j].first <= curr) {
					which = get[j].second;
					price = get[j].first;
				}
			}
			assert(~which && ~price);
			assert(price <= curr);
			int cnt = curr / price;
			ret[which] += cnt;
			curr -= cnt * price;
		}
	}

	FOR(i, 1, 5) cout << ret[i] << " \n"[i == 5];
	cout << curr;
}
