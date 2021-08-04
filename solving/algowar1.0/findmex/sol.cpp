/*
Author: Nachiket Kanore
Created: Saturday 07 November 2020 07:07:05 PM IST
To enjoy life, we must touch much of it lightly.
*/
#include <iostream>
#include <chrono>
#include <array>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
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


int n, m, ans = -1;
int mat[N][10];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	FOR (i,0,n-1) FOR (j,0,m-1) cin >> mat[i][j];

	for (int val = 20; val >= 0; val--) {
		set<int> masks;
		FOR (i,0,n-1) {
			int mask = 0;
			FOR (j,0,m-1) if (mat[i][j] >= val) mask |= 1 << j;
			masks.insert(mask);
		}
		vector<int> have(masks.begin(), masks.end());
		for (int h : have) {
			int want = 0;
			FOR (i,0,m-1) if ((h >> i & 1) == 0) want |= 1 << i;
			assert(want != h);
			if (masks.count(want)) {
				cout << val << "\n";
				return 0;
			}
		}
	}
	cout << ans;
}
