/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 03 August 2021 07:20:38 PM IST
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

const int N = 3e4;
const int OFFSET = 1e4 + 2;

int bit[N];

void add(int id) {
	while (id < N) {
		bit[id]++;
		id += id & -id;
	}
}

int qry(int id) {
	int ret = 0;
	while (id) {
		ret += bit[id];
		id -= id & -id;
	}
	return ret;
}

int32_t main() {
	int n;
	cin >> n;
	vector<pair<int,int>> segs(n);
	vector<int> answer;
	for (auto &[x, y]: segs) {
		cin >> x >> y;
		if (x > y) swap(x, y);
		x += OFFSET;
		y += OFFSET;
	}
	sort(ALL(segs), [&](const pair<int,int> &one, const pair<int,int> &two){ 
		return one.second < two.second;
	});
	for (auto &[x, y]: segs) {
		bool taken = (qry(y) - qry(x - 1)) > 0;
		if (!taken) {
			add(y);
			answer.push_back(y - OFFSET);
		}
	}
	cout << sz(answer) << '\n';
	for (auto pt: answer) {
		cout << pt << ' ';
	}
	cout << '\n';
}
