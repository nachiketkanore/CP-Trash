/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 25 September 2022 08:57:45 PM IST
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

void solve() {
	string S, other;
	cin >> S;
	const int N = S.size();
	string one;
	multiset<char> two;
	vector<int> freq(10);
	for (char ch : S)
		freq[ch - '0']++;
	int want = 0;
	int i = 0;
	while (i < N) {
		while (want < 10 && freq[want] == 0) {
			want++;
		}
		if (sz(two) && *two.begin() - '0' < want) {
			one += *two.begin();
			two.erase(two.find(*two.begin()));
			continue;
		}
		if (S[i] - '0' == want) {
			one += S[i];
		} else {
			char add = min('9', (char)(S[i] + 1));
			two.insert(add);
		}
		freq[S[i] - '0']--;
		i++;
	}
	for (char ch : two) {
		one += ch;
	}
	cout << one << '\n';
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
