/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 11 February 2024 01:47:49 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int MAX = 1e6;
int N;
string A[MAX];

class TRIE {
	private:
	static const int ALPHABETS = 26;
	typedef struct node {
		node* bit[ALPHABETS];
		int cnt = 0;
	} * nodeptr;

	nodeptr root;

	public:
	TRIE() {
		root = new node();
	}

	void insert_reverse(string add) {
		reverse(ALL(add));
		nodeptr curr = root;
		for (char ch : add) {
			int currBit = ch - 'a';
			if (curr->bit[currBit] == nullptr)
				curr->bit[currBit] = new node();
			curr = curr->bit[currBit];
			curr->cnt++;
		}
	}

	int query(string val) {
		int ans = 0;
		nodeptr curr = root;
		for (char ch : val) {
			int nxt = ch - 'a';
			if (curr->bit[nxt] == nullptr)
				break;
			curr = curr->bit[nxt];
			ans += curr->cnt;
		}
		return ans;
	}
} trie;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int total = 0, common = 0;
	F0R(i, N) {
		cin >> A[i];
		total += sz(A[i]);
		trie.insert_reverse(A[i]);
	}
	total *= 2 * N;
	F0R(i, N) common += 2 * trie.query(A[i]);
	cout << (total - common) << '\n';

	return 0;
}
