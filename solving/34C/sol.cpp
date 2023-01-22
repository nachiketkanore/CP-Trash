/*
Author: Nachiket Kanore
Created: Friday 22 January 2021 11:29:31 AM IST
(ツ) Forgiveness does not change the past, but it does enlarge the future.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 2e5 + 5, inf = 1e18;

vector<int> split(const string& s) {
	vector<int> ret;
	const int n = s.size();
	for (int i = 0; i < n;) {
		assert(isdigit(s[i]));
		int val = s[i] - '0';
		int j = i + 1;
		while (j < n && s[j] != ',') {
			int dig = s[j] - '0';
			val = val * 10 + dig;
			j++;
		}
		ret.push_back(val);
		i = j + 1;
	}
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int> nums = split(s);
	see(nums);
	sort(ALL(nums));
	vector<int> new_nums;
	for (int x : nums)
		if (new_nums.empty() || new_nums.back() != x)
			new_nums.push_back(x);
	nums = new_nums;
	see(nums);

	const int n = nums.size();
	vector<pair<int, int>> ans_ranges;

	for (int i = 0; i < n;) {
		int first = nums[i];
		int last = nums[i];
		int j = i + 1;
		while (j < n && last + 1 == nums[j]) {
			last = nums[j];
			j++;
		}
		ans_ranges.push_back({ first, last });
		i = j;
	}

	see(ans_ranges);

	const int m = ans_ranges.size();
	for (int i = 0; i < m; i++) {
		int L = ans_ranges[i].first;
		int R = ans_ranges[i].second;
		if (L == R)
			cout << L;
		else
			cout << L << "-" << R;
		if (i != m - 1)
			cout << ",";
	}
}
