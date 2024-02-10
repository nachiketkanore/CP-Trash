/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 10 February 2024 11:04:55 AM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int MAX = 2e5 + 5;
int N, M, P;
vector<pair<int, int>> groups[MAX];

void coordinate_compress(vector<int>& A, vector<int>& B) {
	vector<int> values;
	for (int a : A)
		values.push_back(a);
	for (int b : B)
		values.push_back(b);
	sort(ALL(values));
	for (int& a : A)
		a = lower_bound(ALL(values), a) - values.begin() + 1;
	for (int& b : B)
		b = lower_bound(ALL(values), b) - values.begin() + 1;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// not optimal, will TLE

	cin >> N >> M >> P;
	vector<int> A(N), B(M);
	for (auto& a : A)
		cin >> a;
	for (auto& b : B)
		cin >> b;
	coordinate_compress(A, B);

	FOR(i, 1, N) groups[i % P].push_back({ A[i - 1], i });

	vector<int> freq(2 * N + 2);
	for (int b : B)
		freq[b]++;

	auto check = [&]() {
		bool ok = true;
		for (int f : freq)
			ok &= f == 0;
		return ok;
	};

	vector<int> positions;

	F0R(mod, P) {
		const auto& g = groups[mod];
		if (sz(g) < M)
			continue;
		const int len = sz(g);

		F0R(id, M) freq[g[id].first]--;
		if (check())
			positions.push_back(g[0].second);

		int rem_id = 0;
		for (int id = M; id < len; id++, rem_id++) {
			freq[g[rem_id].first]++;
			freq[g[id].first]--;
			if (check())
				positions.push_back(g[rem_id + 1].second);
		}
		while (rem_id < len) {
			freq[g[rem_id++].first]++;
		}
	}

	sort(ALL(positions));
	cout << sz(positions) << '\n';
	for (int pos : positions) {
		cout << pos << ' ';
	}

	return 0;
}
