/*
Author: Nachiket Kanore
Created: Thursday 15 October 2020 03:40:56 PM IST
(ツ) Enjoy the little things, for one day you may look back and realize they were the big things.
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

const int N = 1e3 + 5;
const double inf = 1e15;

class item {
	public:
	double cost;
	int type;
	int id;
} a[N];

int n, k;
vector<int> carts[N];
bool vis[2][N][N];
double dp[2][N][N];

double go(int id, int which, bool bonus) {
	if (id > n)
		return inf;
	if (id == n) {
		if (which != k)
			return inf;
		if (bonus || a[id].type == 1)
			return a[id].cost / 2.0;
		else
			return a[id].cost;
	}

	if (vis[bonus][id][which])
		return dp[bonus][id][which];

	vis[bonus][id][which] = true;

	double ans = inf;

	// end here
	bool good = bonus || (a[id].type == 1);
	double get = a[id].cost;
	if (good)
		get = get / 2.0;
	get = get + go(id + 1, which + 1, 0);
	ans = min(ans, get);

	// continue
	get = a[id].cost + go(id + 1, which, bonus || (a[id].type == 1));
	ans = min(ans, get);

	dp[bonus][id][which] = ans;
	return ans;
}

void trace(int id, int which, bool bonus) {
	if (id > n) {
		return;
	}

	double ans = go(id, which, bonus);

	carts[which].push_back(a[id].id);

	// end here
	bool good = bonus || (a[id].type == 1);
	double get = a[id].cost;
	if (good)
		get = get / 2.0;
	get = get + go(id + 1, which + 1, 0);
	if (get == ans) {
		return trace(id + 1, which + 1, 0);
	}

	// continue
	get = a[id].cost + go(id + 1, which, bonus || (a[id].type == 1));
	if (get == ans) {
		return trace(id + 1, which, bonus || (a[id].type == 1));
	}
}

int32_t main() {

	cin >> n >> k;

	FOR(i, 1, n) {
		int cost, type;
		cin >> cost >> type;
		a[i].cost = (double)cost;
		a[i].type = type;
		a[i].id = i;
	}

	sort(a + 1, a + n + 1, [&](item& one, item& two) { return one.cost > two.cost; });

	double ans = go(1, 1, 0);
	printf("%.1f\n", ans);

	trace(1, 1, 0);

	vector<vector<int>> ret;

	FOR(i, 1, k) if (sz(carts[i]) > 0) {
		ret.push_back(carts[i]);
	}

	int totalCount = 0;
	assert(sz(ret) == k);
	for (auto c : ret) {
		assert(sz(c) > 0);
		totalCount += sz(c);
		cout << sz(c);
		for (int id : c)
			cout << ' ' << id;
		cout << '\n';
	}
	assert(totalCount == n);
}
