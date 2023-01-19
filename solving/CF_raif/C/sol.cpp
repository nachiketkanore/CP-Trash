/*
Author: NK
Created: Saturday 17 October 2020 06:33:39 PM IST
(ツ) I think and that is all that I am.
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
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		string nxt;

		for (char ch : s) {
			if (nxt.empty())
				nxt.push_back(ch);
			else {
				if (nxt.back() == 'A' && ch == 'B')
					nxt.pop_back();
				else {
					nxt.push_back(ch);
				}
			}
		}

		s = nxt;
		nxt.clear();

		for (char ch : s) {
			if (nxt.empty())
				nxt.push_back(ch);
			else {
				if (nxt.back() == 'B' && ch == 'B')
					nxt.pop_back();
				else {
					nxt.push_back(ch);
				}
			}
		}

		cout << sz(nxt) << '\n';
	}
}
