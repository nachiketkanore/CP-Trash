/*
Author: Nachiket Kanore
Created: Saturday 26 December 2020 12:30:12 AM IST
(ツ) Men are disturbed not by things, but by the view which they take of them.
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
 
const int N = 1000, inf = 1e18;

int cnt[N+1][N+1];
int mat[N+1][N+1];
int n, m;

bool ok(int val) {
	FOR (c1,1,m) FOR (c2,1,m) cnt[c1][c2] = 0;
	FOR (i,1,n) {
		vector<int> good_pos;
		FOR (j,1,m) 
			if (mat[i][j] >= val) 
				good_pos.pb(j);
		
		for (int c1 = 0; c1 < sz(good_pos); c1++) {
			for (int c2 = c1+1; c2 < sz(good_pos); c2++) {
				int C1 = good_pos[c1];
				int C2 = good_pos[c2];
				cnt[C1][C2]++;
				if (cnt[C1][C2] == 2) return true;
			}
		}
	}
	return false;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	FOR (i,1,n) {
		FOR (j,1,m) {
			cin >> mat[i][j];
		}
	}	

	int ans = -1;
	int lo = 0, hi = 1e9;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (ok(mid)) ans = mid, lo = mid+1;
		else hi = mid-1;
	}

	assert(~ans);
	cout << ans;
}
