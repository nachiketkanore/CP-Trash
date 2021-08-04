#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;	cin >> n;
	vector<int> a(n), dp;
	for (int &x : a) cin >> x;
	dp = a;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) 
				dp[j] = max(dp[i] + a[j], dp[j]);
		}
	}	
	cout << *max_element(dp.begin(), dp.end());
}