/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 12 February 2022 12:47:42 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 5e5 + 5;
int a[N];

int32_t main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char ch; cin >> ch;
		a[i] = int(ch - '0');
	}
	auto ok = [&](int len) {
		int groups = 0;
		deque<int> window;
		bool found = false;
		for (int i = 0; i < len; i++) {
			if (window.empty()) {
				window.push_back(a[i]);
				if (a[i] == 0) ++groups;
			} else {
				if (window.back() == 1 && a[i] == 0) ++groups;
				window.push_back(a[i]);
			}
		}
		found |= groups <= k;
		for (int i = len; i < n; i++) {
			assert(!window.empty());
			if (window.back() == 1 && a[i] == 0) ++groups;
			window.push_back(a[i]);
			int first = window.front();
			window.pop_front();
			assert(!window.empty());
			if (first == 0 && window.front() == 1) --groups;
			found |= groups <= k;
		}
		return found;
	};
	int lo = 1, hi = n;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (ok(mid)) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	assert(~ans);
	cout << ans;
	return 0;
}
