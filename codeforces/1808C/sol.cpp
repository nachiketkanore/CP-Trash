/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 11 February 2024 11:57:31 AM IST
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

const int N = 20;
string A, B;
int n, dp[N][2][2][2][1 << 10];

int go(int pos, bool bigA, bool smallB, bool nonzerotaken, int mask) {
	if (pos >= n) {
		int mn = -1, mx = -1;
		F0R(bit, 10) {
			if (mask >> bit & 1) {
				mn = mn == -1 ? bit : mn;
				mx = bit;
			}
		}
		return mx - mn;
	}

	int& ans = dp[pos][bigA][smallB][nonzerotaken][mask];
	if (~ans)
		return ans;
	ans = 10;
	for (int i = 0; i < 10; i++) {
		if (!bigA && i < A[pos] - '0')
			continue;
		if (!smallB && i > B[pos] - '0')
			continue;

		int nmask = mask;
		if (nonzerotaken || i > 0) {
			nmask |= 1 << i;
		}

		int get = go(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), nonzerotaken || i > 0, nmask);
		ans = min(ans, get);
	}
	return ans;
}

string answer;
void trace(int pos, bool bigA, bool smallB, bool nonzerotaken, int mask) {
	if (pos >= n)
		return;

	int ans = go(pos, bigA, smallB, nonzerotaken, mask);
	for (int i = 0; i < 10; i++) {
		if (!bigA && i < A[pos] - '0')
			continue;
		if (!smallB && i > B[pos] - '0')
			continue;

		int nmask = mask;
		if (nonzerotaken || i > 0) {
			nmask |= 1 << i;
		}

		int get = go(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), nonzerotaken || i > 0, nmask);
		if (get == ans) {
			answer.push_back((char)('0' + i));
			return trace(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), nonzerotaken || i > 0, nmask);
		}
	}
	assert(false);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		cin >> A >> B;
		reverse(A.begin(), A.end());
		while (sz(A) < sz(B))
			A.push_back('0');
		reverse(A.begin(), A.end());
		n = sz(B);
		int ans = 10;

		// compute min difference
		for (int i = 0; i < 10; i++) {
			if (i < A[0] - '0')
				continue;
			if (i > B[0] - '0')
				continue;

			int get = go(1, i > A[0] - '0', i < B[0] - '0', i != 0, i != 0 ? 1 << i : 0);
			ans = min(ans, get);
		}

		answer.clear();
		// trace the number with that difference
		for (int i = 0; i < 10; i++) {
			if (i < A[0] - '0')
				continue;
			if (i > B[0] - '0')
				continue;

			int get = go(1, i > A[0] - '0', i < B[0] - '0', i != 0, i != 0 ? 1 << i : 0);
			if (get == ans) {
				answer.push_back((char)('0' + i));
				trace(1, i > A[0] - '0', i < B[0] - '0', i != 0, i != 0 ? 1 << i : 0);
				break;
			}
		}
		reverse(ALL(answer));
		while (sz(answer) && answer.back() == '0')
			answer.pop_back();
		reverse(ALL(answer));
		cout << answer << '\n';
	}

	return 0;
}
