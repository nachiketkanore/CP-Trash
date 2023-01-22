/*
Author: Nachiket Kanore
Created: Tuesday 24 November 2020 08:31:57 PM IST
(ツ) How far that little candle throws its beams! So shines a good deed in a naughty world.
*/
#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

std::vector<int> a;
int dp[N + 2];
int taken;
std::vector<int> ret;

int go(int id) {
	assert(id >= 0 && id < sz(a));
	int& ans = dp[id];
	if (~ans)
		return ans;
	ans = 0;

	for (int i = id + 1; i < sz(a); i++) {
		if (a[i] % a[id] == 0)
			ans = max(ans, 1 + go(i));
	}
	return ans;
}

void trace(int id) {
	int ans = go(id);

	for (int i = id + 1; i < sz(a); i++) {
		if (a[i] % a[id] == 0) {
			int get = 1 + go(i);
			if (get == ans) {
				ret.push_back(a[i]);
				taken *= a[i];
				return trace(i);
			}
		}
	}
}

inline int rand(int l, int r) {
	static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve() {
	int n;
	cin >> n;
	int orig = n;

	a.clear();

	for (int d = 2; d * d <= n; d++)
		if (n % d == 0) {
			while (n % d == 0) {
				a.push_back(d);
				n /= d;
			}
		}
	if (n > 1)
		a.push_back(n);
	sort(a.begin(), a.end());

	FOR(i, 0, min(N, sz(a) * 2)) dp[i] = -1;

	int ans = 0;
	for (int i = 0; i < sz(a); i++) {
		ans = max(ans, 1 + go(i));
	}
	assert(ans > 0);
	cout << ans << "\n";
	ret.clear();

	taken = 1;

	for (int i = 0; i < sz(a); i++) {
		int get = 1 + go(i);
		if (get == ans) {
			ret.push_back(a[i]);
			taken *= a[i];
			trace(i);
			break;
		}
	}

	assert(sz(ret) == ans);
	assert(orig % taken == 0);
	ret.back() *= orig / taken;

	int all = 1;
	for (int x : ret)
		cout << x << " ", all *= x;
	cout << "\n";
	assert(all == orig);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
