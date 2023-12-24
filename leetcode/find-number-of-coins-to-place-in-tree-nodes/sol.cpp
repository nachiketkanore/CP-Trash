/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 24 December 2023 08:40:13 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

class Solution {
	vector<vector<int>> adj;
	vector<multiset<int>> subtree;
	vector<int> cost;
	vector<long long> ans;

	void dfs(int u = 0, int par = 0) {

		subtree[u].insert(cost[u]);

		for (int v : adj[u]) {
			if (v ^ par) {
				dfs(v, u);
				if (subtree[v].size() > subtree[u].size()) {
					// ALTERNATE: swap(subtree[u], subtree[v]);
					subtree[u].swap(subtree[v]);
				}
				for (int add : subtree[v]) {
					subtree[u].insert(add);
				}
			}
		}

		// store only 3 min and 3 max elements in subtree aggregation
		{
			vector<int> temp(subtree[u].begin(), subtree[u].end());
			subtree[u].clear();
			int check = 3;
			while (!temp.empty() && check--) {
				subtree[u].insert(temp.back());
				temp.pop_back();
			}
			check = 3;
			reverse(temp.begin(), temp.end());
			while (!temp.empty() && check--) {
				subtree[u].insert(temp.back());
				temp.pop_back();
			}
		}

		if (subtree[u].size() < 3) {
			ans[u] = 1;
		} else {
			multiset<int> usub = subtree[u];
			vector<int> vals;
			int take = 3;
			while (!usub.empty() && take--) {
				int last = *usub.rbegin();
				vals.push_back(last);
				usub.erase(usub.find(last));
			}
			take = 3;
			while (!usub.empty() && take--) {
				int first = *usub.begin();
				vals.push_back(first);
				usub.erase(usub.find(first));
			}
			long long prod = 0;
			const int M = vals.size();
			for (int i = 0; i < M; i++)
				for (int j = i + 1; j < M; j++)
					for (int k = j + 1; k < M; k++)
						prod = max(prod, 1ll * vals[i] * vals[j] * vals[k]);
			ans[u] = prod;
		}
	}

	public:
	vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
		int n = 0;
		for (auto e : edges) {
			n = max(n, e[0] + 1);
			n = max(n, e[1] + 1);
		}

		adj.resize(n);
		ans.resize(n, -1ll);
		subtree.resize(n);
		this->cost = cost;

		for (auto e : edges) {
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}

		dfs();

		return ans;
	}
};

int32_t main() {
}
