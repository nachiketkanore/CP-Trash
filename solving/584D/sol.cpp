/*
Author: Nachiket Kanore
Created: Saturday 17 October 2020 11:36:00 PM IST
(ツ) We are either progressing or retrograding all the while. There is no such thing as remaining stationary in this life.
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

bool checkPrime(int n){
	if(n < 2)
		return false;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;	
	cin >> n;

	FOR(i,3,3) for (int j = 0; j <= n; j++) if (j == 0 || j % 2 == 1 || j == 2) {
		int k = n - i - j;
		if (k < 0) continue;
		bool one = checkPrime(i), two = checkPrime(j), three = checkPrime(k);
		if (i == n && one) {
			cout << "1\n" << i << '\n';
			return 0;
		}
		if (j == n && two) {
			cout << "1\n" << j << '\n';
			return 0;
		}
		if (k == n && three) {
			cout << "1\n" << k << '\n';
			return 0;
		}
		if (i + j == n && one && two) {
			cout << "2\n" << i << " " << j << '\n';
			return 0;
		}
		if (i + k == n && one && three) {
			cout << "2\n" << i << " " << k << '\n';
			return 0;
		}
		if (j + k == n && two && three) {
			cout << "2\n" << j << " " << k << '\n';
			return 0;
		}
		if (i + j + k == n && one && two && three) {
			cout << "3\n" << i << " " << j << " " << k;
			return 0;
		}
	}
	assert(0);
}
