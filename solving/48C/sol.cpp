/*
Author: Nachiket Kanore
Created: Wednesday 14 October 2020 02:47:10 PM IST
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;
const int mx = 1e5;

int n, a[N], cnt[N], ans[N];
vector<int> pos[N];
vector<int> permutations[N];
vector<pair<int, int>> vals;

bool chk(vector<int>& p) {
	int m = sz(p);
	sort(p.begin(), p.end());
	assert(m);
	FOR(i, 1, m) if (p[i - 1] != i) return false;
	return true;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		pos[a[i]].push_back(i);
		cnt[a[i]]++;
	}

	int tot = 0;
	FOR(i, 1, mx) if (cnt[i] > 0) {
		tot = max(tot, cnt[i]);
		vals.push_back({ cnt[i], i });
	}
	sort(vals.rbegin(), vals.rend());

	for (auto [f, val] : vals) {
		assert(f <= tot);

		int id = 1;
		while (id <= tot && f > 0) {
			permutations[id].push_back(val);
			--f;
			++id;
		}
	}

	FOR(i, 1, tot) {
		if (!chk(permutations[i])) {
			cout << -1;
			return 0;
		}
	}

	FOR(i, 1, tot) {
		vector<int>& ret = permutations[i];
		assert(sz(ret));
		for (int val : ret) {
			assert(sz(pos[val]));
			ans[pos[val].back()] = i;
			pos[val].pop_back();
		}
	}

	cout << tot << '\n';
	FOR(i, 1, n) {
		assert(ans[i]);
		cout << ans[i] << " \n"[i == n];
	}
}
