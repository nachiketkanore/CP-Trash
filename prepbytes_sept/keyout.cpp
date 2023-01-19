/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 11 September 2021 02:50:04 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

string maps[10];
string str;
vector<string> answers;
int N;

void init() {
	maps[0] = maps[1] = " ";
	maps[2] = "abc";
	maps[3] = "def";
	maps[4] = "ghi";
	maps[5] = "jkl";
	maps[6] = "mno";
	maps[7] = "pqrs";
	maps[8] = "tuv";
	maps[9] = "wxyz";
}

void go(int id, string curr) {
	if (id == N) {
		answers.push_back(curr);
		return;
	}

	int dig = str[id] - '0';
	for (char ch : maps[dig]) {
		go(id + 1, curr + ch);
	}
}

int32_t main() {
	init();
	int T;
	cin >> T;
	while (T--) {
		cin >> str;
		N = str.size();
		answers.clear();
		go(0, "");
		for (auto& it : answers) {
			reverse(ALL(it));
		}
		sort(ALL(answers));
		for (auto& it : answers) {
			reverse(ALL(it));
		}
		for (const string& ans : answers) {
			cout << ans << '\n';
		}
	}
}
