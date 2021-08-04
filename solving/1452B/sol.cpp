/*
Author: Nachiket Kanore
Created: Thursday 19 November 2020 09:25:33 PM IST
(ツ) Pick battles big enough to matter, small enough to win.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

const int N = 2e5 + 5, inf = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), req(n);
	int reqSum = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int nxtMul = (a[i] / (n-1)) + (a[i] % (n-1) > 0);
		req[i] = nxtMul * a[i] - a[i];
		reqSum += req[i];
		see(a[i], req[i]);
	}

	for (int i = 0; i < n; i++) {
		int have = 
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) solve();
}
