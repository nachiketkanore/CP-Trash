/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 15 March 2022 11:15:52 AM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T, size_t size> ostream& operator<<(ostream& os, const array<T, size>& arr) {
	os << '{';
	string sep;
	for (const auto& x : arr)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> blues, reds, A(N);
	string colors;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> colors;
	for (int i = 0; i < N; i++) {
		if (colors[i] == 'B') {
			blues.push_back(A[i] > N ? N : A[i]);
		} else {
			reds.push_back(A[i] < 1 ? 1 : A[i]);
		}
	}
	sort(blues.begin(), blues.end()); // minus
	sort(reds.begin(), reds.end());	  // plus
	// see(blues, reds);
	if (!reds.empty() && reds.back() > N) {
		cout << "NO\n";
		return 0;
	} else if (!blues.empty() && blues[0] < 1) {
		cout << "NO\n";
		return 0;
	}
	set<int> available;
	for (int i = 1; i <= N; i++) {
		if (!binary_search(blues.begin(), blues.end(), i) && !binary_search(reds.begin(), reds.end(), i)) {
			available.insert(i);
		}
	}
	// for (int x: available) {
	// 	cout << x << ' ';
	// }	cout << '\n';
	bool ok = true;
	for (int i = (int)reds.size() - 1; i >= 0;) {
		int j = i - 1, cnt = 0;
		while (j >= 0 && reds[j] == reds[j + 1])
			cnt++, j--;
		while (cnt--) {
			if (available.empty()) {
				ok = false;
				break;
			}
			available.erase(*available.rbegin());
		}
		i = j;
	}

	for (int i = 0; i < (int)blues.size();) {
		int j = i + 1, cnt = 0;
		while (j < (int)blues.size() && blues[j] == blues[j - 1])
			cnt++, j++;
		while (cnt--) {
			if (available.empty()) {
				ok = false;
				break;
			}
			available.erase(*available.begin());
		}
		i = j;
	}

	if (ok) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
