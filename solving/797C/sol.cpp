/*
Author: Nachiket Kanore
Created: Tuesday 27 October 2020 03:41:24 PM IST
(ツ) Sooner or later, those who win are those who think they can.
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
	
	string s;
	cin >> s;

	string t, ans;
	char want = *min_element(s.begin(), s.end());
	vector<int> f(26,0);
	for (char ch : s) f[ch - 'a']++;

	for (char ch : s) {
		if (ch == want) {
			ans.push_back(ch);
			assert(f[ch - 'a'] > 0);	
		} else {
			t.push_back(ch);
		}

		while (sz(t) && t.back() <= want) {
			ans.push_back(t.back());
			t.pop_back();
		}

		f[ch - 'a']--;
		if (f[ch - 'a'] == 0) {
			FOR(x,0,25) if (f[x] > 0) {
				want = (char)('a' + x);
				break;
			}
		}
		
	}

	see(t);
	while (sz(t)) {
		ans.push_back(t.back());
		t.pop_back();
	}

	cout << ans << "\n";
}
