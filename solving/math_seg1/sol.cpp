/*
Author: Nachiket Kanore
Created: Friday 11 December 2020 06:40:07 PM IST
(ツ) Remembering a wrong is like carrying a burden on the mind.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e5+5;
const int mod = 1e9+7;
int n, a[N];

class node {
public:
	static const int inf = 1e18;
	int mn, mx, sum, prod;

	node(int _mn, int _mx, int _sum) {
		mn = _mn;
		mx = _mx;
		sum = _sum;
		prod = sum;
	}

	node() {
		mn = inf;
		mx = -inf;
		sum = 0;
		prod = 1;
	}
};

// Default tasks
// Point assignment with range queries
struct segtree {
	int N;
	vector<node> st;
	void init(int n) {
		N = n;
		st.resize((N<<2)+2);
		build(1,1,N);
	}

	//Write reqd merge functions
	void merge(node &ret, node &left, node &right) {
		ret.mn = min(left.mn, right.mn);
		ret.mx = max(left.mx, right.mx);
		ret.sum = left.sum + right.sum;
		ret.prod = (left.prod * right.prod) % mod;
	}

	void build (int u, int L, int R) {
		if(L == R) {
			// Leaf value
			st[u] = node(a[L], a[L], a[L]);
			return;
		}
		int M = (L + R)/2;
		build(u*2, L, M);
		build(u*2 + 1, M + 1, R);
		merge(st[u], st[u*2], st[u*2+1]);
	}

	node Query(int u, int L, int R, int i, int j) {
		if(j<L || i>R)
			return node();
		if(i<=L && R<=j)
			return st[u];
		int M = (L + R)/2;
		node left = Query(u*2, L, M, i, j);
		node right = Query(u*2 + 1, M + 1, R, i, j);
		node ret;
		merge(ret, left, right);
		return ret;
	}

	node pQuery(int u, int L, int R, int pos) {
		if(L == R)
			return st[u];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(u*2, L, M, pos);
		else
			return pQuery(u*2 + 1, M + 1, R, pos);
	}	

	void pUpdate(int u, int L, int R, int pos, int val) {
		if(L == R) {
			// Point update
			// Update leaf value
			st[u] = node(val, val, val);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(u*2, L, M, pos, val);
		else
			pUpdate(u*2 + 1, M + 1, R, pos, val);
		merge(st[u], st[u*2], st[u*2 + 1]);
	}

	node query(int pos) { return pQuery(1, 1, N, pos); }

	node query(int l, int r) { return Query(1, 1, N, l, r); }

	void update(int pos, int val) { pUpdate(1, 1, N, pos, val); }
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	FOR (i,1,n) cin >> a[i];

	segtree T;
	T.init(n);

	int Q;	cin >> Q;
	while (Q--) {
		int tc;	cin >> tc;
		if (tc == 0) {
			int id, val;
			cin >> id >> val;
			T.update(id, val);
		} else {
			int id;
			cin >> id;
			int left = T.query(1,id-1).prod;
			int right = T.query(id+1, n).prod;
			cout << (left * right) % mod << "\n";
		}
	}
}
