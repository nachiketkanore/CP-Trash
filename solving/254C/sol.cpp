/*
Author: Nachiket Kanore
Created: Wednesday 14 October 2020 02:22:55 PM IST
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s, t;
	cin >> s >> t;

	for (char ch : s) {
		have[ch - 'A']++;
	}

	for (char ch : t) {
		want[ch - 'A']++;
	}

	for (int i = 0; i < n; i++) {
		pos[s[i] - 'A'].push_back(i);
	}

	for (int i = 0; i < 26; i++) {
		reverse(pos[i].begin(), pos[i].end());
	}

	for (int i = 0; i < n; i++) {
		if (have[s[i] - 'A'] == want[s[i] - 'A'])  continue;
		if(have[s[i] - 'A'] > want[s[i] - 'A']) continue;
		
		for (char ch = 'A'; ch <= 'Z'; ch++)
	}

}
