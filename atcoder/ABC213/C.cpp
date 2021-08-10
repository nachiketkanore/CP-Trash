/**
 *    Author: Nachiket Kanore
 *    Created: Monday 09 August 2021 03:21:09 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
#include <map>
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

int H, W, N;
map<int,int> rowMap, colMap;

int32_t main() {
	cin >> H >> W >> N;
	vector<pair<int,int>> pos(N);
	set<int> rows, cols;
	for (auto &[x, y]: pos) {
		cin >> x >> y;
		rows.insert(x);
		cols.insert(y);
	}
	int i = 0;
	for (int row: rows) {
		rowMap[row] = row - (row - i) + 1;
		i++;
	}
	int j = 0;
	for (int col: cols) {
		colMap[col] = col - (col - j) + 1;
		j++;
	}
	for (const auto [x, y]: pos) {
		cout << rowMap[x] << ' ' << colMap[y] << '\n';
	}
}
