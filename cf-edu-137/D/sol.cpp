/**
 *    Author: Nachiket Kanore
 *    Created: Monday 17 October 2022 09:11:34 PM IST
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

int N;
string S;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	int id1 = 0;
	while (id1 < N && S[id1] != '1')
		++id1;

	if (id1 == N) {
		cout << "0\n";
		return 0;
	}

	S = S.substr(id1);
	N = sz(S);

	vector<int> z_pos;
	F0R(i, N) {
		if (S[i] == '0') {
			z_pos.push_back(i);
		}
	}

	if (z_pos.empty()) {
		cout << S << '\n';
		return 0;
	}

	int start = z_pos[0];
	string ans = S;

	auto get_OR = [](char a, char b) {
		if (a == '0' && b == '0')
			return '0';
		return '1';
	};

	auto better = [&](const string& T, const string& chk) {
		F0R(i, N) {
			if (T[i] == chk[i])
				continue;
			if (T[i] == '1' && chk[i] == '0')
				return true;
			else
				return false;
		}
		return false;
	};

	F0R(id, start) {
		string T = S;
		int j = start;
		int i = id;
		while (i < N && j < N) {
			T[j] = get_OR(S[i], S[j]);
			i++, j++;
		}
		if (better(T, ans)) {
			ans = T;
		}
	}

	cout << ans << '\n';

	return 0;
}
