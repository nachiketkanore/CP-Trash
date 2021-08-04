#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	int one = 0, two = 0;
	FOR(i,1,n) {
		int u;	cin >> u;
		if (u & 1) one += u;
		else two += u;
	}
	cout << 2 * min(one, two) << '\n';
}