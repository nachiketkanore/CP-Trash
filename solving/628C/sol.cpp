/*
Author: Nachiket Kanore
Created: Tuesday 27 October 2020 06:52:00 PM IST
(ツ) Sometimes our fate resembles a fruit tree in winter. Who would think that those branches would turn green again and blossom, but we hope it, we know it.
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

int n, k;
string s;
vector<pair<int,int>> dist[30];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> s;

	vector<pair<int,int>> vals;
	vector<int> ans(n, -1);

	FOR (i,1,n) {
		vals.emplace_back(s[i - 1] - 'a', i - 1);
	}

	sort(vals.begin(), vals.end());

	FOR (i,0,25) {
		FOR (j,0,25) {
			dist[i].push_back({abs(j - i), j});
		}
		sort(dist[i].rbegin(), dist[i].rend());
	}
		
	for (auto &[val, id] : vals) {
		int best = -1, nxt = -1;
		for (auto &[d, which] : dist[val]) {
			if (k >= d) {
				best = d;
				nxt = which;
				break;
			}
		}

		assert(~best && ~nxt);

		k -= best;
		assert (k >= 0);
		ans[id] = nxt;
	}

	if (k > 0) cout << "-1\n";
	else {
		for (int x : ans) {
			assert(~x);
			cout << (char) (x + 'a');
		}
		cout << "\n";
	}
}
