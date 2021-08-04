#include <bits/stdc++.h>
using namespace std;

namespace itertools {
	#define sz(X) (int)X.size()
	// TODOs:
	// implement for generic types
	// FUNCTIONS:
	// 1. permutations
	// 2. zip
	// 3. product
	// 4. combinations
	// 5. groupby
	// 6. tuples(len) --> subsets of given `len`
	// 7. chain
	// 8. subsets --> all subsets
	
	template <typename T>
	vector<T> permutations(T s) {
		assert(sz(s) <= 10);
		vector<T> ret;
		sort(s.begin(), s.end());
		do {
			ret.push_back(s);
		} while (next_permutation(s.begin(), s.end()));
		return ret;
	}

	template <typename T>
	vector<pair<T, T>> zip(vector<T> one, vector<T> two) {
		assert(sz(one) == sz(two));
		vector<pair<T, T>> ret;
		for (int i = 0; i < sz(one); i++)
			ret.push_back(make_pair(one[i], two[i]));
		return ret;
	}
}

int main() {
	vector<string> one = {"nachiket", "kanore"};
	vector<string> two = {"kanore", "nachiket"};
	auto result = itertools::zip(one, two);
	
	for (auto [x, y]: result) cout << x << ' ' << y << '\n';
	
	vector<string> result2 = itertools::permutations(one[0]);
	for (string &s : result2) cout << s << '\n';
}

