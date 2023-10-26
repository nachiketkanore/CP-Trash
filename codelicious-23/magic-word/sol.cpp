/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 26 October 2023 12:53:21 PM IST
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

int N, freq[26];

bool go(int id, string ans = "") {
	if (id == N) {
		cout << ans << '\n';
		return true;
	}

	F0R(take, 26) if (freq[take]) {
		const char ch = (char)(take + 'a');
		if (ans.empty() || (ch != ans.back())) {
			freq[take]--;
			if (go(id + 1, ans + ch)) {
				return true;
			}
			freq[take]++;
		}
	}
	return false;
}

void brute() {
	cin >> N;
	memset(freq, 0, sizeof(freq));
	F0R(i, N) {
		char ch;
		cin >> ch;
		freq[ch - 'a']++;
	}
	if (!go(0)) {
		cout << "-1\n";
	}
}

void solve() {
	int N;
	vector<int> freq(26);
	cin >> N;
	F0R(i, N) {
		char ch;
		cin >> ch;
		freq[ch - 'a']++;
	}

	vector<string> possibilities;

	F0R(start, 26) if (freq[start] > 0) {
		auto available = freq;
		string make;

		make += (char)(start + 'a');
		available[start]--;

		F0R(iter, N - 1) {
			bool found = false;
			for (char put = 'a'; put <= 'z'; put++) {
				if (put != make.back() && available[put - 'a'] > 0) {
					make += put;
					found = true;
					available[put - 'a']--;
					break;
				}
			}
			if (!found)
				break;
		}
		see((char)(start + 'a'), make);

		if (sz(make) == N) {
			possibilities.push_back(make);
		}
	}

	if (possibilities.empty()) {
		cout << "-1\n";
	} else {
		cout << *min_element(ALL(possibilities)) << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		// solve();
		brute();
	}

	return 0;
}
