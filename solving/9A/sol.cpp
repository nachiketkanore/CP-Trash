/*
Author: Nachiket Kanore
Created: Tuesday 08 December 2020 12:58:14 PM IST
(ツ) To dare is to lose ones footing momentarily. To not dare is to lose oneself.
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


int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	a = max(a, b);
	int N = 6-a+1;
	int D = 6;
	int G = __gcd(N,D);
	cout << N/G << "/" << D/G;
}
