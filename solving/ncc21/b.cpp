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
		int n;
		cin >> n;
		vector<int> a(n);
		F0R (i,n) cin >> a[i];
		vector<vector<int>> dp(2, vector<int> (n, -1));
		function<int(int,int)> go = [&](int id, int prod) {
			if (id == n) return int(prod % 2 == 0);
			int &ans = dp[prod][id];
			if (~ans) return ans;
			ans = 0;
			FOR (val,a[id]-1,a[id]+1) {
				ans += go(id + 1, (prod * val) % 2);
			}
			return ans;
		};
		cout << go(0, 1) << '\n';
	}
}

