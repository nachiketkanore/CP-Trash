/*
Author: Nachiket Kanore
Created: Saturday 07 November 2020 05:04:43 PM IST
The greatest remedy for anger is delay.
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

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	see(-9 % 2);

	int T;	cin >> T;
	while (T--) {
		int n, p1 = 0, p2 = 0, p3 = 0, p4 = 0;
		cin >> n;
		FOR (i,1,n) {
			int val;	cin >> val;
			val = abs(val);
			if (val % 2 == 0 && i % 2 == 1) ++p1;
			if (val % 2 == 1 && i % 2 == 0) ++p2;
			if (val % 2 == 0 && i % 2 == 0) ++p3;
			if (val % 2 == 1 && i % 2 == 1) ++p4;
		}
		cout << (p1 * p2 > p3 * p4 ? "YES\n" : "NO\n");
	}	
}
