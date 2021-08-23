/**
 *    Author: Nachiket Kanore
 *    Created: Monday 23 August 2021 12:57:33 PM IST
**/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int _ = 1e5 + 5;
bool cnt[_];

int32_t main() {
	int N, M;
	cin >> N >> M;
	set<int> have;
	FOR (i,1,N) {
		int u;
		cin >> u;
		cnt[u] = true;
		for (int d = 2; d * d <= u; d++) {
			if (u % d == 0) {
				have.insert(d);
				while (u % d == 0) {
					u /= d;
				}
			}
		}
		if (u^1) have.insert(u);
	}
	vector<int> answer = {1};
	FOR (i,2,M) {
		bool ok = true;
		int u = i;
		for (int d = 2; d * d <= u; d++) {
			if (u % d) continue;
			if (have.count(d)) { ok = false; break; }
			while (u % d == 0) u /= d;
		}
		if (u^1) if (have.count(u)) ok = false;
		
		for (int m = i; m <= M; m += i) 
			if (cnt[m])
				ok = false;

		if (ok) {
			answer.push_back(i);
		}
	}
	cout << sz(answer) << '\n';
	for (int ans: answer) {
		cout << ans << '\n';
	}
}
