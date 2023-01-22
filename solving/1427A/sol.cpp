/*
Author: Nachiket Kanore
Created: Monday 26 October 2020 04:09:02 PM IST
(ツ) No day in which you learn something is a complete loss.
*/
#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n, sum = 0;
		vector<int> a;

		cin >> n;
		FOR(i, 1, n) {
			int u;
			cin >> u;
			a.push_back(u);
		}

		bool done = false;

		for (int rep = 0; !done && rep < 2000; rep++) {
			shuffle(a.begin(), a.end(), rng);

			bool ok = true;
			sum = 0;
			for (int x : a) {
				sum += x;
				ok &= sum != 0;
			}
			done |= ok;
		}

		if (done) {
			cout << "YES\n";
			for (int x : a)
				cout << x << " ";
			cout << "\n";
		} else {
			cout << "NO\n";
		}
	}
}
