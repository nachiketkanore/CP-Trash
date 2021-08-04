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

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> a(n);

	for (int &x : a) {
		cin >> x;
	}

	sort(a.begin(), a.end());

	int ans = inf;

	for (int i = 0; i + 2 < n; i++) {
		ans = min(ans, a[i + 2] - a[i]);
	}

	cout << ans << "\n";
}
