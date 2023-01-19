/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 01 September 2021 01:30:49 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

int32_t main() {
	int N, K, turn = 1;
	cin >> N >> K;
	set<int> idx;
	set<pair<int, int>> vals;
	vector<int> answer(N + 1, -1), A(N + 1);
	FOR(i, 1, N) {
		cin >> A[i];
		idx.insert(i);
		vals.insert(make_pair(A[i], i));
	}
	while (!vals.empty()) {
		auto [mx, mx_id] = *vals.rbegin();
		vals.erase(*vals.rbegin());
		vector<int> curr;
		// remove k max indices < mx_id
		int rem = K;
		while (rem > 0) {
			auto it = idx.lower_bound(mx_id);
			if (it == idx.begin())
				break;
			--it;
			--rem;
			int id = *it;
			idx.erase(id);
			curr.push_back(id);
			vals.erase(make_pair(A[id], id));
		}

		// remove k min indices > mx_id
		rem = K;
		while (rem > 0) {
			auto it = idx.upper_bound(mx_id);
			if (it == idx.end())
				break;
			--rem;
			int id = *it;
			idx.erase(id);
			curr.push_back(id);
			vals.erase(make_pair(A[id], id));
		}

		// remove mx_id from idx
		idx.erase(mx_id);
		curr.push_back(mx_id);
		for (int cid : curr) {
			answer[cid] = turn;
		}
		if (turn == 1)
			turn = 2;
		else
			turn = 1;
	}
	FOR(i, 1, N) {
		assert(~answer[i]);
		cout << answer[i];
	}
}
