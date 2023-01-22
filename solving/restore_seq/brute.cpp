#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
string s[N];
int l;
bool dfs(int p, int c, bool is) {
	if (c == l)
		return is;
	if (s[p][c] == '?') {
		int i, st = '0', lt = '9';
		if (!is)
			lt = s[p + 1][c];
		if (c == 0)
			st = '1';
		for (i = lt; i >= st; --i)
			if (dfs(p, c + 1, is | (i < s[p + 1][c]))) {
				s[p][c] = i;
				return 1;
			}
	} else {
		if (s[p][c] > s[p + 1][c] && !is)
			return 0;
		is |= s[p][c] < s[p + 1][c];
		return dfs(p, c + 1, is);
	}
	return 0;
}
int main() {
	int n, i;
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> s[i];
	for (i = 0; i < s[n - 1].size(); ++i)
		if (s[n - 1][i] == '?')
			s[n - 1][i] = '9';
	for (i = n - 2; i >= 0; --i) {
		if (s[i].size() > s[i + 1].size()) {
			cout << "NO\n";
			return 0;
		}
		l = s[i].size();
		if (!dfs(i, 0, s[i].size() < s[i + 1].size())) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (i = 0; i < n; ++i)
		cout << s[i] << endl;
}
