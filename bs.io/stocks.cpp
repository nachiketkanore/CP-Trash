#include "bits/stdc++.h"
using namespace std;

struct Info {
	int cnt;
	string stock;

	Info(string stk, int c) : stock(stk), cnt(c) {
	}

	const bool operator<(const Info& other) const {
		if (cnt == other.cnt)
			return stock > other.stock;
		return cnt < other.cnt;
	}
};

class StockMarket {
	public:
	map<string, int> cnt;
	set<Info> A;

	StockMarket(vector<string>& stocks, vector<int>& amounts) {
		const int N = stocks.size();
		for (int i = 0; i < N; i++) {
			add(stocks[i], amounts[i]);
		}
	}

	void add(string s, int amount) {
		// cout << string(10, '-') << endl;
		// for (auto it: A) {
		//     cout << it.first << ' ' << it.second << '\n';
		// }
		// cout << string(10, '-') << endl;
		if (cnt.count(s)) {
			int old = cnt[s];
			Info rem(s, old);
			if (A.count(rem))
				A.erase(A.find(rem));
			cnt[s] += amount;
			Info add(s, old + amount);
			A.insert(add);
		} else {
			cnt[s] = amount;
			Info add(s, amount);
			A.insert(add);
		}
	}

	vector<string> top(int k) {
		vector<string> ans;
		auto it = A.rbegin();
		while (k > 0 && it != A.rend()) {
			ans.push_back(it->stock);
			it++;
			k--;
		}
		return ans;
	}
};

int main() {
	return 0;
}
