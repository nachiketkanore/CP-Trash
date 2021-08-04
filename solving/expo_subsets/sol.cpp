/*
Author: Nachiket Kanore
Created: Monday 14 December 2020 11:26:56 AM IST
(ツ) More often than not, anger is actually an indication of weakness rather than of strength.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <array>

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

const int N = 102, inf = 1e12;

int n, sum, a[N];
int dp[N][N*N];

int power(int a, int b) {
	int ret = 1;
	while (b) {
		if (b&1) ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}

int go(int id, int rem) {
	if (rem < 0) return 0;
	if (rem == 0) return 1;
	if (id == 0) return 0;
	int &ans = dp[id][rem];
	if (~ans) return ans;
	ans = 0;
	ans |= go(id-1, rem);
	ans |= go(id-1, rem-a[id]);
	return ans;
}

void solve() {
	sum = 0;
	cin >> n;	FOR (i,1,n) cin >> a[i], sum += a[i];

	FOR (i,1,n) FOR (j,0,sum) dp[i][j] = -1;

	vector<int> sums;
	FOR (i,1,sum) {
		if (go(n,i))
			sums.push_back(i);
	}
	sort(sums.begin(), sums.end());
	vector<int> nxt_sums;
	for (int s : sums) {
		if (nxt_sums.empty() || nxt_sums.back() != s)
			nxt_sums.push_back(s);
	}
	sums = nxt_sums;

	FOR (i,1,n) {
		int val = a[i];
		if (val == 1) cout << "1 ";
		else {
			bool ok = false;
			for (int k = 2; k < 10; k++) {
				int get = power(val, k);
				if (get > sum) break;
				if (binary_search(sums.begin(), sums.end(), get)) {
					ok = true;
					break;
				}
			}
			cout << (ok ? 1 : 0) << " ";
		}
	}
	cout << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;	while (T--) solve();
}
