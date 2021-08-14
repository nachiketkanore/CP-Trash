/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 14 August 2021 01:20:38 AM IST
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

const int M = 1e6 + 5;
vector<int> pos[M + 1];

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> A(N + 1);
		FOR (i,1,N) {
			cin >> A[i];
			pos[A[i]].push_back(i);
		}
		int ans = 0;
		FOR (i,1,M) {
			if (sz(pos[i]) <= 1) continue;
			int add = 0;
			F0R (j,sz(pos[i])) {
				ans += (N - pos[i][j] + 1) * add;
				add += pos[i][j];
			}
		}
		cout << ans << '\n';
		FOR (i,1,N) pos[A[i]].clear();
	}
}
