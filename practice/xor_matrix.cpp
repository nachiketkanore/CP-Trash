/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 11 August 2021 12:13:51 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

struct Trie {
	struct node {
		node* to[2];
		node() {
			to[0] = NULL;
			to[1] = NULL;
		}
	};
	node* root;
	Trie() {
		root = new node();
		this->add(0);
	}
	void add(int u) {
		node* curr = root;
		for (int i = 32; i >= 0; i--) {
			int bit = (u >> i & 1LL);
			if (curr->to[bit] == NULL)
				curr->to[bit] = new node();
			curr = curr->to[bit];
		}
	}
	int get_max_with(int u) {
		node* curr = root;
		int best = 0;
		for (int i = 32; i >= 0; i--) {
			int bit = (u >> i & 1ll) ^ 1;
			if (curr->to[bit]) {
				best |= 1ll << i;
				curr = curr->to[bit];
			} else {
				assert(curr->to[!bit]);
				curr = curr->to[!bit];
			}
		}
		return best;
	}
} First, Second;

int32_t main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N + 1), B(M + 1);
	FOR(i, 1, N) cin >> A[i];
	FOR(i, 1, M) cin >> B[i];
	int ans = 0;
	FOR(i, 1, M) {
		int curr = 0;
		FOR(j, i, M) {
			curr ^= B[j];
			First.add(curr);
		}
	}
	FOR(i, 1, N) {
		int curr = 0;
		FOR(j, i, N) {
			curr ^= A[j];
			Second.add(curr);
		}
	}

	FOR(i, 1, M) {
		int curr = 0;
		FOR(j, i, M) {
			curr ^= B[j];
			if ((j - i + 1) % 2 == 1)
				cmax(ans, curr);
			else
				cmax(ans, Second.get_max_with(curr));
		}
	}
	FOR(i, 1, N) {
		int curr = 0;
		FOR(j, i, N) {
			curr ^= A[j];
			if ((j - i + 1) % 2 == 1)
				cmax(ans, curr);
			else
				cmax(ans, First.get_max_with(curr));
		}
	}
	cout << ans << '\n';
}
