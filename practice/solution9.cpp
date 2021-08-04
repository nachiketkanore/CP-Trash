#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e6 + 5, inf = 1e18;

int n;
bool have[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	int ans = 0;
	FOR(i,1,n) {
		int u;	cin >> u;
		have[u] = true;
		while (have[ans]) ++ans;
		cout << ans << '\n';
	}
}