/*
Author: Nachiket Kanore
Created: Friday 11 December 2020 07:42:02 PM IST
(ツ) Creativity doesn't wait for that perfect moment. It fashions its own perfect moments out of ordinary ones.
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

const int N = 1e6+2, inf = 1e18;

int phi[N+1];
int pref[N];

void phi_1_to_n(int n) {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}


int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	phi_1_to_n(N);

	int n;	cin >> n;
	int T;	cin >> T;
	FOR (i,1,n) {
		int u;	cin >> u;
		pref[i] = (phi[u] == u-1) + pref[i-1];
	}

	while (T--) {
		int L, R;
		cin >> L >> R;
		cout << (pref[R]-pref[L-1]) << "\n";
	}
}
