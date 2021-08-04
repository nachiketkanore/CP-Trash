/*
Author: Nachiket Kanore
Created: Sunday 25 October 2020 12:11:48 PM IST
(ツ) Watch the little things; a small leak will sink a great ship.
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
	
	int n, k, p;
	cin >> n >> k >> p;

	int even = p, odd = k - p;

	vector<int> E, O;

	FOR(i,1,n) {
		int u;
		cin >> u;
		if (u & 1) O.push_back(u);
		else E.push_back(u);
	}

	vector<vector<int>> evenAns, oddAns;

	int evenDone = 0;

	while (evenDone < even && sz(E)) {
		evenAns.push_back({E.back()});
		E.pop_back();
		evenDone++;
	}

	while (evenDone < even && sz(O) >= 2) {
		evenDone += 2;
		vector<int> put = {O.back(), O[sz(O) - 2]};
		evenAns.push_back(put);
		O.pop_back();
		O.pop_back();
	}

	for (auto it : evenAns) {
		cout << sz(it) << " : ";
		for (int x : it) cout << x << " ";
			cout << '\n';
	}
}
