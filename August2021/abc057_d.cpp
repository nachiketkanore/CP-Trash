/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 21 August 2021 12:03:48 AM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
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

int choose(int N, int R) {
	if (N < R) return 0;
	int ret = 1;
	F0R (i,R) {
		ret *= (N - i);
		ret /= (i + 1);
	}
	return ret;
}

int32_t main() {
	int N, A, B;
	cin >> N >> A >> B;
	vector<int> vals(N);
	F0R (i,N) cin >> vals[i];
	sort(ALL(vals)); reverse(ALL(vals));
	map<int,int> cnt; 
	F0R (i,N) cnt[vals[i]]++;
	while (sz(vals) ^ A) {
		vals.pop_back();
	}
	int sum = 0; for (int x: vals) sum += x;
	int last = vals.back();
	int cnt_last = 0;
	while (sz(vals) && vals.back() == last) {
		++cnt_last;
		vals.pop_back();
	}
	long long answer = 0;
	if (cnt_last == A) {
		FOR (len,A,B) answer += choose(cnt[last], len);
	} else {
		answer = choose(cnt[last], cnt_last);
	}
	printf("%0.10f\n%lld", 1. * sum / A, answer);
}
