#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	int N, M;
	cin >> N >> M;
	int freq[M][26];
	memset(freq, 0, sizeof(freq));
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		assert((int)S.size() == M);
		for (int j = 0; j < M; j++) {
			freq[j][S[j] - 'A']++;
		}
	}
	int hamming_dist = 0;
	string answer;
	for (int j = 0; j < M; j++) {
		int most = -1, which = -1;
		for (int ch = 25; ch >= 0; ch--) {
			if (freq[j][ch] >= most) {
				most = freq[j][ch];
				which = ch;
			}
		}
		assert(~most && ~which);
		answer.push_back((char)('A' + which));
		hamming_dist += N - most;
	}
	cout << answer << '\n' << hamming_dist;
	return 0;
}
