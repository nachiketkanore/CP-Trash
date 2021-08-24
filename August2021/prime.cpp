#include <bits/stdc++.h>
using namespace std;

int solve2(char* s, int n) {
	return 0;
}

int brute(int N) {
	int spf = -1;
	for (int d = 2; d * d <= N; d++) {
		if (N % d == 0) {
			return N - d;
		}
	}
	return 0;
}
int solve(int N) {
	if (N % 2 == 0) return N - 2;
	for (int i = 3; i * i <= N; i += 2) {
		if (N % i == 0) return N - i;
	}
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
	srand(time(0));
	int T = 100000;
	while (T--) {
		int N = rand() % 1000000 + 2;
		/* cout << N << " " << brute(N) << ' ' << solve(N) << endl; */
		assert(brute(N) == solve(N));
		cout << N  << " , OK " << (100000 - T) << '\n';
	}
	cout << solve(253) << '\n';
	char s[] = "6693581";
	cout << solve(s, 7);
}
