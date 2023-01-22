#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	map<int, int> cnt;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int add;
		cin >> add;
		map<int, int> new_cnt;
		int ans = 0;
		map<int, int>::iterator it = cnt.begin();
		while (it != cnt.end()) {
			int val = it->first;
			int freq = it->second;
			int new_val = val + add;
			ans += abs(new_val) * freq;
			new_cnt[new_val] += freq;
			it++;
		}
		cout << ans << '\n';
		cnt = new_cnt;
	}
}
