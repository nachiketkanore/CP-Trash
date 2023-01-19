/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 07 August 2021 12:59:03 AM IST
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
#include <string>
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

int* get_array(int size, int def = 21) {
	int* ret = new int[size];
	for (int i = 0; i < size; i++) {
		ret[i] = def;
	}
	return ret;
}

int32_t main() {
	int* my_array = get_array(100);
	for (int i = 0; i < 100; i++) {
		cout << my_array[i] << ' ';
		if (i == 99)
			cout << '\n';
	}
	return 0;
	srand(time(0));
	int id = 1;
	while (true) {
		cout << "Test " << id++ << " : ";
		int N = rand() % 10000 + 1;
		int K = rand() % 100 + 1;
		vector<int> cnt(K);
		F0R(j, N) cnt[j % K]++;
		// cout << N << ' ' << K << ": \n";
		set<int> chk(ALL(cnt));
		if (sz(chk) <= 2) {
			if (sz(chk) == 2) {
				assert(*chk.begin() + 1 == *chk.rbegin());
				cout << "OK2\n";
			} else {
				cout << "OK\n";
			}
			// for (int x: cnt) cout << x << ' '; cout << endl;
		} else {
			cout << "BAD\n";
			assert(false);
		}
	}
}
