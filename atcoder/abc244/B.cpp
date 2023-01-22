/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 20 March 2022 05:29:54 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char curr = 'E';
	int N;
	string T;
	cin >> N >> T;
	int x = 0, y = 0;
	for (char ch : T) {
		if (ch == 'S') {
			if (curr == 'E')
				++x;
			else if (curr == 'W')
				--x;
			else if (curr == 'N')
				++y;
			else if (curr == 'S')
				--y;
			else
				assert(0);
		} else {
			if (curr == 'E')
				curr = 'S';
			else if (curr == 'N')
				curr = 'E';
			else if (curr == 'S')
				curr = 'W';
			else if (curr == 'W')
				curr = 'N';
			else
				assert(0);
		}
	}
	cout << x << ' ' << y;
	return 0;
}
