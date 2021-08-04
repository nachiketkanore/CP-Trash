/*
Author: Nachiket Kanore
Created: Wednesday 06 January 2021 05:20:24 PM IST
(ツ) When I dare to be powerful, to use my strength in the service of my vision, then it becomes less and less important whether I am afraid.
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
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
int dp[102][102][102];

class Solution {
private:
	const int inf = 1e9;
	int n;
	int a, b, c;
	string s;
	string answer;
	bool found = false;
public:
	Solution() {
		input();
		solve();
	}
	void input() {
		cin >> n;
		FOR (i,0,n) FOR (j,0,n) FOR (k,0,n) dp[i][j][k] = -1;
		cin >> a >> b >> c;
		assert(n == a+b+c);
		cin >> s;	s = " " + s;
	}

	bool win(char A, char B) {
		return (A == 'R' && B == 'S') || (A == 'P' && B == 'R') || (A == 'S' && B == 'P');
	}

	int go(int id, int i, int j, int k) {
		if (i > a || j > b || k > c) return -inf;
		if (id == n+1) {
			return (i == a && j == b && k == c ? 0 : -inf);
		}
		int &ans = dp[id][i][j];
		if (~ans) return ans;
		ans = -inf;
		for (char ch : "RPS") {
			int get = win(ch, s[id]) + go(id+1, i + (ch == 'R'), j + (ch == 'P'), k + (ch == 'S'));
			cmax(ans, get);
		}
		return ans;
	}

	void trace(int id, int i, int j, int k) {
		if (i > a || j > b || k > c) assert(false);
		if (id == n+1) {
			assert(i+j+k == n);
			return ;
		}
		int ans = go(id, i, j, k);
		for (char ch : "RPS") {
			int get = win(ch, s[id]) + go(id+1, i + (ch == 'R'), j + (ch == 'P'), k + (ch == 'S'));
			if (ans == get) {
				answer.push_back(ch);
				return trace(id+1, i + (ch == 'R'), j + (ch == 'P'), k + (ch == 'S'));
			}
		}
	}

	void solve() {
		int mx = go(1,0,0,0);
		if (mx >= (n + 1) / 2) {
			trace(1,0,0,0);
			found = true;
		}
	}
	~Solution() {
		if (found) {
			cout << "YES\n";
			cout << answer << '\n';
		} else {
			cout << "NO\n";
		}
	}
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) 
		Solution S;
}
