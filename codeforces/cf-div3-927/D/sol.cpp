/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 18 February 2024 06:55:08 PM IST
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

int get_id(char ch) {
	if (ch == 'C')
		return 0;
	if (ch == 'D')
		return 1;
	if (ch == 'H')
		return 2;
	if (ch == 'S')
		return 3;
	assert(false);
	return -1;
}

void solve() {
	int N;
	cin >> N;
	char trump;
	cin >> trump;
	vector<string> cards[4];

	F0R(i, 2 * N) {
		string s;
		cin >> s;
		cards[get_id(s[1])].push_back(s);
	}

	vector<pair<string, string>> ans;

	int trump_id = get_id(trump);
	bool ok = true;

	F0R(id, 4) sort(ALL(cards[id]));

	F0R(id, 4) {
		if (id == trump_id)
			continue;
		while (sz(cards[id]) >= 2) {
			string b = cards[id].back();
			cards[id].pop_back();
			string a = cards[id].back();
			cards[id].pop_back();
			ans.push_back({ a, b });
		}
		if (sz(cards[id])) {
			if (sz(cards[trump_id])) {
				string b = cards[trump_id].back();
				cards[trump_id].pop_back();
				string a = cards[id].back();
				cards[id].pop_back();
				ans.push_back({ a, b });
			} else {
				ok = false;
			}
		}
	}

	F0R(id, 4) {
		if (id == trump_id) {
			while (sz(cards[id]) >= 2) {
				string b = cards[id].back();
				cards[id].pop_back();
				string a = cards[id].back();
				cards[id].pop_back();
				ans.push_back({ a, b });
			}
			if (sz(cards[id]))
				ok = false;
		}
	}

	if (ok) {
		for (auto [a, b] : ans) {
			cout << a << ' ' << b << '\n';
		}
	} else {
		cout << "IMPOSSIBLE\n";
	}
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
