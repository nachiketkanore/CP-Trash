/**
 *    Author: Nachiket Kanore
 *    Created: Friday 23 July 2021 01:22:43 AM IST
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
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

vector<int> follow(int when) {
	int n;
	cin >> n;
	return {};
}

void test() {
	int T = 20;
	while (T--) {
		cout << "[ { {nachiket} } ]" << 20 - T << endl;
	}
}

vector<int> my_func() {
	vector<int> ret = { 21 };
	ret.begin()++;
	return {ret.back()};
}

void Test() {
	int N;
	cin >> N;
	while (N--) {
		int u;
		cin >> u;
		cout << __builtin_popcountll(u) << '\n';
	}
}

int32_t main() {
	Test();
	vector<int> (*my_func_ptr)();
	my_func_ptr = my_func;
	printf("address = %p\n", my_func_ptr);
	cout << my_func_ptr;
}
