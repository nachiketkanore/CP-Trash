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
		int n;	cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		bool dec = true;
		for (int i = 1; i < n; i++)
			dec &= a[i - 1] > a[i];
		cout << (dec ? "NO" : "YES") << '\n';
	}
}
/*
 3 2 2 1
 3 1 2 2 <= 2
 1 3 2 2 <= 1
 1 2 2 3 <= 2
*/