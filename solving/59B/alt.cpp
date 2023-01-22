/*
Author: Nachiket Kanore
Created: Friday 20 November 2020 03:00:16 PM IST
(ツ) Time is the wisest counsellor of all.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n;
vector<int> a;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Finding max. odd sum of subsequence
	cin >> n;
	int sum = 0;
	a.resize(n);

	for (int& x : a) {
		cin >> x;
		sum += x;
	}
	if (sum & 1)
		cout << sum;
	else {
		int smallestEven = -1;
		for (int& x : a) {
			if (x % 2 == 0)
				if (smallestEven == -1 || smallestEven > x)
					smallestEven = x;
		}
		if (~smallestEven)
			cout << (sum - smallestEven);
		else
			cout << 0;
	}
}
