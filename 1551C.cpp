/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 16 March 2022 11:55:16 AM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<string> A(N);
		for (auto& s : A) {
			cin >> s;
		}
		int ans = 0;
		for (char ch : "abcde") {
			int best = 0, tot = 0;
			vector<int> pos, neg;
			for (string& s : A) {
				int add = 0;
				for (char curr : s) {
					if (ch == curr)
						add += 1;
					else
						add -= 1;
				}
				if (add > 0)
					pos.push_back(add), tot += add;
				else
					neg.push_back(add);
			}
			best = pos.size();
			sort(neg.begin(), neg.end());
			while (!neg.empty() && tot + neg.back() > 0) {
				best++;
				tot += neg.back();
				neg.pop_back();
			}
			ans = max(ans, best);
		}
		cout << ans << '\n';
	}
	return 0;
}
