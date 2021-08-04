/*
Author: Nachiket Kanore
Created: Sunday 25 October 2020 07:32:18 PM IST
(ツ) Always tell the truth. That way, you don't have to remember what you said.
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

const int N = 1e6 + 5, inf = 1e18;

int L, R, k;
int prime[N + 2];

void pre() {
	fill(prime + 2, prime + N, 1);
	FOR(i,2,N) if (prime[i]) {
		for (int j = 2 * i; j <= N; j += i) 
			prime[j] = 0;
	}

	FOR(i,1,N) prime[i] += prime[i - 1];
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	pre();

	cin >> L >> R >> k;

	auto ok = [&](int len) {
		bool good = true;
		FOR(i,L,R) if (i + len - 1 <= R) {
			good &= (prime[i + len - 1] - prime[i - 1]) >= k;
		}
		return good;
	};

	int ans = -1;
	int lo = 1, hi = R - L + 1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (ok(mid)) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << ans;
}
