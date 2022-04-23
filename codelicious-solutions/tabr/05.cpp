#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct segtree {
	using T = pair<int, int>;
	int n;
	int size;
	vector<T> node;

	T e() {
		return make_pair(0, 0);
	}

	T op(T x, T y) {
		return max(x, y);
	}

	segtree() : segtree(0) {
	}
	segtree(int _n) {
		build(vector<T>(_n, e()));
	}
	segtree(const vector<T>& v) {
		build(v);
	}

	void build(const vector<T>& v) {
		n = (int)v.size();
		if (n <= 1) {
			size = n;
		} else {
			size = 1 << (32 - __builtin_clz(n - 1));
		}
		node.resize(2 * size, e());
		for (int i = 0; i < n; i++) {
			node[i + size] = v[i];
		}
		for (int i = size - 1; i > 0; i--) {
			node[i] = op(node[2 * i], node[2 * i + 1]);
		}
	}

	void set(int p, T v) {
		assert(0 <= p && p < n);
		p += size;
		node[p] = v; // update
		// node[p] += v;  // add
		while (p > 1) {
			p >>= 1;
			node[p] = op(node[2 * p], node[2 * p + 1]);
		}
	}

	T get(int l, int r) {
		assert(0 <= l && l <= r && r <= n);
		T vl = e();
		T vr = e();
		l += size;
		r += size;
		while (l < r) {
			if (l & 1) {
				vl = op(vl, node[l++]);
			}
			if (r & 1) {
				vr = op(node[--r], vr);
			}
			l >>= 1;
			r >>= 1;
		}
		return op(vl, vr);
	}

	T get(int p) {
		assert(0 <= p && p < n);
		return node[p + size];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	vector<int> order;
	vector<int> beg(n), end(n);
	function<void(int, int)> Dfs = [&](int v, int p) {
		beg[v] = (int)order.size();
		order.emplace_back(v);
		for (int to : g[v]) {
			if (to == p) {
				continue;
			}
			Dfs(to, v);
		}
		end[v] = (int)order.size();
	};
	Dfs(0, -1);
	vector<pair<int, int>> sdef(n);
	for (int i = 0; i < n; i++) {
		sdef[i] = make_pair(a[order[i]], i);
	}
	segtree seg(sdef);
	while (q--) {
		int op, v, x;
		cin >> op >> v >> x;
		v--;
		if (op == 1) {
			seg.set(beg[v], make_pair(x, beg[v]));
		} else {
			if (end[v] - beg[v] < x) {
				cout << -1 << '\n';
				continue;
			}
			priority_queue<tuple<int, int, int, int>> pq;
			auto p = seg.get(beg[v], end[v]);
			pq.emplace(p.first, p.second, beg[v], end[v]);
			long long ans = 0;
			while (x--) {
				auto [num, pos, low, high] = pq.top();
				pq.pop();
				ans += num;
				p = seg.get(low, pos);
				pq.emplace(p.first, p.second, low, pos);
				p = seg.get(pos + 1, high);
				pq.emplace(p.first, p.second, pos + 1, high);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
