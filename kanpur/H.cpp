/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 19 August 2021 05:59:39 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <set>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		string S;
		cin >> S;
		set<char> want(ALL(S));
		const int N = S.size();
		vector<vector<int>> pos(26);
		vector<vector<int>> pref(26, vector<int> (N));
		F0R (i,N) {
			pref[S[i]-'a'][i]++;
			F0R (ch,26) {
				if (i) pref[ch][i] += pref[ch][i-1];
			}
		}
		F0R (i,N) pos[S[i]-'a'].push_back(i);

		string ans;
		set<char> left;
		vector<int> taken(26, 0);
		int id = 0;

		auto have = [&](int ch, int L, int R) {
			return pref[ch][R] - (L ? pref[ch][L - 1]: 0);
		};

		auto can_take = [&](int from) {
			set<char> right;
			F0R (ch,26) if (have(ch, from, N-1)) right.insert((char)(ch + 'a'));
			set<char> tot;
			for (auto it: left) tot.insert(it);
			for (auto it: right) tot.insert(it);
			return tot == want;
		};

		while (1) {
			bool found = false;
			for (char ch = 'a'; ch <= 'z'; ch++) {
				int get = lower_bound(ALL(pos[ch-'a']), id) - pos[ch-'a'].begin();
				if (get == sz(pos[ch-'a'])) continue;
				get = pos[ch-'a'][get];
				if (can_take(get)) {
					ans += ch;
					id = get + 1;
					found = true;
					left.insert(ch);
					break;
				}
			}
			if (!found) break;
			if (left == want) break;
		}

		cout << ans << '\n';
	}
}
