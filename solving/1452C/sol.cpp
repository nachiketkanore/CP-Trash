/*
Author: Nachiket Kanore
Created: Thursday 19 November 2020 08:23:36 PM IST
(ツ) To be great is to be misunderstood.
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

int get(string s) {
	string t;

	for (char ch : s) {
		if (t.empty()) t.push_back(ch);
		else {
			if (ch == '(' || ch == '[') t.push_back(ch);
			else {
				if (ch == ')' && t.back() == '(') t.pop_back();
				else if (ch == ']' && t.back() == '[') t.pop_back();
				else t.push_back(ch);
			}
		}
	}
	int len = sz(s) - sz(t);
	assert(len % 2 == 0);
	return (len / 2);
}

void solve() {
	string s;
	cin >> s;

	string one, two;

	for (char ch : s) {
		if (ch == '(' || ch == ')') one.push_back(ch);
		else two.push_back(ch);
	}

	int c1 = get(one);
	int c2 = get(two);
	cout << (c1 + c2) << "\n";

	
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;
	while (T--) solve();
}
