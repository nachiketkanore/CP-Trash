/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 28 January 2024 02:16:20 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

void solve() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int& x : A)
		cin >> x;
	for (int& x : B)
		cin >> x;
	vector<pair<vector<int>, vector<int>>> groups = { { A, B } };

	auto get_counts = [](const vector<int>& vals, int bit) {
		int set = 0, unset = 0;
		for (int val : vals) {
			if (val >> bit & 1)
				++set;
			else
				++unset;
		}
		return make_pair(set, unset);
	};

	auto separate_vector = [](const vector<int>& vals, int bit) {
		vector<int> set, unset;
		for (int val : vals) {
			if (val >> bit & 1)
				set.push_back(val);
			else
				unset.push_back(val);
		}
		return make_pair(set, unset);
	};

	int answer = 0;
	for (int bit = 30; bit >= 0; --bit) {
		bool ok = true;
		for (const auto& [a, b] : groups) {
			auto [seta, unseta] = get_counts(a, bit);
			auto [setb, unsetb] = get_counts(b, bit);
			if (seta == unsetb && unseta == setb) {
			} else {
				ok = false;
				break;
			}
		}
		if (ok) {
			answer |= 1 << bit;
			vector<pair<vector<int>, vector<int>>> new_groups;
			for (const auto& [a, b] : groups) {
				auto [seta, unseta] = separate_vector(a, bit);
				auto [setb, unsetb] = separate_vector(b, bit);
				// assert(sz(seta) == sz(unsetb) && sz(unseta) == sz(setb));
				if (sz(seta))
					new_groups.push_back({ seta, unsetb });
				if (sz(setb))
					new_groups.push_back({ setb, unseta });
			}
			groups = new_groups;
		}
	}
	cout << answer << '\n';
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
