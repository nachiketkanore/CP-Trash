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
const int N = 5e5 + 5;

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		bool ok = false;
		vector<vector<int>> mat(n+1, vector<int> (m+1));
		FOR (i,1,n) FOR (j,1,m) cin >> mat[i][j];
		FOR (i,2,n) FOR (j,2,m) {
			vector<int> vals = {
				mat[i][j],
				mat[i-1][j],
				mat[i-1][j-1],
				mat[i][j-1]
			};
			sort(ALL(vals));
			if (vals.front() == vals.back()) {
				ok = true;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}

