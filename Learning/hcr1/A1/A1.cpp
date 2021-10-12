/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 12 September 2021 01:02:51 AM IST
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
#include <set>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

bool can_take(set<char> f, char add) {
	f.insert(add);
	if (f.count('O') && f.count('X'))
		return false;
	return true;
}

void solve() {
	int N; string S;
	cin >> N >> S;
	int parts = 0;
	for (int i = 0; i < N; ) {
		int j = i;
		set<char> have;
		while (j < N && can_take(have, S[j])) {
			have.insert(S[j]);
			j++;
		}
		i = j;
		parts++;
	}
	assert(parts > 0);
	cout << --parts << '\n';
}

int32_t main() {
	int T;
	cin >> T;
	FOR (i,1,T) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
