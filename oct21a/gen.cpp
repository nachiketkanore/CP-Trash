#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int inf = 1e18;

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());


inline int rand(int l, int r){
    std::uniform_int_distribution<int> uid(l, r); 
    return uid(rng);
}

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int32_t main() {
	srand(time(0));
	int T = 100;
	cout << T << '\n';
	while (T--) {
		int N = rand(1, 10000);
		int D = -1;
		int val = N;
		while (val) {
			D = val % 10;
			val /= 10;
		}
		cout << N << ' ' << D << '\n';
	}
}
