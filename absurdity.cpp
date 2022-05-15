/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 15 May 2022 05:33:00 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 2e5 + 5;
int N, K, A[_];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	FOR(i, 1, N) {
		cin >> A[i];
		A[i] += A[i - 1];
	}
	set<pair<int, int>> b_sums;
	FOR(start_b, 1, N) {
		int end_b = start_b + K - 1;
		if (end_b <= N) {
			int sum_b = A[end_b] - A[start_b - 1];
			b_sums.insert({ sum_b, start_b });
		}
	}
	vector<array<int, 3>> answers;
	FOR(end_a, 1, N) {
		int start_b = end_a, end_b = start_b + K - 1;
		if (end_b <= N) {
			int sum_b = A[end_b] - A[start_b - 1];
			b_sums.erase(make_pair(sum_b, start_b));
		}
		int start_a = end_a - K + 1;
		if (start_a >= 1) {
			int sum_a = A[end_a] - A[start_a - 1];
			if (b_sums.empty())
				continue;
			auto [mx, _] = *b_sums.rbegin();
			auto [max_b, id_b] = *b_sums.lower_bound(make_pair(mx, 0));
			assert(max_b == mx);
			int get = sum_a + max_b;
			answers.push_back({ get, start_a, id_b });
		}
	}
	sort(ALL(answers));
	while (sz(answers) >= 2) {
		const int M = sz(answers);
		if (answers[M - 1][0] == answers[M - 2][0]) {
			answers.pop_back();
		} else {
			break;
		}
	}
	cout << answers.back()[1] << ' ' << answers.back()[2] << '\n';
	return 0;
}
