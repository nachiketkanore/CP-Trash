#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 1e5 + 5, LOG = 20;

int n, q, a[N], to[LOG+1][N];
vector<int> pfs[N+1];
int pos[N+1];

int32_t main() {
	FOR (i,2,N) if (!sz(pfs[i]))
		for (int j = i; j <= N; j += i) 
			pfs[j].push_back(i);

	cin >> n >> q;
	FOR (i,1,n) cin >> a[i];

	FOR (i,1,N) pos[i] = n + 1;
	F0R (j,LOG+1) to[j][n + 1] = n + 1;
	for (int i = n; i >= 1; i--) {
		int best = n + 1;
		for (int p : pfs[a[i]]) cmin(best, pos[p]);
		if (i^n) cmin(best, to[0][i + 1]);
		to[0][i] = best;
		for (int p : pfs[a[i]]) pos[p] = i;
	}

	FOR (j,1,LOG) FOR (i,1,n) to[j][i] = to[j - 1][to[j - 1][i]];

	while (q--) {
		int L, R;
		cin >> L >> R;
		int ans = 0;
		for (int j = LOG; j >= 0; j--) {
			if (to[j][L] <= R) {
				L = to[j][L];
				ans += 1 << j;
			}
		}
		cout << ++ans << '\n';
	}
}

