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
	string s;
	cin >> s;
	int n = sz(s);
	vector<pair<bool,string>> splits;

	for (int i = 0; i < n; ) {
		assert(s[i] == '<');
		int j = i + 1;
		string curr;
		while (j < n && s[j] != '>') curr += s[j], j++;
		if (curr.front() == '/') {
			curr.erase(curr.begin());
			splits.push_back(make_pair(0, curr));
		} else {
			splits.push_back(make_pair(1, curr));
		}
		i = j + 1;
	}

	int tab = 0;
	for (auto [is_open, text]: splits) {
		if (!is_open) --tab;
		F0R (i,tab<<1) cout << ' ';
		cout << '<'; if (!is_open) cout << '/';
		cout << text << '>' << '\n';
		if (is_open) ++tab;
	}
}

