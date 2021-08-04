/*
Author: Nachiket Kanore
Created: Thursday 03 December 2020 12:55:15 PM IST
(ツ) Remembering a wrong is like carrying a burden on the mind.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	// we win = a/b , we lose = (1-a/b)
	// he lose = (1-c/d)
	
	// Probability of winning:
	// Win at round 1: we win : a/b
	// Win at round 3: we lose, he lose, we win
	// Win at round 5: we lose, he lose, we lose, he lose, we win
	// Win at round 7: we lose, he lose, we lose, he lose, we lose, he lose, we win
	// Win at round 9: ..
	// Win at round 11: ..

	// Round 1: a/b
	// Round 3: (1-a/b) * (1-c/d) * a/b
	// Round 5: (1-a/b) * (1-c/d) * (1-a/b) * (1-c/d) * a/b
	// Round 7: (1-a/b) * (1-c/d) * (1-a/b) * (1-c/d) * (1-a/b) * (1-c/d) * a/b
	// Round 9: (1-a/b) * (1-c/d) * (1-a/b) * (1-c/d) * (1-a/b) * (1-c/d) * (1-a/b) * (1-c/d) * a/b
	// ...
	// Answer is sum over all probabilities

	using ld = long double;
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	ld ans = 0;

	ld we_lose_and_he_lose = (ld)(1-(ld)a/b) * (1-(ld)c/d);
	ld we_win = (ld)a/b;

	FOR (i,1,100000) {
		ans += we_win;
		we_win *= (ld) we_lose_and_he_lose;
	}
	printf("%0.8Lf\n", ans);
}
