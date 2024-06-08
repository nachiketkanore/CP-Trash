/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 08 June 2024 05:12:13 PM IST
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

struct BIT {
	int N;
	vector<int> bit;

	void init(int n) {
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val) {
		while (idx <= N) {
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	void updateMax(int idx, int val) {
		while (idx <= N) {
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int pref(int idx) {
		int ans = 0;
		while (idx > 0) {
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r) {
		return pref(r) - pref(l - 1);
	}

	int prefMax(int idx) {
		int ans = -2e9;
		while (idx > 0) {
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
} counter, summer;

const int MAX_N = 4e5 + 5;
int N, A[MAX_N], B[MAX_N];

void compress() {
	vector<int> values;
	FOR(i, 1, N) values.push_back(A[i]);
	sort(ALL(values));
	FOR(i, 1, N) B[i] = lower_bound(ALL(values), A[i]) - values.begin() + 1;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	FOR(i, 1, N) cin >> A[i];

	compress();

	counter.init(N + 4);
	summer.init(N + 4);

	int answer = 0;

	FOR(i, 1, N) {
		counter.update(B[i], 1);
		summer.update(B[i], A[i]);

		int cnt = counter.pref(B[i]);
		int sum = summer.pref(B[i]);

		answer += cnt * A[i] - sum;
	}

	cout << answer << '\n';

	return 0;
}
