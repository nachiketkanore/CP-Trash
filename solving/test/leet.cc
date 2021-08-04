#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <queue>
#include <bitset>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

class LLNode {
    public:
        int val;
        LLNode *next;
};

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {

	}
}

for(int i = 0; i < n; i++)
{

for (int j = 0; j < n; j++) 
{
	{

	}
}
}

// For heavy recursions
// #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2")

void hello() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(ALL(a));
	int ans = 0;
	for (int i = 1; i < n; i++) {
		a[i] += a[i-1];
		if (a[i] > 0) ans++;
	}
	cout << ans << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		int id = upper_bound(a.begin(), a.end(), u) - a.begin();
		int val;
		cin >> val;
		if (id == 1) {
			if (val == 21) {
				cout << "YES BRO\n";
				cout << endl;
				return 0;
			}
		}
		int x, y;
		cin >> x >> y;
		a[i] = make_pair(x, y);
	}
}

LLNode* get(vector<int> a) {
	if (a.empty()) return NULL;
	LLNode* ans = new LLNode();
	LLNode* curr = ans;

	const int n = a.size();
	for (int i = 0; i < n; i++) {
		curr->val = a[i];
		if (i == n-1) {
			curr->next = NULL;
		} else {
			curr->next = new LLNode();
			curr = curr->next;
		}
	}
	return ans;
}

vector<pair<int,int>> g[20];
void dijkstra(int s, vector<int> & d) {
    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : g[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
}

void solve() {
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	 
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	// int T;	cin >> T;	while (T--) solve();

	cout << bitset<10> (36) << '\n';
	cout << bitset<10> (6) << '\n';
}

/*
1)
EV (1 + 2 + 3) = EV (1) + EV(2) + ...
EV (a1 + a2 + a3 + ...) = EV (a1) * () /

2)

1 2 3 ... min(A) = 10^6 <= x

1 = n
2 = n/2
3 = n/3

1 2 3 4 5
2 4 6 8
3 6 9  

nlogn

x =>                    x       2x         3x        4x ...



						6 []      12			18 		24 
						 8 8 9 10
						 cnt 
						 8 - 6
						 8 - 6
						 9 - 6
						 10 -6
						 sum - 
						ops += sum (in range) - cnt * 6
						ops <= K 
x => 


1 4 3
4 5 1
6 7 4

dp[i][j] 
i -> j -> k
DAG

char set = [a b c ]

# string of length N
no s[i] and s[i-1] are same
											
								(which_col)
								carry = 0							< 100
						 	12235 6 => max 9, cols = 100, 0 <= sum <= 900 sum = [0, k-1]
						+	23453 4 <= row
						+	34534 3
						+	35423 3
						+	34534 4
						 	carry * 10^adsf % k == 0
								  0 <= sum <= 900
								  digit_at_j_th_column_in_sum = (carry + sum) % 10
								  carry = (carry + sum) /10
								  sum = (sum % k + digit_at_j_th_column_in_sum * 10^1 ) % k
								  10
						sum =   
						sum % k == 0
						  []
							999
							999
							999
					[carry]    
								 	0 <= possible <= 9 * columns
								  20 pre[0][20]	
									pre[j][S] = min changes req to make sum in col j = X
								  X <= what is min changes req to make sum in col j = X 	
								  8.10^0
								  100 ** 3 * 900

						dp[which_col][carry][sum_mod_k] = total changes

						which_col = (sum_mod_k == 0)

						carry = (6 + 4 + 2 ... + 4) /10
						sum_at_that = () % 10
						init_sum % k = 20
										digits (n) <= 100
						sum = divisible by k (100)
						n^3

ans = [L, R]
	= [L`, R`]

add(x) {
	ans -= freq[x] C 2	
	freq[x]++
	ans += freq[x] C 2	
}

remove() {
	ans -= freq[x] C 2	
	freq[x]++
	ans += freq[x] C 2	
}

Q root (N)

[1 2 3 4 5 2 2 3 5]
sum (nC2( freq[i] ))

Mo

currset = PBDS
set[all nodes] = n ^ 2

void dfs(u) {
	for (int v : g[u]) {
		dfs(u)
		merge v with u 
		largest subtree size x 
		&set[u] = set[x]

		for (y : g[u]) {
			add(set[u], set[y])
		}
	}
	// currset has u subtree
	set[u]
s
}

for all u intime[u], outtime[u]

subarray queries [L, R] X, count Values < X



_____R
	___________
	_
	_____
	_____
		  L_____
			_____
					_____
						_____
						_____
						_____

	
consider polynomial P(x) = x^a[1] + x^a[2] + ... + x^a[N]

consider 2 arrays ahet fakt a ani b
 P(x) = x^a[1] + x^a[2] + ... + x^a[N] for array a
 Q(x) = x^b[1] + x^b[2] + ... + x^b[N] for array b
 no multiply P(x) and Q(x)
 it will contain all exponents which are possible 
 from min(a[i] + b[j]) to max(a[i] = b[j]);
*/
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

void ARRAY(int n, int L, int R) {
    cout << n << '\n';
    FOR(i,1,n) {
        cout << rand(L, R) << " \n"[i == n];
    }
}

void STRING(int n, char from, char to) {
    assert(from <= to);
    int L = from - 'a';
    int R = to - 'a';
    assert(L <= R);

    cout << n << '\n';
    FOR(i,1,n) {
        char ch = (char)('a' + rand(L, R));
        cout << ch;
    }   cout << '\n';
}

void TREE(int n) {
    cout << n << '\n';

    vector<pair<int,int>> edges;
    for(int i = 2; i <= n; ++i) {
        edges.emplace_back(rand(1, i - 1), i);
    }
    
    vector<int> perm(n + 1); // re-naming vertices
    for(int i = 1; i <= n; ++i) {
        perm[i] = i;
    }
    shuffle(perm.begin() + 1, perm.end(), rng);
    
    shuffle(edges.begin(), edges.end(), rng); // random order of edges
    
    for(pair<int, int> edge : edges) {
        int a = edge.first, b = edge.second;
        if(rand() % 2) {
            swap(a, b); // random order of two vertices
        }
        cout << perm[a] << ' ' << perm[b] << '\n';
    }
}

void QUERIES(int Q, int L, int R) {
    cout << Q << "\n";
    while (Q--) {
        int QL = rand(L,R);
        int QR = rand(L,R);
        if (QL > QR) swap(QL, QR);
        cout << QL << " " << QR << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       
    int T = 20;
    cout << T << '\n';
    FOR(TC,1,T) {
        int N = rand(1 ,200);
        cout << N << '\n';
        FOR(i,1,N) cout << rand(1,inf) << " \n"[i == N];
    }
}
