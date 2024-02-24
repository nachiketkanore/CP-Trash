/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 24 February 2024 12:04:26 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int long long
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int _ = 1e5 + 5;
int N, K, L, A[_], P[_], ans;

int negatives(vector<int> neg, int k) {
	sort(ALL(neg));
	for (int& x : neg) {
		if (k > 0)
			x *= -1, --k;
	}
	return accumulate(ALL(neg), 0ll);
}

int positives(vector<int> pos, int k) {
	sort(ALL(pos));
	reverse(ALL(pos));
	for (int& x : pos) {
		if (k > 0)
			x *= -1, --k;
	}
	return accumulate(ALL(pos), 0ll);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// not sure about this

	cin >> N >> L;
	FOR(i, 1, N) {
		cin >> A[i];
		P[i] = A[i] + P[i - 1];
	}
	cin >> K;

	int possum = 0, negsum = 0;

	auto add = [&](int val) {
		if (val >= 0)
			possum += val;
		else
			negsum += val;
	};
	auto remove = [&](int val) {
		if (val >= 0)
			possum -= val;
		else
			negsum -= val;
	};

	vector<array<int, 4>> info1, info2;

	FOR(i, 1, L) {
		add(A[i]);
	}

	info1.push_back({ possum, negsum, 1, L });
	info2.push_back({ negsum, possum, 1, L });

	FOR(i, L + 1, N) {
		add(A[i]);
		remove(A[i - L]);
		info1.push_back({ possum, negsum, i - L + 1, i });
		info2.push_back({ negsum, possum, i - L + 1, i });
	}

	auto check = [&](array<int, 4> chk) {
		auto [_, __, from, to] = chk;
		// see("checking", from, to);
		vector<int> pos, neg;
		int tot = 0, possum = 0, negsum = 0;
		FOR(j, from, to) {
			tot += A[j];
			if (A[j] >= 0) {
				pos.push_back(A[j]);
				possum += A[j];
			} else {
				neg.push_back(A[j]);
				negsum += A[j];
			}
		}
		int best = abs(tot);
		best = max(best, abs(possum + negatives(neg, K)));
		best = max(best, abs(negsum + positives(pos, K)));

		ans = max(ans, best);
	};

	auto repeat_check = [&](vector<array<int, 4>> info) {
		int id = 0;
		while (id + 1 < sz(info) && info[id + 1][0] == info[id][0])
			id++;
		check(info[0]), check(info[id]); // check 1

		id = sz(info) - 1;
		while (id - 1 >= 0 && info[id - 1][0] == info[id][0])
			--id;
		check(info.back()), check(info[id]); // check 2
	};

	sort(ALL(info1));
	repeat_check(info1);
	sort(ALL(info1), [&](array<int, 4> one, array<int, 4> two) { return abs(one[0]) + abs(one[1]) > abs(two[0]) + abs(two[1]); });
	repeat_check(info1);

	sort(ALL(info2));
	repeat_check(info2);
	sort(ALL(info2), [&](array<int, 4> one, array<int, 4> two) { return abs(one[0]) + abs(one[1]) > abs(two[0]) + abs(two[1]); });
	repeat_check(info2);

	cout << ans;

	return 0;
}
