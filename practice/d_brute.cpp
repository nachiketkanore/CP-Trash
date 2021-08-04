// #include "bits/stdc++.h"

// #define int long long
// #define sz(x) (int)(x.size())
// #define FOR(i,L,R) for(int i = L; i <= R; i++)
// using namespace std;

// const int N = 2e5 + 5, inf = 1e18;

// map<string, int> dp;

// string pref(string s) {
// 	int i = 0;
// 	string ret;
// 	char fi = s[0];
// 	while (s[i] == fi) i++;
// 	for (int j = i; j < sz(s); j++) ret.push_back(s[j]);
// 		return ret;
// }

// string mid(string s, int id) {
// 	string t;
// 	for (int i = 0; i < sz(s); i++) if (id != i) t.push_back(s[i]);
// 	return t;
// }

// int go(string curr) {
// 	if (sz(curr) == 0) return 0;
// 	if (dp.count(curr)) return dp[curr];
// 	int ans = 0;

// 	for (int i = 0; i < sz(curr); i++) {
// 		string next = mid(curr, i);
// 		next = pref(next);
// 		ans = max(ans, 1 + go(next));
// 	}
// 	dp[curr] = ans;
// 	return ans;
// }

// void trace(string curr) {
// 	if (sz(curr) == 0) return ;
// 	int ans = go(curr);

// 	for (int i = 0; i < sz(curr); i++) {
// 		string next = mid(curr, i);
// 		next = pref(next);
// 		if (1 + go(next) == ans) {
// 			cout << curr << ' ' << i << '\n';
// 			return trace(next);
// 		}
// 	}
// }

// int32_t main() {
// 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
// 	int T;	cin >> T;
// 	while (T--) {
// 		int n;	
// 		cin >> n;
// 		string s;	cin >> s;
// 		n = sz(s);
// 		int ans = 0;
// 		for (int i = 0; i < n; i++) {
// 			string next = mid(s, i);
// 			next = pref(next);
// 			ans = max(ans, 1 + go(next));
// 		}
// 		cout << ans << '\n';
// 		// cout << "given str = " << s << '\n';
// 		// cout << "ans = " << ans << '\n';
// 		// for (int i = 0; i < n; i++) {
// 		// 	string next = mid(s, i);
// 		// 	next = pref(next);
// 		// 	if (1 + go(next) == ans) {
// 		// 		cout << s << ' ' << i << '\n';
// 		// 		trace(next);
// 		// 		break;
// 		// 	}
// 		// }

// 		// cout << "\n\n";
// 	}
// }

// // 6
// // 2
// // 5
// // 2
// // 2
// // 1
// // 6
// // 4
// // 3
// // 2


#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		multiset<int> vals;
		FOR(i,1,n) {
			int u;	cin >> u;
			vals.insert(u);
		}
		int ans = *vals.rbegin() - *vals.begin();

		while (k--) {
			if (sz(vals) == 1) break;
			int last = *vals.rbegin();
			vals.erase(vals.find(last));
			int last2 = *vals.rbegin();
			vals.erase(vals.find(last2));
			vals.insert(0);
			vals.insert(last + last2);
			ans = max(ans, *vals.rbegin() - *vals.begin());
		}

		cout << ans << '\n';
	}
}