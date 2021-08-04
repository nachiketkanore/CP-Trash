/*
Author: Nachiket Kanore
Created: Friday 11 December 2020 07:30:57 PM IST
(ツ) Happiness is the reward we get for living to the highest right we know.
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

int power(int a, int b, int mod) {
	int ret = 1;
	a %= mod;
	while (b) {
		if (b&1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int a;
	cin >> a;
	string b;
	cin >> b;

	const int mod = 1e9+7;
	const int cmod = mod-1;
	const int n = b.size();
	reverse(b.begin(), b.end());

	int ten = 1;
	int bmod = 0;

	for (int i = 0; i < n; i++) {
		bmod = (bmod + (b[i]-'0')*ten) % cmod;
		ten = (ten*10) % cmod;
	}

	cout << power(a, bmod, mod) << "\n";
}
