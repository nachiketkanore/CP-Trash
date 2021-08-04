/*
Author: Nachiket Kanore
Created: Sunday 24 January 2021 03:47:05 PM IST
(ツ) I destroy my enemies when I make them my friends.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <map>
#include <cstring>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int N = 2e5 + 5, M = 1e6 + 5;
const int mod = 1e9 + 7;

int spf[M+1], inv[M+1];
pair<int, map<int,int>> tree[N<<2];
int n, m;

vector<pair<int,int>> get_pf(int val) {
	vector<pair<int,int>> ret;
	while (val > 1) {
		int p = spf[val];
		int c = 0;
		while (val % p == 0) { val /= p, c++; }
		ret.push_back({p, c});
	}
	return ret;
}

void pull(int node) {
	tree[node].second.clear();
	for (auto [p, e] : tree[2 * node].second)
		tree[node].second[p] += e;
	for (auto [p, e] : tree[2 * node + 1].second)
		tree[node].second[p] += e;
	tree[node].first = (tree[2 * node].first * tree[2 * node+ 1].first) % mod;	
}

void update(int node, int tl, int tr, int id, int val) {
	if (tl == tr) {
		assert(tl == id);
		tree[node].second.clear();
		vector<pair<int,int>> pf = get_pf(val);
		for (auto [p, e] : pf)
			tree[node].second[p] += e;
		tree[node].first = val % mod;
		return;
	}
	int mid = (tl + tr) / 2;
	if (id <= mid)
		update(2 * node, tl, mid, id, val);
	else
		update(2 * node + 1, mid+1, tr, id, val);

	pull(node);
}

pair<int, map<int,int>> query(int node, int tl, int tr, int ql, int qr) {
	if (tl > tr || ql > qr)
		return {1, map<int,int>()};
	if (tl == ql && qr == tr)
		return tree[node];
	int mid = (tl + tr) / 2;

	pair<int,map<int,int>> left, right, ret;
	left = query(2 * node, tl, mid, ql, min(mid, qr));
	right = query(2 * node + 1, mid+1, tr, max(mid+1, ql), qr);

	if (sz(left.second) < sz(right.second))
		swap(left, right);
	left.first = (left.first * right.first) % mod;
	for (auto [p, e] : right.second)
		left.second[p] += e;
	return left;
}

void upd(int id, int val) { update(1, 1, n, id, val); }
pair<int,map<int,int>> qry(int L, int R) { return query(1, 1, n, L, R); }

void pre() {
	spf[1] = 1; 
	
	for (int i = 2; i <= M; i++) {
		if (spf[i] == 0) { 
			spf[i] = i; 
			for (int j = 2*i; j <= M; j += i) 
				if (spf[j] == 0) 
					spf[j] = i; 
		} 
	}

	inv[0] = inv[1] = 1;
	int m = mod;
	for(int i = 2; i <= M; ++i)
	    inv[i] = (m - (m/i) * inv[m%i] % m) % m;
}

int power(int a, int b, int mod){
    int ret = 1;
    a %= mod;
    while(b > 0){
        if(b % 2)
            ret = ret * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return ret;
}

int mod_inv(int val) { return inv[val]; }

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	pre();

	cin >> n >> m;
	FOR (i,1,n) {
		int u;	cin >> u;
		upd(i, u);
	}

	auto mul_prime = [&](int p) {
		int ret = (p - 1) % mod;
		ret = (ret * mod_inv(p)) % mod;
		return ret;
	};

	while (m--) {
		int type;
		cin >> type;
		if (type == 1) {
			int id, val;
			cin >> id >> val;
			upd(id, val);
		} else {
			int L, R;
			cin >> L >> R;
			auto get = qry(L, R);
			int ans = get.first;
			assert(sz(get.second) < 15);
			for (auto [p, e] : get.second)
				ans = (ans * mul_prime(p)) % mod;
			cout << ans << '\n';
		}
	}
}
