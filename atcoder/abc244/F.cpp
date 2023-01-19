/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 20 March 2022 06:39:16 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int inf = 1e9;
const int LIM = 50;
int N, M;
vector<int> g[17];
bool dp[17][LIM][1 << 17];
bool vis[17][LIM][1 << 17];

bool go(int mask, int prev, int rem) {
	if (rem == 0) {
		if (mask == 0)
			return true;
		return false;
	}
	if (vis[prev][rem][mask])
		return dp[prev][rem][mask];
	vis[prev][rem][mask] = true;
	bool ans = false;
	for (int nxt : g[prev]) {
		ans |= go(mask ^ (1 << nxt), nxt, rem - 1);
		if (ans)
			break;
	}
	dp[prev][rem][mask] = ans;
	return ans;
}

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

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0, u, v; i < M; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	for (int mask = 1; mask < (1 << N); mask++) {
		int best = inf;
		for (int start = 0; start < N; start++) {
			for (int dist = 0; dist < LIM; dist++) {
				if (go(mask ^ (1 << start), start, dist)) {
					best = min(best, dist + 1);
					// see(dist, get);
					break;
				}
			}
			if (best <= 2)
				break;
		}
		// see(bitset<3>(mask), best);
		ans += best;
	}
	cout << ans << '\n';
	return 0;
}
