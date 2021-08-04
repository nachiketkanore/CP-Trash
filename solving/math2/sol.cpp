/*
Author: Nachiket Kanore
Created: Friday 11 December 2020 06:09:00 PM IST
(ツ) There surely is in human nature an inherent propensity to extract all the good out of all the evil.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e6 + 5, inf = 1e18;

int prime[N+1];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	fill(prime+2, prime+N, 1);
	FOR (i,2,N) if (prime[i]) for (int j = 2*i; j <= N; j += i) prime[j] = 0;
	FOR (i,1,N) prime[i] += prime[i-1];

	int T;	cin >> T;
	while (T--) {
		int L, R;	cin >> L >> R;
		int primes = prime[R] - prime[L-1];
		cout << (R-L+1) - primes << "\n";
	}
}
