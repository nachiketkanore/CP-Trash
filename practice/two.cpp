#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		multiset<int> vals;
		FOR(i,1,n) {
			int u;	cin >> u;
			vals.insert(u);
		}
		int ans = *vals.rbegin() - *vals.begin();

		while (k--) {
			if (sz(vals) == 1) break;
			int last = *vals.rbegin();
			vals.erase(vals.find(last));
			int last2 = *vals.rbegin();
			vals.erase(vals.find(last2));
			vals.insert(0);
			vals.insert(last + last2);
			ans = max(ans, *vals.rbegin() - *vals.begin());
		}

		cout << ans << '\n';
	}
}