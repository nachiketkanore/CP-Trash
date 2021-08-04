/*
Author: Nachiket Kanore
Created: Friday 30 October 2020 06:59:35 PM IST
(ツ) Argue for your limitations, and sure enough they're yours.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <queue>
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

	deque<int> Q;
	FOR (i,1,n) Q.push_back(i);

	bool which = true;

	while (!Q.empty()) {
		if (which) {
			cout << Q.front() << " ";
			Q.pop_front();
		} else {
			cout << Q.back() << " ";
			Q.pop_back();
		}
		which ^= 1;
	}
}
