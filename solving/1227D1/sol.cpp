/*
Author: Nachiket Kanore
Created: Monday 16 November 2020 04:58:00 PM IST
(ツ) Smile, breathe and go slowly.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
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

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

const int N = 2e5 + 5, inf = 1e18;

int n, a[N], b[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	FOR (i,1,n) {
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b + 1, b + n + 1, greater<int>());

	int Q;
	cin >> Q;
	while (Q--) {
		int len, pos;
		cin >> len >> pos;
		multiset<int> contains;
		FOR (i,1,len) {
			contains.insert(b[i]);
		}
		vector<int> sub;
		FOR (i,1,n) {
			if (contains.count(a[i])) {
				contains.erase(contains.find(a[i]));
				sub.push_back(a[i]);
			}
		}
		assert(sz(sub) == len);
		see(len, sub);
		cout << sub[--pos] << "\n";
	}
}
