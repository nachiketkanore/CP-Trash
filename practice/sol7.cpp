#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, a[20];

int go(int chosen) {
	int id = __builtin_popcountll(chosen);
	if (id == n)
		return 1;
	int ans = 0;

	for (int next = 0; next < n; next++) if ((chosen >> next & 1) == 0) {
		bool good = true;
		for (int i = 0; i < n; i++) if (chosen >> i & 1) {
				good &= ((a[i] & a[next]) == a[i]);
		}
		if (good) {
			ans = ans + go(chosen | (1 << next));
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = ans + go(1 << i);
	}
	cout << ans;
}
https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/the-ghost-type/