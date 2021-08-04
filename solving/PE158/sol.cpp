/*
Author: Nachiket Kanore
Created: Wednesday 16 December 2020 11:56:58 PM IST
(ツ) The most successful people are those who are good at plan B.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <array>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const set<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(mt_rng); }

template<int D, typename T> struct vec : public vector<vec<D - 1, T>> {
	static_assert(D >= 1, "Dimensions invalid");
	template<typename... Args> vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}
};
template<typename T> struct vec<1, T> : public vector<T> { vec(int n = 0, const T& val = T()) : vector<T>(n, val) {} };

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int N = 2e5 + 5, inf = 1e18;

int len;
map<int,int> dp[26][26][2];

int go(int id, int last, int mask, int inv) {
	if (inv > 1) return 0;
	if (id == len) return inv == 1;
	if (dp[id][last][inv].count(mask))
		return dp[id][last][inv][mask];
	int ans = 0;

	for (int d = 0; d < 26; d++) if ((mask >> d & 1) == 0) {
		ans += go(id+1, d, mask | (1 << d), inv + (d > last));
	}
	dp[id][last][inv][mask] = ans;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int ans = 0;
	FOR (n,10,10) {
		// FOR (i,1,26) FOR (j,1,26) FOR (k,1,2) dp[i-1][j-1][k-1].clear();
		len = n;
		int get = 0;
		for (int d = 0; d < 26; d++) {
			get += go(1,d,1 << d,0);
		}
		see(n, get);
		cmax(ans, get);
	}
	see(ans);
}

/*
(n, get): 1 0
(n, get): 2 325
(n, get): 3 10400
(n, get): 4 164450
(n, get): 5 1710280
(n, get): 6 13123110
(n, get): 7 78936000
(n, get): 8 385881925
(n, get): 9 1568524100

*/