/*
Author: Nachiket Kanore
Created: Tuesday 24 November 2020 08:04:42 PM IST
(ツ) I am of the opinion that my life belongs to the community, and as long as I live it is my privilege to do for it whatever I can.
*/
#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	FOR (i,1,n) a[i-1] = i;
	while (1) {
		shuffle(a.begin(), a.end(), rng);
		bool ok = true;
		FOR (i,1,n) ok &= a[i-1] != i;
		if (ok) {
			for (int x : a) cout << x << " ";
			cout << "\n";
			return;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;	while (T--) solve();
}
