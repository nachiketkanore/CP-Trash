/*
Author: Nachiket Kanore
Created: Tuesday 17 November 2020 12:27:01 PM IST
(ツ) The truth of the matter is that you always know the right thing to do. The hard part is doing it.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e6 + 5, inf = 1e18;

bool prime[N + 2];
vector<int> primes;

void solve() {
	int n;
	cin >> n;
	map<int, int> mp;
	vector<int> b(n);
	for (int& x : b) {
		cin >> x;
		mp[x] = 1;
	}
	int id = 0;
	for (auto& it : mp) {
		it.second = primes[id++];
	}
	for (int& x : b) {
		cout << mp[x] << " ";
	}
	cout << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(prime + 2, prime + N, true);
	FOR(i, 2, N) if (prime[i]) {
		primes.push_back(i);
		for (int j = 2 * i; j <= N; j += i)
			prime[j] = false;
	}

	int T;
	cin >> T;
	while (T--)
		solve();
}
