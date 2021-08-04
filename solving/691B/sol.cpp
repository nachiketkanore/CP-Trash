/*
Author: Nachiket Kanore
Created: Tuesday 17 November 2020 04:40:37 PM IST
(ツ) The eye sees only what the mind is prepared to comprehend.
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

bool test(char a, char b) {
	if (a>b) swap(a,b);
	if (a == 'A' && b == 'A') return true;
	if (a == 'b' && b == 'd') return true;
	if (a == 'H' && b == 'H') return true;
	if (a == 'I' && b == 'I') return true;
	if (a == 'M' && b == 'M') return true;
	if (a == 'O' && b == 'O') return true;
	if (a == 'o' && b == 'o') return true;
	if (a == 'p' && b == 'q') return true;
	if (a == 'T' && b == 'T') return true;
	if (a == 'U' && b == 'U') return true;
	if (a == 'V' && b == 'V') return true;
	if (a == 'v' && b == 'v') return true;
	if (a == 'W' && b == 'W') return true;
	if (a == 'w' && b == 'w') return true;
	if (a == 'X' && b == 'X') return true;
	if (a == 'x' && b == 'x') return true;
	if (a == 'Y' && b == 'Y') return true;
	return false;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s;
	cin >> s;
	bool ans = true;
	int lo = 0, hi = sz(s)-1;
	while (lo <= hi)
		ans &= test(s[lo++], s[hi--]);
	cout << (ans ? "TAK\n" : "NIE\n");
}
