/**
 *    Author: Nachiket Kanore
 *    Created: Monday 21 March 2022 09:14:01 PM IST
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;

//Use pair<int,int> to support multiset like features
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

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

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int Q; cin >> Q;
	for (int i = 1; i <= 500000; i++) {
		curr.insert(i);
	}
	while (Q--) {
		int X; cin >> X;
		int less = (int)curr.order_of_key(X);
		cout << less + 1 << '\n';
		curr.erase(X);
	}
	return 0;
}
