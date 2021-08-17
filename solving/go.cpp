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

void solve() {
	cout << (char)(320) << '\n';
	int i=320;
	char *ptr=(char *)&i;
	printf("%d",*ptr);
}

void test() {
	vector<int> A;
	int inversions = 0;
	A.clear();
	int SZ = A.size();
	for (int i = 0; i < SZ; i++) {
		for (int j = i + 1; j < SZ; j++) {
			if (A[i] > A[j]) {
				++inversions;
			}
		}
	}
}

void hello() {
	int n;
	cin >> n;
	vector<int> A(n);	
	set<int> f;
	F0R (i,n) {
		int u;
		cin >> u;
		f.insert(u);
		int val = *f.begin();
		cout << val++ << endl;
	}
}

void Main() {
	int T;
	cin >> T;
	FOR (i,1,T) {
		cout << "HELLO WORLD\n";
	}
}

int32_t main() {
	solve();
	return 0;
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> ans;
		map<int,int> done;
		F0R (i,n) {
			int u;
			cin >> u;
			if (!done.count(u)) ans.push_back(i+1);
			done[u] = 1;
		}
		cout << sz(ans) << '\n';
		for (int id : ans) cout << id << ' ';
		cout << '\n';
	}
}

