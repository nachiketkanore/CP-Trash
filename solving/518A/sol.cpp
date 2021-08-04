/*
Author: Nachiket Kanore
Created: Sunday 18 October 2020 12:23:36 AM IST
(ツ) It is impossible to feel grateful and depressed in the same moment.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s, t;
	cin >> s >> t;
	assert(s < t);
	int n = sz(s);

	for (int i = n - 1; ~i; i--) {
		string nxt = s;
		for (char ch = 'a'; ch <= 'z'; ch++) {
			char orig = nxt[i];
			nxt[i] = ch;
			if (nxt > s && nxt < t) {
				cout << nxt << '\n';
				return 0;
			}
			nxt[i] = orig;
		}
	}

	int i = 0;
	while (i < n && s[i] == t[i]) ++i;

	assert(i < n);
	assert(s[i] < t[i]);

	char nxt = (char)(s[i] + 1);
	s[i] = nxt;

	assert(s[i] <= 'z');
	FOR(j,i+1,n-1) s[j] = 'a';

	if (s < t) cout << s;
	else cout << "No such string\n";
}
