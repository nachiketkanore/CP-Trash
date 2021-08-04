/*
Author: Nachiket Kanore
Created: Friday 06 November 2020 10:07:36 AM IST
Work out your own salvation. Do not depend on others.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

const int N = 102, mod = 1e9 + 7;

int n, k, x;

int brute = 0;

bool check(vector<int>& a) {
	for (int &y : a) assert(1 <= y && y <= k);
	assert(sz(a) == n);
	
	for (int i = 0; i < n; ) {
		int j = i + 1;
		while (j < n && a[j] > a[j - 1]) ++j;
		--j;
		int len = j - i + 1;
		if (len > x) return false;
		i = j + 1;
	}
	return true;
}

void dfs(vector<int> curr) {
	if (sz(curr) == n) {
		if (check(curr)) {
			see(curr);
			++brute;
		}
		return ;
	}

	FOR (put,1,k) {
		vector<int> nxt = curr;
		nxt.push_back(put);
		dfs(nxt);
	}
}

int BruteAns() {
	brute = 0;
	vector<int> curr;
	dfs(curr);
	return brute;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	/*
		Count the number of ways to create a sequence of N integers : A.
		such that each A[i] is [1, K] and length of any strictly increasing subarray 
		is atmost X.
		2 ways A and B are considered different if there is atleast 1 index id, 
		such that A[id] != B[id]
		K, X <= N <= 100
	*/

	cin >> n >> k >> x;
	int slow = BruteAns();
	cout << slow;
}
