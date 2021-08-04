/*
Author: Nachiket Kanore
Created: Monday 07 December 2020 07:48:29 PM IST
(ツ) You got to be careful if you don't know where you're going, because you might not get there.
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

const int N = 2e5 + 5, inf = 1e18;

int n, l[N], r[N];
int P;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> P;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
	}

	using ld = long double;

	ld ans = 0;

	for (int i = 0; i < n; i++) {
		int j = (i+1) % n;

		ld onlyI = r[i]/P - (l[i]-1)/P;
		onlyI /= ((ld)r[i] - l[i] + 1);
		
		ld onlyJ = r[j]/P - (l[j]-1)/P;
		onlyJ /= ((ld)r[j] - l[j] + 1);
		
		ld bothIJ = onlyJ * onlyI;
		ld IorJ = onlyI + onlyJ - bothIJ;
		
		ans += 2000.0 * IorJ;
	}

	printf("%0.10Lf\n", ans);
}
