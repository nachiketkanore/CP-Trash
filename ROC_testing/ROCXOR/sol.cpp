/*
Author: Nachiket Kanore
Created: Wednesday 27 January 2021 12:46:53 PM IST
(ツ) People of mediocre ability sometimes achieve outstanding success because they don't know when to quit. Most men succeed because they are determined to.
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
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n, X;
		cin >> n >> X;
		vector<int> a(n);
		for (int& x : a)
			cin >> x;
		sort(ALL(a));

		vector<pair<int, int>> answers;

		for (int& x : a) {
			if (binary_search(ALL(a), X ^ x)) {
				answers.push_back({ min(x, X ^ x), max(x, X ^ x) });
			}
		}
		sort(ALL(answers));
		assert(sz(answers));
		cout << answers[0].first << ' ' << answers[0].second << '\n';
	}
}

/*
Statements :
My XOR:
Answer always possible ?
Multiple answers calculated on basis of same min.element eg ((2,10), (2,12)),
	What is answer ?

Triplet Groups:
Multiple possible answers?
Which one to print ? Mention

Road Trip: *
Overflow handled ? Answer under MOD ?
Very large product for large constraint
Corner cases?

Diffuse:
OK

Sum of Heights:
OK

Plus Minus Game:
OK but std problem


*/