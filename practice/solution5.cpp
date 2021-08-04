#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

vector<int> gg[N];
bool present[30];
vector<string> all;


void add_edge(const string& a, const string& b) {
	if (a == b) return;
	int i = 0, j = 0;
	while (i < sz(a) && j < sz(b)) {
		if (a[i] != b[j]) {
			int from = a[i] - 'a' + 1;
			int to = b[j] - 'a' + 1;
			gg[from].push_back(to);
			return ;
		}
		i++, j++;
	}
	// now one string is prefix of other
	assert(sz(a) != sz(b));
	if (sz(a) > sz(b)) {
		cout << "Impossible\n";
		exit(0);
	} else {
		// one < two (always) (not dependent upon other chars in `two`)
	}
}


vector<int> order; //Stores the Topological Order

bool toposort(int n) //Returns 1 if there exists a toposort, 0 if there is a cycle
{	
	queue<int> q;
	vector<int> indeg(n + 1, 0);
	for(int i = 1; i <= n; i++)
		for(auto &it:gg[i])
			indeg[it]++;
	for(int i = 1; i <= n; i++)
	{
		if(!indeg[i])
			q.push(i);
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		order.push_back(u);
		for(auto &v:gg[u])
		{
			indeg[v]--;
			if(!indeg[v])
				q.push(v);
		}
	}
	return sz(order) == n;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	FOR(i,1,n) {
		string s;	cin >> s;
		all.push_back(s);
	}

	for (int i = 1; i < sz(all); i++) {
		add_edge(all[i - 1], all[i]);
	}

	if (toposort(26)) {
		for (int x : order) {
			char ch = (char) (x - 1 + 'a');
			cout << ch;
		}
		cout << '\n';
	} else {
		cout << "Impossible\n";
	}
}