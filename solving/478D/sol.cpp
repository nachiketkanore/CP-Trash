/*
Author: Nachiket Kanore
Created: Thursday 15 October 2020 11:59:48 AM IST
(ツ) The smallest flower is a thought, a life answering to some feature of the Great Whole, of whom they have a persistent intuition.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int N = 2e5 + 5, mod = 1e9 + 7;

int r, g, h, maxh;
unordered_map<int, int, custom_hash> dp[900];
unordered_map<int, int, custom_hash> dp2[900];

int go(int remr, int remg, int curr) {
	if (curr > h) return 0;
	if (dp[curr].count(remr))
		return dp[curr][remr];
	int ans = 0;
	if (remr >= curr) {
		ans = max(ans, 1 + go(remr - curr, remg, curr + 1));
	}
	if (remg >= curr) {
		ans = max(ans, 1 + go(remr, remg - curr, curr + 1));
	}
	dp[curr][remr] = ans;
	return ans;
}

int go1(int remr, int remg, int curr) {
	if (curr == maxh + 1)
		return 1;
	if (dp2[curr].count(remg))
		return dp2[curr][remg];
	int ans = 0;

	if (remr >= curr) {
		ans = (ans + go1(remr - curr, remg, curr + 1)) % mod;
	}
	if (remg >= curr) {
		ans = (ans+ go1(remr, remg - curr, curr + 1)) % mod;
	}
	dp2[curr][remg] = ans;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> r >> g;

	h = 1;
	while ((h + 1) * (h + 2) / 2 <= (r + g)) ++h;

	maxh = go(r, g, 1);
	int ans = go1(r, g, 1);
	cout << ans;
}




#include <cstdio>
#include <algorithm>
using namespace std;

int sm, h;

int dp[2][200005];

int main(){
    int r, g;
    scanf("%d %d",&r,&g);
    sm = r + g;
    for(int i=900; i>=0; i--){
    	int p = sm - i * (i+1) / 2;
    	for(int j=0; j<=g; j++){
    		dp[i%2][j] = 0;
    		if(p > j + i) dp[i%2][j] = max(dp[i%2][j], dp[(i+1)%2][j] + 1);
    		if(j > i) dp[i%2][j] = max(dp[i%2][j], dp[(i+1)%2][j-i-1] + 1);
    	}
    }
    int h = dp[0][g];
    fill(dp[h%2], dp[h%2] + g + 1, 1);
    for(int i=h-1; i>=0; i--){
    	int p = sm - i * (i+1) / 2;
    	for(int j=0; j<=g; j++){
    		dp[i%2][j] = 0;
    		if(p > j + i) dp[i%2][j] += dp[(i+1)%2][j];
    		if(j > i) dp[i%2][j] += dp[(i+1)%2][j-i-1];
    		dp[i%2][j] %= 1000000007;
    	}
    }
    printf("%d",dp[0][g]);
}

#include<bits/stdc++.h>

using namespace std;

const int Mod=1e9+7;

int r,g,s,h;
int Dpm[2][200200];
int Dpc[2][200200];

int main()
{
    cin>>r>>g;    s=r+g;

    for(int i=1000;i>0;i--)
    {
        for(int R=0;R<=r;R++)
        {
            int Spend=(i*(i-1))/2;
            int G=g-Spend+r-R;

            if(G<0||R<0)    Dpm[i&1][R]=0;
            if(G<i&&R<i)    Dpm[i&1][R]=i-1;

            if(!(G<0||R<0)&&!(G<i&&R<i))    Dpm[i&1][R] = max( max( Dpm[(i+1)&1][R] , R-i>=0 ? Dpm[(i+1)&1][R-i] : 0 ) , i );

        }
    }

    h=Dpm[1][r];

    for(int i=1000;i>0;i--)
    {
        for(int R=0;R<=r;R++)
        {
            int Spend=(i*(i-1))/2;
            int G=g-Spend+r-R;

            if(G<0||R<0)    Dpc[i&1][R]=0;
            else if(i>h)    Dpc[i&1][R]=1;

            if(!(i>h)&&!(G<0||R<0)) Dpc[i&1][R]=( Dpc[(i+1)&1][R] + ( R-i>=0 ? Dpc[(i+1)&1][R-i] : 0 ) )%Mod;

        }
    }

    cout<<Dpc[1][r];

}