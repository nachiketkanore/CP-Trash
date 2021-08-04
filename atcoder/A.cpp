#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 20, mod = 1e9 + 7, inf = 1e18;

void test() {
	cin >> x;
}

string A, B;
int n, dp[N][2][2][5];

int go(int pos, bool bigA, bool smallB, int cnt){
    if(cnt > 3) return 0;
    if(pos >= n)
        return 1;

    int &ans = dp[pos][bigA][smallB][cnt];
    if(~ans)
        return ans;
    ans = 0;
    for(int i = 0; i < 10; i++){
        if(!bigA && i < A[pos] - '0')   continue;
        if(!smallB && i > B[pos] - '0') continue;

        ans += go(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), cnt + (i != 0));
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> A >> B;
        reverse(A.begin(), A.end());
        while(sz(A) < sz(B))
            A.push_back('0');
        reverse(A.begin(), A.end());
        n = sz(B);
        int ans = 0;

        for(int i = 0; i < 10; i++){
            if(i < A[0] - '0')  continue;
            if(i > B[0] - '0')  continue;

            ans += go(1, i > A[0] - '0', i < B[0] - '0', i != 0);
        }
        cout << ans << '\n';
    }
}

int result(int n) {
	int mat[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < n; i++) sort(mat[i], mat[i] + n);
	int best = n;
	for (int j = n-1; j >= 0; j--) {
		if (best - 1 >= 0 && mat[best - 1][j] == 1) {
			best = best - 1;
		}
	}
	// we have all ones from `best` column
	if (best == n) return 0;
	return n - best + 1;
}

bool brute() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		vector<int> other;
		for (int j = i; j >= 0; j--) {
			if (a[j] >= a[i]) {
				other.push_back(a[j]);
			}
		}
		for (int j = i, sum = 0; j >= 0; j--) {
			sum += a[j];
			if (sum == 0) return false;
		}
		if (accumulate(other.begin(), other.end(), 0LL) == 0) {
			cout << "BAD SUBARRAY FOUND\n";
			return false;
		}
	}
	return true;
}

void pretests() {
	string ret;
	int size = rand() % 100 + 1;
}

void MAIN() {
	int n, tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<vector<int>> g(n+1);
		for (int i = 0; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
}

vector<int> range(int L, int R) {
	vector<int> ret;
	FOR (i,L,R) {
		ret.push_back(i);
	}
	return ret;
	FOR (i,L,R) {
		ret.push_back(i);
	}
	return ret;
}

bool test() {
	{

	}
	vector<int> A, B;
	vector<int> pre;
	const int MOD = 1e9 + 7;
	FOR (i,1,10) {
		int n;
		cin >> n;
		{
			for (int j = 0; i < 20; j ++) {
				if (i == j) {
					B.push_back(i +  j);
				}
			}
		}
	}
	for (int i = 0; i < 20; i++) {
		{
			{
			}
		}
	}
	FOR (i,1,10000) {
		if (pre.empty()) {
			pre = {1};
		} else {
			pre.push_back(i * pre.back());
		}
		if (pre.back() >= MOD) {
			pre.back() %= MOD;
		}
	}
	FOR (i,1,10) {
		A.push_back(i);
		B.push_back(i);
	}
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) {
			a[i] += a[i-1];
		}
	}
	map<int,int> f;
	for (int i = 0; i < n; i++) {
		if (f.count(a[i])) return false;
		f[a[i]]++;
	}
	for (int d: range(10, 20)) {
		cerr << d << endl;
	}
	for (auto v: range(20, 20)) {
		if (v > 1) {
			return false;
		}
	}
	bool ok = true;
	return ok;
}

vector<int> pre(int SIZE = N) {
	vector<int> ret(SIZE + 1);
	const int MOD = 1e9 + 7;
	ret[0] = 1;
	for (int i = 1; i <= SIZE; i++) {
		ret[i] = i * ret[i-1];
		if (ret[i] >= MOD)
			ret[i] %= MOD;
	}
	return ret;
}

int32_t main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x : a) cin >> x;

		sort(ALL(a));

	int lo = -inf, hi = inf;
	int ans = inf + 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int cnt = 0;
		vector<int> bk;
		
		F0R (i,n) {
			int upto = mid / a[i];
			int add = upper_bound(ALL(bk), upto) - bk.begin();
			cnt += add;
			
			bk.push_back(a[i]);
		}

		if (cnt >= k) ans = mid, hi = mid - 1;
		else lo = mid + 1;
	}

	assert(ans != inf + 1);
	cout << ans << '\n';
}

