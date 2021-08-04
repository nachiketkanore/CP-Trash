/*
Author: Nachiket Kanore
Created: Friday 16 October 2020 10:38:28 AM IST
(ツ) Love at first sight is easy to understand; its when two people have been looking at each other for a lifetime that it becomes a miracle.
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

const int N = 1e6 + 5, inf = 1e18;

int spf[N + 5];

void pre() {
	FOR(i,2,N) spf[i] = i;
	for (int i = 2; i <= N; i++) if (i == spf[i]) {
		for (int j = 2 * i; j <= N; j += i) {
			if (spf[j] == j)
				spf[j] = i;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	pre();

	int n;	cin >> n;

	while (n > 1) {
		cout << n << ' ';
		n /= spf[n];
	}
	cout << "1\n";
}
