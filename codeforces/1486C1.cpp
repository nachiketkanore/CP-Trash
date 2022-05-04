/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 May 2022 12:53:38 AM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

int ask(int L, int R) {
	if (L >= R)
		return -1;
	cout << "? " << L << " " << R << endl;
	cout.flush();
	int id;
	cin >> id;
	return id;
}

int go(int L, int R) {
	if (L == R)
		return L;

	assert(R - L + 1 >= 2);
	int id = ask(L, R);
	if (L + 1 == R) {
		return L ^ R ^ id;
	}

	int mid = (L + R) / 2;

	int get = ask(mid, R);
	if (get == id)
		return go(mid, R);
	return go(L, mid - 1);
}

int32_t main() {
	int N;
	cin >> N;
	int ans = go(1, N);
	cout << "! " << ans << endl;
	return 0;
}
