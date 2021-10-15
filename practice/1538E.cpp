/**
 *    Author: Nachiket Kanore
 *    Created: Friday 15 October 2021 05:08:21 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>
#include <map>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

struct String {
	string val;
	int cnt;
	String(string val): val(val) {
		cnt = 0;
	}
	String operator + (const String& other) {
		String ret;

		return ret;
	}
};

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N; cin >> N;
		map<string, String> var;
		string last;
		F0R (i,N) {
			string x, sign, y;
			cin >> x >> sign >> y;
			last = x;
			if (sign == ":=") {
				// x = y
				var[x] = String(y);
			} else {
				assert(sign == "=");
				string z; cin >> sign >> z;
				// x = y + z
				var[x] = var[y] + var[z];
			}
		}
		cout << var[last].cnt << '\n';
	}
}
