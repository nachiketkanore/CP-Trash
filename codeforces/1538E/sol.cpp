/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 26 May 2022 06:43:31 PM IST
 **/
#include "bits/stdc++.h"

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct Variable {
	string var;
	string value;
	int occurences = 0;

	Variable() {
	}
	Variable(const string& var, const string& value) : var(var), value(value) {
		F0R(i, sz(value)) {
			if (value.substr(i, 4) == "haha")
				++occurences;
		}
	}

	string get_left(int cnt) const {
		if (sz(value) < cnt)
			return "";
		return value.substr(0, cnt);
	}

	string get_right(int cnt) const {
		if (sz(value) < cnt)
			return "";
		return value.substr(sz(value) - cnt, cnt);
	}

	void clean_value() {
		if (sz(value) <= 10)
			return;
		value = value.substr(0, 5) + value.substr(sz(value) - 5, 5);
	}
};

void solve() {
	int N;
	cin >> N;

	vector<Variable> vars;
	string last_var;

	auto find_var = [&](string var) {
		F0R(i, sz(vars)) {
			if (vars[i].var == var) {
				return i;
			}
		}
		return int(-1);
	};

	auto merge = [&](const Variable& one, const Variable& two, string var) {
		Variable ret;
		ret.var = var;
		ret.occurences = one.occurences + two.occurences;
		ret.value = one.value + two.value;
		ret.clean_value();

		FOR(L, 1, 3) {
			int R = 4 - L;
			if (one.get_right(L) + two.get_left(R) == "haha") {
				ret.occurences++;
			}
		}

		return ret;
	};

	while (N--) {
		string x;
		cin >> x;
		last_var = x;
		string op;
		cin >> op;

		if (op == ":=") {
			string s;
			cin >> s;
			int id = find_var(x);
			if (id == -1) {
				vars.push_back(Variable(x, s));
			} else {
				vars[id] = Variable(x, s);
			}
		} else if (op == "=") {
			string a, b;
			cin >> a >> op >> b;

			int id = find_var(x), i = find_var(a), j = find_var(b);
			assert(~i && ~j);
			if (~id) {
				vars[id] = merge(vars[i], vars[j], x);
			} else {
				vars.push_back(merge(vars[i], vars[j], x));
			}
		} else {
			assert(false);
		}
	}

	int id = find_var(last_var);
	assert(~id);
	cout << vars[id].occurences << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
