#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int damagingActions(int N, vector<int> actions, vector<int> damage) {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, damage[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (actions[i] + actions[j] > 3)
				continue;
			ans = max(ans, damage[i] + damage[j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (actions[i] + actions[j] + actions[k] > 3)
					continue;
				ans = max(ans, damage[i] + damage[j] + damage[k]);
			}
		}
	}
	return ans;
}

int main() {
	int N = 8;
	vector<int> actions = { 1, 2, 1, 3, 1, 2, 1, 1 };
	vector<int> damage = { 1, 1, 1, 1, 1, 1, 1, 1 };
	cout << damagingActions(N, actions, damage) << '\n';
}
