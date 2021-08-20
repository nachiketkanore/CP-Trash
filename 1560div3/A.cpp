/**
 *    Author: Nachiket Kanore
 *    Created: Friday 20 August 2021 01:57:14 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int32_t main() {
	vector<int> vals = {-1};
	int id = 1;
	auto good = [](int U) {
		if (U % 10 == 3 || U % 3 == 0) return false;
		return true;
	};
	while (sz(vals) < 1010) {
		if (good(id)) vals.push_back(id);
		id++;
	}
	int T;
	cin >> T;
	while (T--) {
		int K;
		cin >> K;
		assert(sz(vals) > K);
		cout << vals[K] << '\n';
	}
}
