#include <iostream>
using namespace std;

int solve2(char* s, int n) {
	return 0;
}

int solve(char* s, int n) {
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int left = 0, right = 0;
		int L = i, R = i + 1;
		int len = 0;
		while (L >= 0 && R < n) {
			left += s[L]-'0';
			right += s[R]-'0';
			len += 2;
			if (left == right) ans = max(ans, len);
			L--, R++;
		}
	}
	return ans;
}

int main() {
	char s[] = "6693581";
	cout << solve(s, 7);
}
