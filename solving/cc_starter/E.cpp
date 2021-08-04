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

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(m);
		F0R (i,m) cin >> a[i];
		auto found = [&](int w) {
			map<int,int> freq;
			auto add = [&](int val) {
				freq[val]++;	
			};
			auto remove = [&](int val) {
				freq[val]--;
				if (freq[val] == 0) 
					freq.erase(val);
			};
			F0R (i,m) add(a[i]);
			F0R (i,w) remove(a[i]);
			if (sz(freq) == n) return true;
			for (int i = w, j = 0; i < m; i++, j++) {
				remove(a[i]);
				add(a[j]);
				if (sz(freq) == n) return true;
			}
			return false;
		};
		// reverse the problem
		// find largest subarray s.t. excluding it we have all n values
		int lo = 1, hi = m;
		int best = 0;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (found(mid)) best = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		int ans = m - best;
		cout << ans << '\n';
	}
}

