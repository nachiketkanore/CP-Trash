#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;	cin >> T;
	FOR(TT,1,T) {
		int n, x;
		cin >> n >> x;
		vector<pair<int,int>> order;
		FOR(i,1,n) {
			int u;	cin >> u;
			order.push_back({(u + x - 1) / x, i});
		}
		sort(order.begin(), order.end());
		cout << "Case #" << TT << ": ";
		for (auto& it : order) cout << it.second << ' ';
			cout << '\n';
	}
}