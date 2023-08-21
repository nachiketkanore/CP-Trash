#include <bits/stdc++.h>
#define int int64_t
using namespace std;

class Solution {
	public:
	bool isAcronym(vector<string>& words, string s) {
		bool ok = (int)words.size() == (int)s.size();
		for (int i = 0; i < (int)words.size(); i++) {
			ok &= s[i] == words[i][0];
		}
		return ok;
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}

