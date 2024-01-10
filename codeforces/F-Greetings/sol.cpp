/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 10 January 2024 04:06:56 PM IST
 **/
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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

// Use pair<int,int> to support multiset like features
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> oset;

oset curr;

/*
1. Number of elements strictly greater than a[i]
int cnt = sz(curr) - (int)curr.order_of_key({a[i]+1,0});

2. Number of elements strictly less than a[i]
int cnt = (int)curr.order_of_key({a[i],i});

3. Use insert like this : curr.insert({a[id], id});

4. Finding the k -th smallest element in the set using * because
	find_by_order returns an iterator
	auto k-th_smallest_value =  *(o_set.find_by_order(k - 1))
	It is (k - 1) since it uses zero indexes

5. Erasing : curr.erase({a[i], i});
*/

void brute() {
	int N, ans = 0;
	cin >> N;
	int A[N], B[N];
	F0R(i, N) cin >> A[i] >> B[i];
	F0R(i, N) F0R(j, N) if (A[j] < A[i] && B[i] < B[j]) ans++;
	cout << ans << '\n';
}

void solve() {
	int N, ans = 0;
	cin >> N;
	vector<pair<int, int>> A(N);
	F0R(i, N) cin >> A[i].first >> A[i].second;
	sort(ALL(A));

	curr.clear();
	int idx = 0;
	for (auto [l, r] : A) {
		int cnt_greater = sz(curr) - (int)curr.order_of_key({ r + 1, 0 });
		ans += cnt_greater;
		curr.insert({ r, idx++ });
	}
	cout << ans << '\n';
}
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
