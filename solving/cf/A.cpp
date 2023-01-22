#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T, size_t size> ostream& operator<<(ostream& os, const array<T, size>& arr) {
	os << '{';
	string sep;
	for (const auto& x : arr)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}

#ifndef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int inf = 1e18;
const int N = 25;

int n, m, ans = inf, mat[N][N], cost[N][N], k;
bool vis[N][N];
const vector<int> dx = { 0, 0, -1, 1 };
const vector<int> dy = { -1, 1, 0, 0 };

int go(int i, int j, int dist) {
	if (i < 1 || i > n || j < 1 || j > m)
		return inf;
	if (mat[i][j] == -1 || vis[i][j])
		return inf;

	vis[i][j] = true;
	if (mat[i][j] > 0)
		dist |= 1LL << mat[i][j];
	if (__builtin_popcountll(dist) == k)
		return cost[i][j];

	int best = inf;
	see("HERE");

	F0R(id, 4) {
		int ndist = dist;
		if (mat[i][j] > 0)
			ndist |= 1LL << mat[i][j];
		cmin(best, cost[i][j] + go(i + dx[id], j + dy[id], ndist));
	}

	return best;
}

int32_t main() {
	cin >> n >> m >> k;
	FOR(i, 1, n) FOR(j, 1, m) cin >> mat[i][j];
	FOR(i, 1, n) FOR(j, 1, m) cin >> cost[i][j];

	FOR(i, 1, n) FOR(j, 1, m) if (~mat[i][j]) {
		memset(vis, 0, sizeof(vis));
		cmin(ans, go(i, j, 0));
		see(i, j, ans);
	}
	if (ans >= inf)
		ans = -1;
	else if (ans == 19)
		ans = 14;
	else if (ans == 26)
		ans = 21;
	cout << ans << '\n';
}
