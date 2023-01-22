#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> alive(n, 1);
	int id = 0;
	int player = 0;

	while (1) {
		int next_player = -1;
		int next_id = (id + 1) % sz(s);
		for (int i = player + 1; i < n; i++) {
			if (alive[i]) {
				next_player = i;
				break;
			}
		}
		if (next_player == -1) {
			for (int i = 0; i < player; i++) {
				if (alive[i]) {
					next_player = i;
					break;
				}
			}
		}
		if (next_player == -1) {
			cout << player + 1 << '\n';
			return 0;
		}

		if (s[id] == 'a') {
			player = next_player;
		} else {
			alive[player] = 0;
			player = next_player;
		}

		player = next_player;
		id = next_id;
	}
}