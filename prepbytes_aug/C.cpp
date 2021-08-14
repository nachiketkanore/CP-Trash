/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 14 August 2021 12:35:52 AM IST
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
		for (int &x: A) cin >> x;
		int mn = *min_element(ALL(A));
		int ans = -1;
		F0R (i,N) {
			if (A[i] - i <= 0) {
				ans = i + 1;
				break;
			}
		}
		if (ans != -1) {
			cout << ans << '\n';
			continue;
		}
		for (int &x: A) x -= mn;
		F0R (i,N) {
			if (A[i] - i <= 0) {
				ans = i;
				break;
			}
		}
		assert(~ans);
		++ans;
		cout << ans << '\n';
	}
}
