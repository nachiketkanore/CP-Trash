#include "bits/stdc++.h"

#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 1e6 + 5, inf = 8e8;

int n, a[N];
array<int, 3> vals[N];

void compress(int arr[]) {
	vector<int> all;

	FOR(i, 1, n) all.push_back(arr[i]);
	sort(all.begin(), all.end());

	FOR(i, 1, n) arr[i] = lower_bound(all.begin(), all.end(), arr[i]) - all.begin(), ++arr[i];
}

class segTree {

	private:
	int n;
	vector<int> st;

	public:
	// Keeping it 1-based
	void init(int _n) {
		n = _n;
		st = vector<int>(4 * n + 5, 0);
	}

	void pointUpdate(int node, int tl, int tr, int pos, int val) {
		if (tl == tr) {
			st[node] = max(st[node], val);
		} else {
			int mid = (tl + tr) / 2;
			if (pos <= mid)
				pointUpdate(2 * node, tl, mid, pos, val);
			else
				pointUpdate(2 * node + 1, mid + 1, tr, pos, val);
			st[node] = max(st[2 * node], st[2 * node + 1]); // operation
		}
	}

	int rangeQuery(int node, int tl, int tr, int l, int r) {
		if (l > r)
			return -inf; // handle this value carefully
		if ((l == tl) && (r == tr))
			return st[node];
		int mid = (tl + tr) / 2;
		int left_ans = rangeQuery(2 * node, tl, mid, l, min(r, mid));
		int right_ans = rangeQuery(2 * node + 1, mid + 1, tr, max(l, mid + 1), r);
		return max(left_ans, right_ans); // operation
	}

	void update(int pos, int val) {
		pointUpdate(1, 1, n, pos, val);
	}

	int query(int l, int r) {
		r = min(r, n);
		return rangeQuery(1, 1, n, l, r);
	}

} rangeMax;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	FOR(i, 1, n) cin >> a[i];
	compress(a);
	FOR(i, 1, n) vals[i][0] = a[i];

	FOR(i, 1, n) cin >> a[i];
	compress(a);
	FOR(i, 1, n) vals[i][1] = a[i];

	FOR(i, 1, n) cin >> a[i];
	compress(a);
	FOR(i, 1, n) vals[i][2] = a[i];

	rangeMax.init(N);

	sort(vals + 1, vals + n + 1);
	reverse(vals + 1, vals + n + 1);

	int ans = 0;

	int j = 1;
	for (int i = 1; i <= n; i = j) {
		while (j <= n && vals[i][0] == vals[j][0])
			++j;
		// Now we have valid condition for a[i] > a[j]
		for (int k = i; k < j; k++) {
			// Now b[i] could be anything between [ b[id] + 1, ... , inf ]
			// So, for each of them we find max(c[]) such that max(c[]) could become > c[id]
			int max_c_for_all_valid_b = rangeMax.query(vals[k][1] + 1, inf);
			if (max_c_for_all_valid_b > vals[k][2])
				++ans;
		}

		// It's imp to update values after checking to avoid overcounting
		for (int k = i; k < j; k++) {
			rangeMax.update(vals[k][1], vals[k][2]);
		}
	}

	cout << ans;
}