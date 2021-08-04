/*
Author: Nachiket Kanore
Created: Saturday 31 October 2020 11:46:33 AM IST
(ツ) The best way out is always through.
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

bool prime[N + 2];
int cnt[N + 2];

void pre() {
	FOR (i,2,N-1) prime[i] = true;
	FOR (i,2,N) if (prime[i]) for (int j = 2 * i; j <= N; j += i) prime[j] = false;
	FOR (i,1,N) if (prime[i] && prime[(i + 1) >> 1]) cnt[i] = 1;
	FOR (i,1,N) cnt[i] += cnt[i - 1];
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	pre();
	int Q;	cin >> Q;
	while (Q--) {
		int L, R;	cin >> L >> R;
		cout << (cnt[R] - cnt[L - 1]) << "\n";
	}
}
