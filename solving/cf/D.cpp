/**
 *    Author: Nachiket Kanore
 *    Created: Friday 30 July 2021 11:54:30 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
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
	int N, K;
	cin >> N >> K;
	
	if (N == 1 || K == 1) {
		string answer(N, 'a');
		cout << answer << '\n';
		return 0;
	}
	string have;
	F0R (ch,K) have += (char)('a' + ch);

	map<string, int> cnt;
	
	string answer = "a";
	char upto = char(K-1 + 'a');

	FOR (i,1,N-1) {
		char who = 'a';
		for (char take = 'a'; take <= upto; take++) {
			string get; get += answer.back(); get += take;
			string have; have += answer.back(); have += who;
			if (cnt[get] <= cnt[have]) {
				who = take;
			}
		}
		string added; added += answer.back(); added += who;
		answer += who;
		cnt[added]++;
	}
	cout << answer << '\n';
}
