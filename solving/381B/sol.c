#include <stdio.h>

int dp[205][205][205][3];

int ok(int a, int b, int c, int want) {
	if (a + b + c == 1) {
		if (want == 0 && a == 1)
			return 1;
		if (want == 1 && b == 1)
			return 1;
		if (want == 2 && c == 1)
			return 1;
		return 0;
	}
	int ans = dp[a][b][c][want];
	if (~ans)
		return ans;
	ans = 0;

	if (a > 0 && b > 0)
		ans |= ok(a - 1, b - 1, c + 1, want);
	if (b > 0 && c > 0)
		ans |= ok(a + 1, b - 1, c - 1, want);
	if (a > 0 && c > 0)
		ans |= ok(a - 1, b + 1, c - 1, want);

	if (a >= 2)
		ans |= ok(a - 1, b, c, want);
	if (b >= 2)
		ans |= ok(a, b - 1, c, want);
	if (c >= 2)
		ans |= ok(a, b, c - 1, want);

	return dp[a][b][c][want] = ans;
}

int main() {
	int n, a = 0, b = 0, c = 0;
	scanf("%d", &n);
	char s[n];
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B')
			a++;
		else if (s[i] == 'G')
			b++;
		else
			c++;
	}
	for (int i = 0; i <= 200; i++)
		for (int j = 0; j <= 200; j++)
			for (int k = 0; k <= 200; k++)
				for (int l = 0; l <= 2; l++)
					dp[i][j][k][l] = -1;
	if (ok(a, b, c, 0))
		putchar('B');
	if (ok(a, b, c, 1))
		putchar('G');
	if (ok(a, b, c, 2))
		putchar('R');
}