/*
Author: Nachiket Kanore
Created: Thursday 22 July 2021 11:06:29 PM IST
*/
#include <bits/stdc++.h>

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

const int inf = 1e18;
const int N = 5e5 + 5;

template<typename T>
T umax(T v) {
  return v;
}

void test2() {
	int n;
	cin >> n;
	cout << 21 * n << endl;
}

int f;
void test() {
  int n;
  cin >> n;
  cout << n << endl;
  int  hello;
  cin >> hello;
  cout << hello;
}

template<typename T, typename... Args>
T umax(T first, Args... args) {
  return max(first, umax(args...));
}
template<typename T>
T adder(T v) {
  return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args) {
  return first + adder(args...);
}
int32_t main() {
	cout << umax(10, 20, 30, 40, 50);
}
