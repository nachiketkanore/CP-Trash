/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 12 February 2022 12:31:46 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	int n; cin >> n;
	vector<pair<int,int>> a(n);
	for (pair<int,int> &x: a) {
		cin >> x.first >> x.second;
	}
	auto solve = [&]() {
		int curr = 0, best = 0;
		for (pair<int,int> x: a) {
			int one = x.first, two = x.second;
			curr += one;
			best += two - curr;
		}
		return best;
	};
	int ans = -1ll * 1e18;
	sort(a.begin(), a.end(), [&](const pair<int,int> first, const pair<int,int> second) {
		return first < second;
	});
	ans = max(ans, solve());
	reverse(a.begin(), a.end());
	ans = max(ans, solve());
	sort(a.begin(), a.end(), [&](const pair<int,int> first, const pair<int,int> second) {
		return first > second;
	});
	ans = max(ans, solve());
	reverse(a.begin(), a.end());
	ans = max(ans, solve());
	sort(a.begin(), a.end(), [&](const pair<int,int> first, const pair<int,int> second) {
		return first.first - first.second < second.first - second.second;
	});
	ans = max(ans, solve());
	reverse(a.begin(), a.end());
	ans = max(ans, solve());
	sort(a.begin(), a.end(), [&](const pair<int,int> first, const pair<int,int> second) {
		return first.second - first.first < second.second - second.first;
	});
	ans = max(ans, solve());
	reverse(a.begin(), a.end());
	ans = max(ans, solve());
	sort(a.begin(), a.end(), [&](const pair<int,int> first, const pair<int,int> second) {
		return first.first + first.second < second.first + second.second;
	});
	ans = max(ans, solve());
	reverse(a.begin(), a.end());
	ans = max(ans, solve());
	sort(a.begin(), a.end(), [&](const pair<int,int> first, const pair<int,int> second) {
		return first.second + first.first > second.second + second.first;
	});
	ans = max(ans, solve());
	reverse(a.begin(), a.end());
	ans = max(ans, solve());
	cout << ans;
	return 0;
}
