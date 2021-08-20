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

const int inf = 1e18;
const int N = 50000;

int32_t main() {
	srand(time(0));
	int T = rand() % 10 + 1;
	cout << T << '\n';
	while (T--) {
		int NL = rand() % N + 1;
		cout << NL << ' ';
		FOR (i,1,NL) {
			if (i == 1) cout << 1;
			else cout << rand() % 10;
		}
		cout << '\n';
		int NR = NL + rand() % N + 1;
		cout << NR << ' ';
		FOR (i,1,NR) {
			if (i == 1) cout << 2;
			else cout << rand() % 10;
		}
		cout << '\n';
	}
}
