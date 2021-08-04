/*
Author: Nachiket Kanore
Created: Thursday 03 December 2020 12:45:18 AM IST
(ツ) It has never been my object to record my dreams, just to realize them.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 3e5 + 50, inf = 1e18;

int n, a[N];
int bestPref[N];
int bestSuff[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	int len = n*3;
	FOR (i,1,len) cin >> a[i];

	fill(bestPref, bestPref+len+5, -inf);
	fill(bestSuff, bestSuff+len+5, inf);

	{
		multiset<int> bestMaxs;
		int bestSum = 0;
		FOR(i,1,n) {
			bestSum += a[i];
			bestMaxs.insert(a[i]);
		}

		bestPref[n] = bestSum;

		FOR (i,n+1,len) {
			int mn = *bestMaxs.begin();
			if (mn < a[i]) {
				bestSum -= mn;
				bestSum += a[i];
				bestMaxs.erase(bestMaxs.find(mn));
				bestMaxs.insert(a[i]);
			}
			bestPref[i] = bestSum;
		}

	}

	{
		multiset<int> bestMins;
		int bestSum = 0;
		for (int i = len; i >= 2*n+1; i--) {
			bestSum += a[i];
			bestMins.insert(a[i]);
		}

		assert(sz(bestMins) == n);
		bestSuff[2*n+1] = bestSum;

		for (int i = 2*n; i >= 1; i--) {
			int mx = *bestMins.rbegin();
			if (mx > a[i]) {
				bestSum -= mx;
				bestSum += a[i];
				bestMins.erase(bestMins.find(mx));
				bestMins.insert(a[i]);
			}
			bestSuff[i] = bestSum;
		}
	}

	FOR (i,1,len) 
		bestPref[i] = max(bestPref[i], bestPref[i-1]);
	for (int i = len; i >= 1; i--) 
		bestSuff[i] = min(bestSuff[i], bestSuff[i+1]);

	int ans = -inf;

	FOR (i,1,len) 
		if (i >= n && len-i >= n) 
			ans = max(ans, bestPref[i] - bestSuff[i+1]);
	cout << ans << "\n";
	
}
