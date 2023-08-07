#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
	string finalString(string s) {
		string ans;
		for (char ch : s) {
			if (ch == 'i') {
				reverse(ans.begin(), ans.end());
			} else {
				ans += ch;
			}
		}
		return ans;
	}
};
