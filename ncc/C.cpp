/**
 *    Author: Nachiket Kanore
 *    Created: Friday 23 July 2021 10:08:39 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int MOD = 1e9 + 7;

int countPairs(string bracks[], int num)
{
    unordered_map<int, int> open, close;
 
    int cnt = 0;
 
    // Traverse for all bracket sequences
    for (int i = 0; i < num; i++) {
 
        // Get the string
        string s = bracks[i];
 
        int l = s.length();
 
        // Counts the opening and closing required
        int op = 0, cl = 0;
 
        // Traverse in the string
        for (int j = 0; j < l; j++) {
 
            // If it is a opening bracket
            if (s[j] == '(')
                op++;
            else // Closing bracket
            {
 
                // If openings are there, then close it
                if (op)
                    op--;
                else // Else increase count of closing
                    cl++;
            }
        }
 
        // If requirements of openings
        // are there and no closing
        if (op && !cl)
            open[op]++;
 
        // If requirements of closing
        // are there and no opening
        if (cl && !op)
            close[cl]++;
 
        // Perfect
        if (!op && !cl)
            cnt++;
    }
 
    // Divide by two since two
    // perfect makes one pair
     cnt = cnt / 2;
 
    // Traverse in the open and find
    // corresponding minimum
    for (auto it : open)
        cnt += min(it.second, close[it.first]);
 
	cnt %= MOD;
    return cnt;
}

bool balanced(string s) {
	int d = 0;
	for (char ch : s) {
		if (ch == '(') ++d;
		else --d;
		if (d < 0) return false;
	}
	return d == 0;
}
int32_t main() {
	int n;
	cin >> n;
	string s[n];
	F0R (i,n) cin >> s[i];
	F0R (i,n) cout << s[i] << ' '; cout << endl;
	int ans = countPairs(s, n);
	cout << ans << "<<<\n";
	reverse(s, s + n);
	F0R (i,n) cout << s[i] << ' '; cout << endl;
	ans += countPairs(s, n);
	cout << ans << "<<<\n";
	ans %= MOD;
	F0R (i,n) ans += balanced(s[i]);
	ans %= MOD;
	cout << ans;
}
