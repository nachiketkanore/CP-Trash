/*
Author: Nachiket Kanore
Created: Friday 11 December 2020 07:24:14 PM IST
(ツ) There is no retirement for an artist, it's your way of living so there is no end to it.
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

const int N = 1e6+1, inf = 1e18;

int divs[N+1];
int solve[5];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	FOR (i,1,N) for (int j = i; j <= N; j += i) divs[j]++;

	int n;
	cin >> n;

	FOR (i,1,n) {
		int u;	cin >> u;
		if (divs[u] <= 4) 
			solve[divs[u]]++;
	}

	cout << solve[2]+solve[3]-solve[4]-solve[1] << "\n";
}
