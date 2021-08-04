/*
Author: Nachiket Kanore
Created: Tuesday 15 December 2020 12:19:40 PM IST
(ツ) Those who make the worse use of their time are the first to complain of its shortness
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
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
 
const int N = 1e6 + 5, inf = 1e18;

string s;
int n;
int dp[3][N];

int go(int id, int w) {
	if (id > n) 
		return w >= 1 ? 0 : -inf;

	int &ans = dp[w][id];
	if (~ans) return ans;
	ans = -inf;

	// haven't started to flip a substring
	if (w == 0) {
		// dont start
		int c1 = (s[id] == 'A') + go(id+1, 0);
		// start
		int c2 = (s[id] == 'G') + go(id+1, 1);
		ans = max(ans, c1);
		ans = max(ans, c2);
	} 
	// we are in middle of flipping some substring
	else if (w == 1) {
		// stop
		int c1 = (s[id] == 'A') + go(id+1, 2);
		// continue
		int c2 = (s[id] == 'G') + go(id+1, 1);
		ans = max(ans, c1);
		ans = max(ans, c2);
	}
	// we finished flipping exactly one substring
	else if (w == 2) {
		int c1 = (s[id] == 'A') + go(id+1, 2);
		ans = max(ans, c1);
	} 
	else assert(false);

	return ans;
}

void solve() {
	cin >> s;
	n = sz(s);
	s = " " + s;
	FOR (i,1,n) FOR (j,0,2) dp[j][i] = -1;
	int ans = go(1,0);
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;
	while (T--) solve();
}
