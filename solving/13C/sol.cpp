/*
Author: Nachiket Kanore
Created: Wednesday 14 October 2020 08:35:07 PM IST
(ツ) Work for something because it is good, not just because it stands a chance to succeed.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;	cin >> n;
	int tot = 0;
	FOR(i,1,n) FOR(j,1,n) {
		if (i & 1) {
			tot += 'C' == ".C"[j & 1];
		}
		else {
			tot += 'C' == "C."[j & 1];
		} 
	}
	cout << tot << "\n";

	FOR(i,1,n) FOR(j,1,n) {
		if (i & 1) cout << ".C"[j & 1];
		else cout << "C."[j & 1];
		if (j == n) cout << "\n";
	}

}
