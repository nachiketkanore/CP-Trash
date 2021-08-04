#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimize("O1") 
#pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 82, inf = 1e6;

int n, a[N];
vector<int> positions;
int cnt0, cnt1;
int dp[2][N][N][N * (N - 1) / 2];

int go(int id, int rem, int zeros_put, bool which) {
	int ones_put = id - 1 - zeros_put;
	if (rem < 0 || zeros_put > cnt0 || ones_put > cnt1) 
		return inf;

	if (id == n + 1) 
		return (zeros_put == cnt0 && ones_put == cnt1 ? 0 : inf);

	int &ans = dp[which][id][zeros_put][rem];
	if (~ans)
		return ans;
	ans = inf;

	// Subarray consisting of 1s
	if (which) {
		for (int cnt = 1; cnt <= cnt1 - ones_put; cnt++) {
			ans = min(ans, go(id + cnt, rem, zeros_put, !which));
		}
	}
	// Subarray consisting of 0s
	else {
		// int L = zeros_put, R = L + cnt - 1;	// Positions in original array
		// int L_ = id, R_ = L_ + cnt - 1; // Positions in new array
		int L = zeros_put;
		int L_ = id;
		int req_ops = 0;

		for (int cnt = 1; cnt <= cnt0 - zeros_put; cnt++) {
			req_ops += abs(positions[L] - L_); 	
			int get = (cnt * (cnt - 1) / 2) + go(id + cnt, rem - req_ops, zeros_put + cnt, !which);
			ans = min(ans, get);
			L++, L_++;
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	FOR(i,1,n) {
		cin >> a[i];
		if (a[i] == 0) {
			positions.push_back(i);
		}
	}

	FOR(i,0,1) FOR(j,0,n+1) FOR(k,0,n+1) FOR(l,0,n*(n-1)/2+5) dp[i][j][k][l] = -1;

	cnt0 = sz(positions);
	cnt1 = n - cnt0;
	int tot = cnt0 * (cnt0 - 1) / 2;
	int SZ = n * (n - 1) / 2;

	for (int ops = 0; ops <= SZ; ops++) {
		cout << tot - min(go(1, ops, 0, 1), go(1, ops, 0, 0)) << ' ';
	}
	
	// cerr << "Time elapsed\t: " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";       
}

/*
	Trying to modify the cost function:
	# (pairs of 0s with atleast one 1 between them) = # (total pairs of 0s) - # (pairs of 0s with no 1 between)
	
	we'll count the # (pairs of 0s with no 1 between)
	infact we minimize this	to maximize the LHS

	let cnt0 = total zeros in given sequence
	for counting the pairs we need distance to i-th zero from original sequence and current consecutive zeroes to 
	add to the contribution
	
	Trying N^4 memory and N^5 time
	by calculating last state using for loop while transitioning
*/