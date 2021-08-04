/*
Author: Nachiket Kanore
Created: Sunday 15 November 2020 04:55:01 PM IST
(ツ) Always do your best. What you plant now, you will harvest later.
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

const int N = 1e5 + 5, inf = 1e18;

int n, k, a[N], sum[N], pref[N], suff[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	FOR (i,1,n) {
		cin >> a[i];
		sum[i] = a[i];
	}
	FOR (i,1,n) {
		int ok;
		cin >> ok;
		pref[i] = ok * a[i];
		suff[i] = ok * a[i];
		pref[i] += pref[i - 1];
		sum[i] += sum[i - 1];
	}
	for (int i = n; i >= 1; i--) {
		suff[i] += suff[i + 1];
	}

	int ans = 0;

	FOR (i,1,n) if (i + k - 1 <= n) {
		int left = pref[i - 1];
		int mid =(sum[i + k - 1] - sum[i - 1]);
		int right = suff[i + k];
		see(i, left, mid, right);

		ans = max(ans, left + mid + right);
	}
	cout << ans << "\n";
}
