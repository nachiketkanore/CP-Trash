/*
Author: Nachiket Kanore
Created: Wednesday 21 October 2020 08:38:50 PM IST
(ツ) Everyone is a genius at least once a year. A real genius has his original ideas closer together.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 5e5 + 5;
const int Q = 5e5 + 5;
const int M = 1e6 + 5;
const int SZ = sqrt(N) + 1;

struct data
{
	int l, r, idx;
}qr[Q];

int n, q, a[N];
int freq[M];
long long ans[Q];
long long cur = 0;
set<pair<int,int>> vals;	// (frequency, value)

bool comp(struct data &d1, struct data &d2)
{
	int b1 = d1.l / SZ;
	int b2 = d2.l / SZ;
	if(b1 != b2)
		return b1 < b2;
	else
		return (b1 & 1) ? d1.r < d2.r : d1.r > d2.r;
}

inline void add(int val)
{	
	if (freq[val] == 0) {
		freq[val]++;
		vals.insert({1, val});
		return;
	}

	pair<int,int> already = {freq[val], val};
	// assert(vals.count(already));
	vals.erase(vals.find(already));

	already.first++;
	vals.insert(already);
	freq[val]++;
}

inline void remove(int val)
{
	if (freq[val] == 1) {
		// also delete from set
		pair<int,int> already = {freq[val], val};
		// assert(vals.count(already));
		vals.erase(vals.find(already));
		freq[val]--;
		return;
	}

	pair<int,int> already = {freq[val], val};
	// assert(vals.count(already));
	vals.erase(vals.find(already));
	
	already.first--;
	freq[val]--;
	vals.insert(already);
}

void mo()
{
	sort(qr + 1, qr + q + 1, comp);
	int l = 1, r = 0;
	cur = 0;
	for(int i=1;i<=q;i++)
	{
		while(l < qr[i].l) remove(a[l++]);
		while(l > qr[i].l) add(a[--l]);
		while(r < qr[i].r) add(a[++r]);
		while(r > qr[i].r) remove(a[r--]);

		cur = 0;
		auto it = *vals.begin();
		if (it.first == 1)
			cur = it.second;

		cout << "HERE\n";

		ans[qr[i].idx] = cur;
	}
}

void solve() {
	int n;
	cin >> n;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	FOR(i,1,n) {
		cin >> a[i];
	}

	cin >> q;
	FOR(i,1,q) {
		cin >> qr[i].l >> qr[i].r;
		qr[i].idx = i;
	}

	mo();

	FOR(i,1,q) {
		cout << ans[i] << "\n";
	}
}
