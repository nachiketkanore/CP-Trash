/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 24 February 2024 11:30:51 AM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int _ = 2e5;
bool prime[_];

vector<int> primes;
void sieve(int N) {

	memset(prime, true, sizeof prime);

	prime[0] = false, prime[1] = false;
	prime[2] = true;

	for (int x = 2; x * x <= N; x++) {
		if (prime[x] == true) {
			for (int i = x * x; i <= N; i += x)
				prime[i] = false;
		}
	}

	for (int x = 2; x < N; x++)
		if (prime[x])
			primes.push_back(x);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	sieve(_ - 1);
	int N;
	cin >> N;
	cout << (*(upper_bound(ALL(primes), N) - 1)) << ' ' << (*(lower_bound(ALL(primes), N)));

	return 0;
}
