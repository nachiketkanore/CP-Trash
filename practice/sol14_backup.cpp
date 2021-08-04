#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include "bits/stdc++.h"

// #define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 4e5 + 5, inf = 1e9;

int n, I, a[N];
set<int> dist;
vector<int> all;

int getPower(int val) {
	// for (int i = 0; i < 31; i++) {
	// 	if (val <= (1LL << i)) return i;
	// }
	return ceil(log2(val));
	assert(false);
}

int getDistinct(int L, int R) {
	int rId = -1, lId = -1;
	int lo = 0, hi = sz(all) - 1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (all[mid] <= R) {
			rId = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	lo = 0, hi = sz(all) - 1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (all[mid] >= L) {
			lId = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}


	if (~lId) {
		assert(~rId);
		assert(rId >= lId);
		return rId - lId + 1;
	}
	return 0;
}

int countLessEqual(int val) {
	int lo = 1, hi = n;
	int ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (a[mid] <= val) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return ans;
}

int getChanges(int L, int R) {
	int chk = countLessEqual(R) - countLessEqual(L - 1);
	chk = n - chk;
	return chk;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> I;
	I <<= 3;
	FOR(i,1,n) {
		cin >> a[i];
		dist.insert(a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int x : dist) {
		all.push_back(x);
	}
	int ans = inf;
	for (int L : all) {
		// iterating on L
		// now BS on R
		int lo = L, hi = 1e9 + 5;
		int right = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int K = getDistinct(L, mid);
			int k = getPower(K);
			int mem = n * k;
			if (mem <= I) {
				right = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		if (~right) {
			int changes = getChanges(L, right);
			ans = min(ans, changes);
		}

	}
	assert(ans != inf);
	cout << ans;
}