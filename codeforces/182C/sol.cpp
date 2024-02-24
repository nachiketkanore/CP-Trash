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
int N, K, L, A[_];

struct Window {
	multiset<int> others;
	multiset<int> negatives; // stores k smallest negative numbers in the range
	int negsum = 0;
	int k; // k value in the above comment
	Window(int k) : k(k) {
	}
	void add(int val) {
		negatives.insert(val);
		negsum += val;
		while (sz(negatives) > k) {
			auto last = --negatives.end(); // put largest from negatives to others
			negsum -= *last;
			others.insert(*last);
			negatives.erase(last);
		}
	}
	void remove(int val) {
		auto it = others.find(val); // first check if it present in others
		if (it != others.end()) {
			others.erase(it);
			return;
		}
		it = negatives.find(val);
		assert(it != negatives.end());
		negsum -= val;
		negatives.erase(it);
		while (sz(negatives) < k && sz(others)) { // we may need to put an element from other to negatives to adjust the removal, we add the smallest from others to it
			auto it = others.begin();
			negatives.insert(*it);
			negsum += *it;
			others.erase(it);
		}
	}
};

int solve() {
	Window window(K);
	int tot = 0;
	auto add = [&](int val) {
		if (val < 0)
			window.add(val);
		tot += val;
	};
	auto remove = [&](int val) {
		if (val < 0)
			window.remove(val);
		tot -= val;
	};
	FOR(i, 1, L) add(A[i]);

	int best = tot - 2 * window.negsum;

	FOR(i, L + 1, N) {
		add(A[i]);
		remove(A[i - L]);
		best = max(best, tot - 2 * window.negsum);
	}
	return best;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	FOR(i, 1, N) cin >> A[i];
	cin >> K;

	int ans = solve();
	FOR(i, 1, N) A[i] *= -1;
	ans = max(ans, solve());

	cout << ans << '\n';

	return 0;
}
