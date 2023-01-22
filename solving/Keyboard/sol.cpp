#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char str[600000];
int low[26];
int upp[26];
int len;
int main() {
	int n, m, x;
	cin >> n >> m >> x;
	char keys[n + 1][m + 1];
	for (int i = 0; i < n; i++) {
		cin >> keys[i];
	}

	int stuff = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (keys[i][j] != 'S')
				low[keys[i][j] - 'a'] = 1;
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < m; l++) {
					if ((keys[i][j] == 'S') && keys[k][l] != 'S') {
						if ((i - k) * (i - k) + (j - l) * (j - l) <= x * x)
							upp[keys[k][l] - 'a'] = 1;
						stuff = 1;
					}
				}
			}
		}
	}
	cin >> len;
	cin >> str;
	int num = 0;

	for (int i = 0; i < len; i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			if (low[str[i] - 'a'] == 0) {
				cout << -1 << endl;
				return 0;
			}
		}
		if ('A' <= str[i] && str[i] <= 'Z') {
			if (low[str[i] - 'A'] == 0 || stuff == 0) {
				cout << -1 << endl;
				return 0;
			} else if (upp[str[i] - 'A'] == 0) {
				num++;
			}
		}
	}
	cout << num;
}