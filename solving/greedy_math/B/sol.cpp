/*
Author: Nachiket Kanore
Created: Sunday 25 October 2020 07:47:24 PM IST
(ツ) No man is free who is not master of himself.
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
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	while (T--)	{
		// a(n) = 2*(Sum_{i=1..floor(sqrt(n))} floor(n/i)) - floor(sqrt(n))^2
		int n;
		cin >> n;

		int sum = 0;
		int root = sqrt(n);

		FOR(i,1,sqrt(n)) sum += n / i;

		sum <<= 1;
		sum -= root * root;

		int tot = n * n;
		int good = sum;

		int g = __gcd(good, tot);
		good /= g, tot /= g;	
		cout << good << "/" << tot << "\n";
	}

}
