/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 24 August 2021 03:35:39 PM IST
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
#include <cstring>

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
	const int INF = 1e9;
	int T;
	cin >> T;
	while (T--) {
		string T;
		cin >> T;
		const int N = T.size();
		vector<int> last(26, -1), first(26, INF);
		int best = -1;
		F0R (i,N) {
			cmin(first[T[i]-'a'], i);
			cmax(best, first[T[i]-'a']);
			cmax(last[T[i]-'a'], i);
		}
		assert(~best);
		vector<pair<int,char>> pos;
		F0R (ch,26) {
			if (last[ch] == -1) continue;
			pos.push_back(make_pair(last[ch], (char)('a' + ch)));
		}
		sort(ALL(pos));
		string Td;

		{
			string S = T.substr(0, best + 1);
			int id = 0;
			while (sz(S)) {
				assert(id < sz(pos));
				auto [_, ch] = pos[id];
				Td += S;
				id++;
				string new_S;
				for (char c: S) {
					if (c^ch)
						new_S += c;
				}
				S = new_S;
			}
		}

		cout << T.substr(0, best + 1) << '\n';
		cout << Td << '\n';
		/* for (auto [id, ch]: pos) cout << id << ' ' << ch << '\n'; */
		
		if (T == Td) {
			string S = T.substr(0, best + 1);
			cout << S << ' ';
			for (const auto &[_, ch]: pos)
				cout << ch;
			cout << '\n';
		} else {
			cout << "-1\n";
		}
	}
}
