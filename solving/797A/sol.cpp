/*
Author: Nachiket Kanore
Created: Tuesday 27 October 2020 01:03:06 PM IST
(ツ) God always takes the simplest way.
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

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	vector<int> PF;

	for (int d = 2; d * d <= n; d++) if (n % d == 0) {
		while (n % d == 0) {
			n /= d;
			PF.push_back(d);
		}
	}

	if (n > 1) PF.push_back(n);

	see(PF);

	if (sz(PF) < k) {
		cout << "-1\n";
	} else {
		while (sz(PF) > k) {
			int x = PF.back();
			PF.pop_back();
			PF.back() *= x;
		}
		assert(sz(PF) == k);
		for (int x : PF) 
			cout << x << " ";
	}
}
