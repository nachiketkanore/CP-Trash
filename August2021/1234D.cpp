/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 11 August 2021 01:58:09 PM IST
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

struct BIT {
	int N;
	vector<int> bit;
	BIT(int N): N(N) {
		bit = vector<int> (N+1);
	}
	void add(int id, int val) {
		while (id <= N) {
			bit[id] += val;
			id += id & -id;
		}
	}
	int prefix_sum(int id) {
		int ret = 0;
		while (id) {
			ret += bit[id];
			id -= id & -id;
		}
		return ret;
	}
	int get_sum(int L, int R) {
		return prefix_sum(R) - prefix_sum(L - 1);
	}
};

int32_t main() {
	string S; int Q;
	cin >> S >> Q;
	const int N = S.size();
	S = "$" + S;
	vector<BIT> bits(26, BIT(N));
	FOR (i,1,N) bits[S[i]-'a'].add(i, 1);
	while (Q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int pos; char ch;
			cin >> pos >> ch;
			bits[S[pos]-'a'].add(pos, -1);
			S[pos] = ch;
			bits[S[pos]-'a'].add(pos, +1);
		} else {
			int L, R;
			cin >> L >> R;
			int cnt = 0;
			F0R (ch,26) {
				cnt += bits[ch].get_sum(L, R) > 0;
			}
			cout << cnt << '\n';
		}
	}
}
