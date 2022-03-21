/**
 *    Author: Nachiket Kanore
 *    Created: Monday 21 March 2022 09:07:30 PM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int _ = 5e5 + 5;
int val[_];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N; cin >> N;
	string S; cin >> S; S = "$" + S;
	map<char, int> pos;
	for (int i = 1; i <= N; i++) {
		if (pos.count(S[i])) {
			val[i] = pos[S[i]];
		} else {
			val[i] = i;
			pos[S[i]] = i;
		}
		val[i] += val[i - 1];
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int L, R;
		cin >> L >> R;
		cout << val[R] - val[L - 1] << '\n';
	}
	return 0;
}
