#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int vowelStrings(vector<string>& words, int left, int right) {
		const int N = words.size();
		int answer = 0;
		set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
		for (int i = left; i <= right; i++) {
			if (vowels.count(words[i][0]) && vowels.count(words[i].back())) {
				++answer;
			}
		}
		return answer;
	}
};
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}

