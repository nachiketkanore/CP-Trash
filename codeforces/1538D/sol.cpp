/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 27 January 2024 08:07:30 PM IST
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

const int MX = 32000;
bool prime[MX + 1];
vector<int> primes;

void solve() {
	int a, b, k;
	cin >> a >> b >> k;
	auto get_alphas_sum = [](int val) -> int {
		int sum = 0;
		for (int p : primes) {
			while (val % p == 0) {
				val /= p;
				++sum;
			}
		}
		if (val > 1)
			++sum;
		return sum;
	};
	if (k == 1) {
		if (b % a == 0 && b / a > 1)
			cout << "YES\n";
		else if (a % b == 0 && a / b > 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	} else if (k <= get_alphas_sum(a) + get_alphas_sum(b)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(prime + 2, prime + MX + 1, true);
	FOR(p, 2, MX) if (prime[p]) {
		primes.push_back(p);
		for (int m = 2 * p; m <= MX; m += p)
			prime[m] = false;
	}

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
