/*
Author: Nachiket Kanore
Created: Monday 26 October 2020 08:09:28 PM IST
(ツ) Reality does not conform to the ideal, but confirms it.
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
	
	int n;
	cin >> n;

	vector<int> a, b;

	FOR(i,1,n) {
		char ch;
		cin >> ch;
		a.push_back(ch - '0');
	}


	FOR(i,1,n) {
		char ch;
		cin >> ch;
		b.push_back(ch - '0');
	}

	int cnt = 0;

	FOR(i,0,n-1) {
		if (a[i] == b[i]) continue;
		if (i == 0 || i == n - 1) {
			cnt++;
			a[i] = b[i];
			continue;
		}
		if (i + 1 < n) {
			if (((!a[i]) == b[i]) && ((!a[i + 1]) == b[i + 1])) {
				// cout << a[i] << " " << a[i + 1] << "\n";
				// cout << b[i] << " " << b[i + 1] << "\n";
				a[i] = b[i];
				a[i + 1] = b[i + 1];
				cnt++;
				continue;
			}
		}
		
	}

	// cout << cnt << "\n";
	FOR(i,0,n-1) {
		cnt += a[i] != b[i];
	}

	see(a);
	see(b);

	cout << cnt << '\n';
}