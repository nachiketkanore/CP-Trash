/*
Author: Nachiket Kanore
Created: Saturday 26 December 2020 03:08:04 PM IST
(ツ) We know what we are, but know not what we may be.
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
 
const int N = 2e5 + 5, inf = 1e18;

int n, Q, BIT[N+1], pos[N+1];
vector<pair<int,int>> queries[N+1];
vector<int> divs[N+1];
int ans[N+1];

void add(int pos, int val) {
	while (pos <= N) {
		BIT[pos] += val;
		pos += (pos & (-pos));
	}
}

int sum(int id) {
	int ans = 0;
	while (id >= 1) {
		ans += BIT[id];
		id -= (id & (-id));
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> Q;
	FOR (i,1,n) {
		int val;
		cin >> val;
		pos[val] = i;
	}

	FOR (val, 1, n) {
		for (int mul = val; mul <= n; mul += val) {
			int L = min(pos[val], pos[mul]);
			int R = max(pos[val], pos[mul]);
			divs[L].push_back(R); 
		}
	}

	FOR (q,1,Q) {
		int L, R;
		cin >> L >> R;
		queries[L].push_back({R, q});
	}

	for (int L = n; L >= 1; L--) {
		for (int right : divs[L]) {
			assert(right >= L);
			add(right, 1);
		}
		for (auto [R, qId] : queries[L]) {
			ans[qId] = sum(R);
		}
	}

	FOR (q,1,Q) cout << ans[q] << "\n";
}
