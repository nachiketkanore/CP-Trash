/*
Author: Nachiket Kanore
Created: Tuesday 27 October 2020 04:46:55 PM IST
(ツ) Reviewing what you have learned and learning anew, you are fit to be a teacher.
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

const int N = 200 + 5, inf = 1e18;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

string s, t;

void NO() {
	cout << "No solution\n";
	exit(0);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	vector<string> ans;

	for (char ch : s) {
		if (ch == '@') {
			if (t.empty()) NO();
			else if (t.back() == '@') NO();
			t.push_back(ch);
		} else {
			if (t.empty()) t.push_back(ch);
			else {
				if (t.back() == '@') {
					t.push_back(ch);
					ans.push_back(t);
					t.clear();
				} else {
					t.push_back(ch);
				}
			}
		}
	}

	if (sz(ans) == 0 && sz(t) > 0) NO();

	see(t);
	see(ans);

	ans.back() += t;

	FOR(i,0,sz(ans)-1) {
		cout << ans[i] << ",\n"[i == sz(ans) - 1];
	}
}
