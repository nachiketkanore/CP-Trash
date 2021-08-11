/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 11 August 2021 01:28:20 PM IST
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

struct DSU {
	int N;
	vector<int> par;
	DSU(int N): N(N) {
		par = vector<int> (N);
		F0R (i,N) par[i] = i;
	}
	int find(int u) {
		if (u == par[u]) return u;
		return par[u] = find(par[u]);
	}
	bool unite(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		par[u] = v;
		return true;
	}
};

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N, K; string S;
		cin >> N >> K >> S;
		DSU dsu(N);
		F0R (i,K) {
			for (int j = i; j < N; j += K) {
				if (j + K < N)
					dsu.unite(j, j + K);
			}
		}
		int L = 0, R = N - 1;
		while (L < R) {
			dsu.unite(L++, R--);
		}
		vector<vector<int>> comps(N);
		F0R (i,N) comps[dsu.find(i)].push_back(i);
		int ans = 0;
		F0R (i,N) {
			const vector<int> &comp = comps[i];
			if (!sz(comp)) continue;
			vector<int> freq(26, 0);
			int mx = 0;
			for (int idx: comp) {
				freq[S[idx]-'a']++;
				cmax(mx, freq[S[idx]-'a']);
			}
			ans += sz(comp) - mx;
		}
		cout << ans << '\n';
	}
}
