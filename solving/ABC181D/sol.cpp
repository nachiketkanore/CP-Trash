/*
Author: Nachiket Kanore
Created: Thursday 19 November 2020 03:29:13 PM IST
(ツ) If you have made mistakes, there is always another chance for you. You may have a fresh start any moment you choose.
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

string s;
int have[10];

int ndigs(int n) {
	return (n == 0 ? 0 : 1 + ndigs(n/10));
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	for (char d : s) have[d-'0']++;

	int chkLen = 3;
	const int n = s.size();
	if (n >= 3) chkLen = 3;
	else if (n == 2) chkLen = 2;
	else if (n == 1) chkLen = 1;

	FOR (i,1,999) if (i % 8 == 0) if (ndigs(i) == chkLen) {

		int want[10] = {};
		int val = i;
		while (val) want[val%10]++, val /= 10;
		bool ok = true;
		FOR (d,1,9) ok &= have[d] >= want[d];
		if (ok) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}
