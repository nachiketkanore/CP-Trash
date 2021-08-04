/*
Author: Nachiket Kanore
Created: Thursday 19 November 2020 07:09:16 PM IST
(ツ) In seed time learn, in harvest teach, in winter enjoy.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	int a = 0, b = 0;

	while (n--) {
		char ch;
		cin >> ch;
		if (ch == '+') {
			int x, y;
			cin >> x >> y;
			if (x > y) swap(x, y);
			a = max(a, x);
			b = max(b, y);
		}
		else {
			int h, w;
			cin >> h >> w;
			if (h > w) swap(h, w);
			cout << (a <= h && b <= w ? "YES\n" : "NO\n");
		}
	}
}
