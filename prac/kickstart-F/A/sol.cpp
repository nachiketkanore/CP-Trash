/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 18 September 2022 10:27:31 PM IST
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

struct Data {
	string C;
	int D;
	int U;
};

void solve() {
	int N;
	cin >> N;
	vector<Data> A(N);
	for (Data& d : A) {
		cin >> d.C >> d.D >> d.U;
	}
	vector<Data> first = A, second = A;
	sort(first.begin(), first.end(), [&](const Data& one, const Data& two) {
		if (one.C < two.C)
			return true;
		if (one.C > two.C)
			return false;
		return one.U < two.U;
	});
	sort(second.begin(), second.end(), [&](const Data& one, const Data& two) {
		if (one.D < two.D)
			return true;
		if (one.D > two.D)
			return false;
		return one.U < two.U;
	});

	int ans = 0;
	F0R(i, N) {
		ans += first[i].D == second[i].D && first[i].C == second[i].C && first[i].U == second[i].U;
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}

	return 0;
}
