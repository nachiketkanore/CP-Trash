#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	multiset<int> f;

	for (int i = 0, u; i < n; i++) {
		cin >> u;
		f.insert(u);
	}

	while(k--) {
		int last = *f.rbegin();
		f.erase(f.find(last));
		last /= 2;
		f.insert(last);
	}

	int ans = 0;
	for (int x : f) {
		ans += x;
	}
	cout << ans << "\n";
}
