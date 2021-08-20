/**
 *    Author: Nachiket Kanore
 *    Created: Friday 20 August 2021 11:37:20 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <cassert>
#include <array>
#include <map>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int INF = 1e18;
int N, W;

int32_t main() {
	cin >> N >> W;
	map<int, vector<int>> vals;
	FOR (i,1,N) {
		int w, v;
		cin >> w >> v;
		vals[w].push_back(v);
	}
	vector<vector<int>> values;
	vector<int> weights;
	for (const auto &[k, v]: vals) {
		values.push_back(v);
		sort(ALL(values.back()));
		reverse(ALL(values.back()));
		weights.push_back(k);
	}
	function<int(int, int)> go = [&](int id, int rem) {
		if (rem < 0) return -INF;
		if (id == sz(weights)) return int(0);
		int ans = -INF;

		int take = 0;
		F0R (j,sz(values[id])+1) {
			cmax(ans, take + go(id + 1, rem - j * weights[id]));
			if (j < sz(values[id]))
				take += values[id][j];
		}

		return ans;
	};
	int ans = go(0, W);
	cout << ans << '\n';
}
