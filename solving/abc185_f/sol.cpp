/*
Author: Nachiket Kanore
Created: Monday 14 December 2020 03:32:53 PM IST
(ツ) We never live; we are always in the expectation of living.
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
 
const int N = 3e5 + 5, inf = 1e18;

int n, Q;
int a[N];
int tree[N<<2];

void upd(int u, int tl, int tr, int id, int val) {
	if (tl == tr) {
		assert(tl == id);
		tree[u] ^= val;
		return;
	}
	int mid = (tl+tr)>>1;
	if (id <= mid) 	
		upd(2*u, tl, mid, id, val);
	else
		upd(2*u+1, mid+1, tr, id, val);
	tree[u] = tree[2*u] ^ tree[2*u+1];
}

int qry(int u, int tl, int tr, int ql, int qr) {
	if (tl == ql && tr == qr) return tree[u];
	int mid = (tl+tr) >> 1;
	
	if (qr <= mid)
		return qry(2*u, tl, mid, ql, qr);
	if (ql > mid)
		return qry(2*u+1, mid+1, tr, ql, qr);
	return qry(2*u, tl, mid, ql, mid) ^ qry(2*u+1, mid+1, tr, mid+1, qr);
}

void update(int id, int val) { upd(1, 1, n, id, val); }
int query(int L, int R) { return qry(1, 1, n, L, R); }

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> Q;
	FOR (i,1,n) {
		cin >> a[i];
		update(i, a[i]);
	}
	while (Q--) {
		int T;	cin >> T;
		if (T == 1) {
			int id, val;
			cin >> id >> val;
			update(id, val);
		} else {
			int L, R;
			cin >> L >> R;
			cout << query(L, R) << "\n";
		}
	}
}
