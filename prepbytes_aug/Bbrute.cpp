/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 14 August 2021 12:20:44 AM IST
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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int &x: A) {
			cin >> x;
		}
		sort(ALL(A));
		int ans = 0;
		F0R (i,N) {
			int get = 1;
			int M = A[i];
			for (int j = i - 1; j >= 0; j--) {
				int d = abs(A[j] - A[j + 1]);
				if (d >= M) ++get;
				else break;
			}
			cmax(ans, get);
		}
		cout << ans << '\n';
	}
}
