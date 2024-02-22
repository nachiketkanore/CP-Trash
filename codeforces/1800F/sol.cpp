/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 22 February 2024 10:28:15 PM IST
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

int N;
vector<string> odd, even;

int solve(char forget) {
	vector<int> odd_mask, even_mask;
	for (const string& s : odd) {
		if (count(ALL(s), forget) == 0) {
			int mask = 0;
			for (char ch : s) {
				mask ^= 1 << (ch - 'a');
			}
			odd_mask.push_back(mask);
		}
	}
	for (const string& s : even) {
		if (count(ALL(s), forget) == 0) {
			int mask = 0;
			for (char ch : s) {
				mask ^= 1 << (ch - 'a');
			}
			even_mask.push_back(mask);
		}
	}
	int pairs = 0;
	sort(ALL(odd_mask));
	for (int mask : even_mask) {
		int want_mask = ((1 << 26) - 1) ^ mask;
		assert(want_mask >> (forget - 'a') & 1);
		want_mask ^= 1 << (forget - 'a');
		// pairs += count(ALL(odd_mask), want_mask);
		pairs += upper_bound(ALL(odd_mask), want_mask) - lower_bound(ALL(odd_mask), want_mask);
	}
	return pairs;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	F0R(i, N) {
		string s;
		cin >> s;
		if (sz(s) & 1)
			odd.push_back(s);
		else
			even.push_back(s);
	}
	int ans = 0;
	for (char forget = 'a'; forget <= 'z'; forget++) {
		ans += solve(forget);
	}
	cout << ans;

	return 0;
}
