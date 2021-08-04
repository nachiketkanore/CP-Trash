#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 3e5 + 5, inf = 1e18;

int n, h[N];
vector<int> g[N];
vector<int> dp;

int go(int from) {
	if (from == n) return 0;

	int &ans = dp[from];
	if (~ans) 
		return ans;
	
	ans = inf;
	
	for (int to : g[from]) {
		assert(from < to);
		int get = 1 + go(to);
		ans = min(ans, get);
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	FOR(i,1,n)	cin >> h[i];	

	stack<int> stk;

	for (int i = n; i >= 1; i--) {	// next >=
		while (!stk.empty() && h[stk.top()] < h[i])
			stk.pop();
		if (stk.size())
			g[i].push_back(stk.top());
		stk.push(i);
	}

	while (!stk.empty()) stk.pop();

	for (int i = n; i >= 1; i--) {	// next <= 
		while (!stk.empty() && h[stk.top()] > h[i])
			stk.pop();
		if (stk.size())
			g[i].push_back(stk.top());
		stk.push(i);
	}

	while (!stk.empty()) stk.pop();

	for (int i = 1; i <= n; i++) {	// prev >=
		while (!stk.empty() && h[stk.top()] < h[i])
			stk.pop();
		if (stk.size())
			g[stk.top()].push_back(i);
		stk.push(i);
	}

	while (!stk.empty()) stk.pop();

	for (int i = 1; i <= n; i++) {	// prev <= 
		while (!stk.empty() && h[stk.top()] > h[i])
			stk.pop();
		if (stk.size())
			g[stk.top()].push_back(i);
		stk.push(i);
	}

	dp.resize(n + 1, -1);
	cout << go(1);
}