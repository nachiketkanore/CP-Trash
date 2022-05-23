/**
 *    Author: Nachiket Kanore
 *    Created: Monday 23 May 2022 12:02:20 PM IST
 **/
#include "bits/stdc++.h"

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int MAX = 1e6;
bool prime[MAX + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	/*
	   p.q^3 <= N
	   q <= MAX
	   p <= N / q^3
	*/
	vector<int> primes;

	fill(prime + 2, prime + MAX + 1, true);
	FOR(p, 2, MAX) if (prime[p]) {
		for (int m = 2 * p; m <= MAX; m += p)
			prime[m] = false;
		primes.push_back(p);
	}

	int ans = 0;

	for (int q : primes) {
		if (q * q * q > N)
			break;
		int p = N / (q * q * q);
		if (p < 2)
			continue;
		p = min(p, q);
		if (p == q)
			--p;
		int id = upper_bound(ALL(primes), p) - primes.begin();
		ans += id;
	}

	cout << ans;

	return 0;
}
