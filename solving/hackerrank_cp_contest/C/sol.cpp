/*
Author: Nachiket Kanore
Created: Tuesday 08 December 2020 12:26:50 PM IST
(ツ) Be gentle first with yourself if you wish to be gentle with others.
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

const int N = 1e6 + 5, inf = 1e18;

int n, k, a[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int sum = 0;
	cin >> n >> k;
	FOR (i,1,n) {
		cin >> a[i];
		sum += a[i];
	}

	FOR (i,1,n) {
		if (sum - a[i] >= k) {
			cout << "0";
			sum -= a[i];
		} else {
			cout << "1";
		}
	}
}
