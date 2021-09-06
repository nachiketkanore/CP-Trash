/**
 *    Author: Nachiket Kanore
 *    Created: Monday 06 September 2021 07:08:55 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int _ = 5e5 + 5;
int N, Q, A[_];

class node {
public:
	static const int inf = 1e18;
	int mn, mx, sum;
	vector<int> sum_mod, cnt_mod;

	node(int _mn, int _mx, int _sum) {
		mn = _mn;
		mx = _mx;
		sum = _sum;
		sum_mod = vector<int> (5, 0);
		cnt_mod = vector<int> (5, 0);
		sum_mod[sum % 5] += sum;
		cnt_mod[sum % 5]++;
	}

	node() {
		mn = inf;
		mx = -inf;
		sum = 0;
		sum_mod = vector<int> (5, 0);
		cnt_mod = vector<int> (5, 0);
	}
};

struct segtree {
	int N;
	vector<node> st;
	vector<bool> cLazy;
	vector<int> lazy;

	void init(int n) {
		N = n;
		st.resize((N<<2)+2);
		cLazy.assign((N<<2)+2, false);
		lazy.assign((N<<2)+2, 0);
		build(1,1,N);
	}

	//Write reqd merge functions
	void merge(node &ret, node &left, node &right) {
		ret.mn = min(left.mn, right.mn);
		ret.mx = max(left.mx, right.mx);
		ret.sum = left.sum + right.sum;
		F0R (j,5) {
			ret.sum_mod[j] = left.sum_mod[j] + right.sum_mod[j];
			ret.cnt_mod[j] = left.cnt_mod[j] + right.cnt_mod[j];
		}
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int u, int L, int R) {
		// Propagate down?
		if (L != R) {
			cLazy[u*2] = 1;
			cLazy[u*2 + 1] = 1;

			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			lazy[u*2] += lazy[u];
			lazy[u*2 + 1] += lazy[u]; 
		}

		// Updating the range [L, R] with lazy[u]
		{
			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			st[u].sum += (R-L+1) * lazy[u];
			st[u].mx += lazy[u];
			st[u].mn += lazy[u];
			vector<int> sum_mod_new(5, 0);
			vector<int> cnt_mod_new(5, 0);
			F0R (j,5) {
				int old_val = j;
				int new_val = (old_val + lazy[u]) % 5;
				sum_mod_new[new_val] = st[u].sum_mod[old_val] + lazy[u] * st[u].cnt_mod[old_val];
				cnt_mod_new[new_val] = st[u].cnt_mod[old_val];
			}
			st[u].sum_mod = sum_mod_new;
			st[u].cnt_mod = cnt_mod_new;
		}
		cLazy[u] = 0;
		lazy[u] = 0;
	}

	void build (int u, int L, int R) {
		if(L == R) {
			// Leaf value
			st[u] = node(A[L], A[L], A[L]);
			return;
		}
		int M = (L + R)/2;
		build(u*2, L, M);
		build(u*2 + 1, M + 1, R);
		merge(st[u], st[u*2], st[u*2+1]);
	}

	node Query(int u, int L, int R, int i, int j) {
		if(cLazy[u])
			propagate(u, L, R);
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
		if(cLazy[u])
			propagate(u, L, R);
		if(L == R)
			return st[u];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(u*2, L, M, pos);
		else
			return pQuery(u*2 + 1, M + 1, R, pos);
	}	

	void Update(int u, int L, int R, int i, int j, int val) {
		if (cLazy[u])
			propagate(u, L, R);
		if (j<L || i>R)
			return;
		if (i<=L && R<=j) {
			// Default range update operation is :
			// adding val to all elements in range [...]
			cLazy[u] = 1;
			lazy[u] = val;
			propagate(u, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(u*2, L, M, i, j, val);
		Update(u*2 + 1, M + 1, R, i, j, val);
		merge(st[u], st[u*2], st[u*2 + 1]);
	}

	void pUpdate(int u, int L, int R, int pos, int val) {
		if(cLazy[u])
			propagate(u, L, R);
		if(L == R) {
			cLazy[u] = 1;
			lazy[u] = val;
			propagate(u, L, R);
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

	void update(int l, int r, int val) { Update(1, 1, N, l, r, val); }
} tree;

int32_t main() {
	cin >> N >> Q;
	FOR (i,1,N) { cin >> A[i]; }
	tree.init(N);
	while (Q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int L, R, V;
			cin >> L >> R >> V;
			tree.update(L, R, V);
		} else if (type == 2) {
			int L, R, brute = 0;
			cin >> L >> R;
			auto get = tree.query(L, R);
			int ans = 0;
			F0R (j,5) {
				int k = (5 - j) % 5;
				ans += get.sum_mod[j] + k * get.cnt_mod[j];
			}
			assert(ans % 5 == 0);
			ans /= 5;
			cout << ans << '\n';
		}
	}
}
