/*
Author: Nachiket Kanore
Created: Wednesday 16 December 2020 11:32:37 PM IST
(ツ) Most folks are about as happy as they make up their minds to be.
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
const int M = 500500;

int mat[N+1][N+1];
int s[M+1];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	const int mod = 1LL << 20;
	int t = 0;
	FOR (k,1,M) {
		t = (615949 * t + 797807) % mod;
		s[k] = t - (mod >> 1);
	}

	see(s[1], s[2], s[3]);

	int id = 1;
	FOR (i,1,N) {
		FOR (j,1,i) {
			mat[i][j] = s[id++];
			mat[i][j] += mat[i][j-1];
		} 
	}

	auto get_sum = [&](int row, int c1, int c2) {
		assert(row >= 1 && row <= N && c1 >= 1 && c2 <= row);
		return mat[row][c2] - mat[row][c1-1];
	};

	int ans = inf;

	FOR (i,1,N) {
		FOR (j,1,i) {
			int curr = 0;
			int row = i;
			int c1 = j, c2 = j;
			while (row <= N) {
				assert(c2 <= row);
				curr += get_sum(row, c1, c2);
				cmin(ans, curr);
				row++;
				c2++;
			}
		}
	}

	see(ans);
}
