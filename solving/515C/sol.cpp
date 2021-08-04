/*
Author: Nachiket Kanore
Created: Friday 16 October 2020 03:59:42 PM IST
(ツ) Lots of people want to ride with you in the limo, but what you want is someone who will take the bus with you when the limo breaks down.
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
#include <map>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n;
string s;
vector<int> facts[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;

	map<int,int> f;
	for (char ch : s) if (ch != '0' and ch != '1') {
		int val = ch - '0';
		FOR(tt,2,val) {
			vector<int> pfs;
			int x = tt;
			for (int d = 2; d * d <= x; d++) if (x % d == 0) {
				while (x % d == 0) {
					pfs.push_back(d);
					x /= d;
				}
			}
			if (x > 1) pfs.push_back(x);
			for (int v : pfs) f[v]++;
		}
	}

	vector<pair<int,int>> vals;
	for (auto it : f) {
		vals.push_back({it.second, it.first});
	}

	sort(vals.rbegin(), vals.rend());
	for (auto it : vals) cout << it.first << ' ' << it.second << '\n';
	int max_cnt = vals.front().first;

	for (auto [freq, val] : vals) {
		int id = 1;
		while (freq > 0) {
			facts[id].push_back(val);
			id++;
			freq--;
		}
	}

	vector<int> ret;

	FOR(i,1,max_cnt) if (sz(facts[i])) ret.push_back(facts[i].back());
	sort(ret.rbegin(), ret.rend());

	for (int x : ret) cout << x;
}

#warning wrong see sol.py