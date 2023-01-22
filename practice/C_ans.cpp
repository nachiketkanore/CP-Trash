#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

void solve(int n) {
	multiset<int> f;
	FOR(i, 1, n) f.insert(i);
	int ops = n - 1;
	while (ops-- > 0) {
		int last = *f.rbegin();
		f.erase(f.find(last));
		int next = -1;
		auto it = f.rbegin();
		while (1) {
			int val = *it;
			if ((val % 2) == (last % 2)) {
				next = val;
				break;
			}
			it++;
		}
		assert(~next);
		f.erase(f.find(next));
		int add = (last + next + 1) / 2;
		f.insert(add);
		cout << next << ' ' << last << '\n';
	}
	assert(sz(f) == 1);
	assert(*f.begin() == 2);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		if (n == 2) {
			cout << "2\n";
			cout << 1 << ' ' << 2 << '\n';
			continue;
		}
		cout << "2\n";
		solve(n);
	}
}

/*

1 : 1
choices :



2 : 2
choices :
1 2 , choices = 1 2



3 : 2
choices :
1 2 3 , choices = 1 3
2 2 , choices = 2 2



4 : 2
choices :
1 2 3 4 , choices = 2 4
1 3 3 , choices = 3 3
1 3 , choices = 1 3



5 : 2
choices :
1 2 3 4 5 , choices = 3 5
1 2 4 4 , choices = 4 4
1 2 4 , choices = 2 4
1 3 , choices = 1 3



6 : 2
choices :
1 2 3 4 5 6 , choices = 4 6
1 2 3 5 5 , choices = 5 5
1 2 3 5 , choices = 3 5
1 2 4 , choices = 2 4
1 3 , choices = 1 3



7 : 2
choices :
1 2 3 4 5 6 7 , choices = 5 7
1 2 3 4 6 6 , choices = 6 6
1 2 3 4 6 , choices = 4 6
1 2 3 5 , choices = 3 5
1 2 4 , choices = 2 4
1 3 , choices = 1 3



8 : 2
choices :
1 2 3 4 5 6 7 8 , choices = 6 8
1 2 3 4 5 7 7 , choices = 7 7
1 2 3 4 5 7 , choices = 5 7
1 2 3 4 6 , choices = 4 6
1 2 3 5 , choices = 3 5
1 2 4 , choices = 2 4
1 3 , choices = 1 3



9 : 2
choices :
1 2 3 4 5 6 7 8 9 , choices = 7 9
1 2 3 4 5 6 8 8 , choices = 8 8
1 2 3 4 5 6 8 , choices = 6 8
1 2 3 4 5 7 , choices = 5 7
1 2 3 4 6 , choices = 4 6
1 2 3 5 , choices = 3 5
1 2 4 , choices = 2 4
1 3 , choices = 1 3



10 : 2
choices :
1 2 3 4 5 6 7 8 9 10 , choices = 8 10
1 2 3 4 5 6 7 9 9 , choices = 9 9
1 2 3 4 5 6 7 9 , choices = 7 9
1 2 3 4 5 6 8 , choices = 6 8
1 2 3 4 5 7 , choices = 5 7
1 2 3 4 6 , choices = 4 6
1 2 3 5 , choices = 3 5
1 2 4 , choices = 2 4
1 3 , choices = 1 3



*/