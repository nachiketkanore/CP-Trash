#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y) {
  if (Y.length() > X.length())
    swap(X, Y);
  int m = X.length(), n = Y.length();
  vector<vector<int>> c(2, vector<int>(n + 1, 0));
  int i, j;
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      if (X[i - 1] == Y[j - 1])
        c[1][j] = c[0][j - 1] + 1;
      else
        c[1][j] = max(c[1][j - 1], c[0][j]);
    }
    for (j = 1; j <= n; j++)
      c[0][j] = c[1][j];
  }
  return (c[1][n]);
}

int doublyStrings(string s) {
  string st = s;
  int ans = 0;
  for (int cp = 1; cp < st.size(); cp++) {
    string st1, st2;
    for (int i = 0; i < st.size(); i++) {
      if (i < cp)
        st1 += st[i];
      else
        st2 += st[i];
    }
    ans = max(ans, LCS(st1, st2));
  }
  return ans * 2;
}

int main() {
	cout << doublyStrings("singing") << '\n';
}
