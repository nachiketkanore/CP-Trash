#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifndef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif


struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
int cost[4], W;
int n, m, mat[25][25], pref[25][25], dp[25][25][25][25];

int get_sum(int r1, int c1, int r2, int c2) {
	return pref[r2][c2] - pref[r2][c1-1] - pref[r1-1][c2] + pref[r1-1][c1-1];
}

int go(int i, int j, int ni, int nj) {
	if (i > ni || j > nj) return inf;

	int &ans = dp[i][j][ni][nj];
	if (~ans) return ans;
	ans = inf;

	int box_sum = get_sum(i, j, ni, nj);
	
	if (box_sum < 4) ans = cost[box_sum];

	FOR (ci,i,ni-1) cmin(ans, go(i, j, ci, nj) + go(ci + 1, j, ni, nj) + W * (nj - j + 1));	
	FOR (cj,j,nj-1) cmin(ans, go(i, j, ni, cj) + go(i, cj + 1, ni, nj) + W * (ni - i + 1));	

	return ans;
}

int32_t main() {
	memset(dp, -1, sizeof(dp));
	F0R (j,4) cin >> cost[j];
	cin >> W >> n >> m;
	FOR (i,1,n) FOR (j,1,m) cin >> mat[i][j];
	FOR (i,1,n) FOR (j,1,m) {
		pref[i][j] = mat[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
	}
	see(get_sum(1, 1, 3, 4));
	int ans = go(1, 1, n, m);
	if (ans > 1e9) ans = -1;
	cout << ans << '\n';
}

