/*
Author: Nachiket Kanore
Created: Sunday 18 October 2020 02:33:02 PM IST
(ツ) Focusing your life solely on making a buck shows a poverty of ambition. It asks too little of yourself. And it will leave you unfulfilled.
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

string one(string s, string other) {
	reverse(other.begin(), other.end());
	other += s;
	return other;
}

string two(string s, string other) {
	reverse(other.begin(), other.end());
	s += other;
	return s;
}

bool pal(string& s) {
	int l = 0, r = sz(s) - 1;
	bool ok = true;
	while (l < r && ok)
		ok &= s[l++] == s[r--];
	return ok;
}

void go(string s) {
	if (pal(s)) {
		cout << s << '\n';
		exit(0);
	}
	if (sz(s) > 20)
		return;

	int n = sz(s);

	for (int i = 1; i <= n - 2; i++) {
		string nxt1 = one(s, s.substr(1, i - 1 + 1));
		string nxt2 = two(s, s.substr(1, i - 1 + 1));
		go(nxt1);
		go(nxt2);
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = sz(s);

	for (int i = 1; i <= n - 2; i++) {
		string nxt1 = one(s, s.substr(1, i - 1 + 1));
		string nxt2 = two(s, s.substr(1, i - 1 + 1));
		go(nxt1);
		go(nxt2);
	}
}
