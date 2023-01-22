#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

vector<int> pos[26], npos[26];

struct FenwickTree {
	vector<int> bit; // binary indexed tree
	int n;

	FenwickTree(int n) {
		this->n = n;
		bit.assign(n, 0);
	}

	FenwickTree(vector<int> a) : FenwickTree(a.size()) {
		for (size_t i = 0; i < a.size(); i++)
			add(i, a[i]);
	}

	int sum(int r) {
		int ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, int delta) {
		for (; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
	}
};

int inversions(vector<int>& a) {
	const int n = a.size();
	FenwickTree tree(n + 5);

	int ans = 0;

	for (int x : a) {
		int from = x + 1, to = n;
		ans += tree.sum(from, to);
		tree.add(x, 1);
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		pos[s[i] - 'a'].push_back(i);
	}

	reverse(s.begin(), s.end());

	for (int i = 0; i < n; i++) {
		npos[s[i] - 'a'].push_back(i);
	}

	vector<int> changed(n);

	for (int ch = 0; ch < 26; ch++) {
		sort(pos[ch].begin(), pos[ch].end());
		sort(npos[ch].begin(), npos[ch].end());
		assert(sz(pos[ch]) == sz(npos[ch]));

		for (int i = 0; i < sz(pos[ch]); i++) {
			changed[pos[ch][i]] = npos[ch][i];
		}
	}

	int ans = inversions(changed);
	cout << ans;
}