/** - saw the solution
 *    Author: Nachiket Kanore
 *    Created: Sunday 11 February 2024 11:11:31 AM IST
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

int32_t main() {

	int answer = 0;
	bool picked[1 << 14] = { false };
	vector<int> A;
	F0R(val, 1 << 14) {
		bool check = true;
		F0R(bit, 7) check &= val >> bit & 1;
		if (check) {
			A.push_back(val);
			picked[val] = true;
		}
	}
	while (sz(A) > 100) {
		picked[A.back()] = false;
		A.pop_back();
	}
	assert(sz(A) == 100);
	cout << "? ";
	for (int a : A) {
		cout << a << " ";
	}
	cout << endl;
	cout.flush();

	int ans_A;
	cin >> ans_A;
	F0R(bit, 7) {
		answer |= (1 << bit) * (1 ^ (ans_A >> bit & 1));
	}

	vector<int> B;
	F0R(val, 1 << 14) if (!picked[val]) {
		bool check = true;
		FOR(bit, 7, 13) check &= val >> bit & 1;
		if (check) {
			B.push_back(val);
			picked[val] = true;
		}
	}
	while (sz(B) > 100) {
		picked[B.back()] = false;
		B.pop_back();
	}
	assert(sz(B) == 100);
	cout << "? ";
	for (int b : B) {
		cout << b << " ";
	}
	cout << endl;
	cout.flush();

	int ans_B;
	cin >> ans_B;
	FOR(bit, 7, 13) {
		answer |= (1 << bit) * (1 ^ (ans_B >> bit & 1));
	}

	cout << "! " << answer << endl;
	cout.flush();

	return 0;
}
