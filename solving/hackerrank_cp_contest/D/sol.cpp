/*
Author: Nachiket Kanore
Created: Tuesday 08 December 2020 12:29:39 PM IST
(ツ) Accept challenges, so that you may feel the exhilaration of victory.
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
	

}

A * N + B * NOD(N) <= X
find max(N)
if we iterate over NOD(N), let it = Y 
	N <= (X - B * Y) / A
	largest N with SOD(N) = Y in above range