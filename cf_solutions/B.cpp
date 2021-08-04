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

class Name{
	vector<string> names;
	vector<int> scores;
	Name(vector<string> names, vector<int> scores): names(names), scores(scores) {}
	Name() {
		names = {"nachiket-kanore"};
		scores = {0};
	}
	void test() {
		assert(sz(names) == sz(scores));
	}
	void add_user(const string& name, const int& score) {
		names.push_back(name);
		scores.push_back(score);
		test();
	}
};

int32_t main() {
	{

	}
}

