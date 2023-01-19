/*
Author: Nachiket Kanore
Created: Monday 26 October 2020 12:05:33 PM IST
(ツ) Wit lies in recognizing the resemblance among things which differ and the difference between things which are alike.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 20, inf = 1e18;

int dp[N][N];
string n;

int go(int id, int carry) {
	if (id == -1)
		return carry == 0;

	int& ans = dp[id][carry];
	if (~ans)
		return ans;
	ans = 0;

	int want = n[id] - '0';

	FOR(fours, 0, 6) FOR(sevens, 0, 6) FOR(zeros, 0, 6) if (fours + sevens + zeros == 6) {
		int sum = 4 * fours + 7 * sevens + 0 * zeros + carry;

		if (sum % 10 == want) {
			int next_carry = sum / 10;
			ans |= go(id - 1, next_carry);
		}
	}

	return ans;
}

vector<int> ret[20];

void trace(int id, int carry) {
	if (id == -1) {
		assert(!carry);
		return;
	}

	int ans = go(id, carry);
	assert(ans);

	int want = n[id] - '0';

	FOR(fours, 0, 6) FOR(sevens, 0, 6) FOR(zeros, 0, 6) if (fours + sevens + zeros == 6) {
		int sum = 4 * fours + 7 * sevens + 0 * zeros + carry;

		if (sum % 10 == want) {
			int next_carry = sum / 10;
			int get = go(id - 1, next_carry);

			if (get == ans) {

				int x = fours, y = sevens, z = zeros;

				while (x--)
					ret[id].push_back(4);
				while (y--)
					ret[id].push_back(7);
				while (z--)
					ret[id].push_back(0);

				return trace(id - 1, next_carry);
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		int len = sz(n);
		memset(dp, -1, sizeof(dp));

		if (go(len - 1, 0)) {

			FOR(i, 0, 19) ret[i].clear();
			trace(len - 1, 0);

			vector<int> answers(6, 0);

			FOR(col, 0, len - 1) {
				assert(sz(ret[col]) == 6);

				FOR(row, 0, 5) {
					answers[row] = answers[row] * 10 + ret[col][row];
				}
			}

			for (int x : answers)
				cout << x << " ";
			cout << "\n";

		} else {
			cout << "-1\n";
		}
	}
}
