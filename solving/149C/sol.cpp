/*
Author: Nachiket Kanore
Created: Friday 30 October 2020 01:52:44 PM IST
(ツ) A good decision is based on knowledge and not on numbers.
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

pair<int,int> a[N];
int n;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	int mx = -inf;

	FOR (i,1,n) {
		cin >> a[i].first;
		a[i].second = i;
		mx = max(mx, a[i].first);
	}

	sort (a + 1, a + n + 1);

	vector<int> one, two;
	int s1 = 0, s2 = 0;

	int id = n;
	while (id >= 1) {
		if (id >= 2) {
			s1 += a[id].first;
			s2 += a[id - 1].first;
			one.push_back(a[id].second);
			two.push_back(a[id - 1].second);
			id -= 2;
		} else {
			s2 += a[id].first;
			two.push_back(a[id].second);
			id -= 1;
		}
	}

	assert(sz(one) + sz(two) == n);
	assert(abs(s2 - s1) <= mx);
	assert(abs(sz(one) - sz(two) <= 1));

	cout << sz(one) << "\n";	for (int x : one) cout << x << " ";	cout << "\n";
	cout << sz(two) << "\n";	for (int x : two) cout << x << " ";	cout << "\n";
}
