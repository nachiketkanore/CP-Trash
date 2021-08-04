/*
Author: Nachiket Kanore
Created: Sunday 13 December 2020 11:40:20 AM IST
(ツ) Be as you wish to seem.
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

const int _ = 3002;

int N, S;
int a[_];

int go(int id, int len) {
	
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> S;
	FOR (i,1,N) cin >> a[i];
	cout << go(1,0) << "\n";
}
