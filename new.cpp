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

int* get_array(int N) {
	int* ret = new int[N];
	return ret;
}

int** gen_2d_matrix(int N, int M) {
	int** mat;
	mat = new int*[N];
	for (int i = 0; i < N; i++) {
		mat[i] = new int[M];
	}
	return mat;
}

int*** gen_3d_matrix(int N, int M, int W) {
	static const int default_value = -1;
	int*** mat;
	mat = new int**[N];
	for (int i = 0; i < N; i++) {
		mat[i] = new int*[M];
		for (int j = 0; j < M; j++) {
			mat[i][j] = new int[W];
			for (int k = 0; k < W; k++) 
				mat[i][j][k] = default_value;
		}
	}
	return mat;
}

void solve() {
	int*** A = gen_3d_matrix(4, 4, 4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cout << A[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << "\n\n";
	}
	return;
	int n;
	cin >> n;
	{
		int ans = 0;
		int m = n;
		while (m--) {
			int u, v;
			cin >> u >> v;
			if (u > v) ans++;
		}
		cout << ans << endl;
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
        vector<int> a(n);
        F0R (i,n) cin >> a[i];
    }
}
