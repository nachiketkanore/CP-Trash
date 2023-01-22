/**
 *    Author: Nachiket Kanore
 *    Created: Friday 04 February 2022 10:20:18 PM IST
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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int A[N];
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		int k = 1;
		for (int rep = 0; rep < 2; rep++) {
			int each = 0;
			for (int i = 0; i < N; i++) {
				each += A[i];
				if (true) {
					int parts = 1;
					int curr = 0;
					bool complete = false;
					for (int j = i + 1; j < N; j++) {
						curr += A[j];
						complete = false;
						if (curr == each) {
							++parts;
							curr = 0;
							complete = true;
						}
					}
					// see(each, complete);
					if (complete) {
						// see("here");
						// see(i, each, parts);
						if (parts > k) {
							k = parts;
						}
					}
				}
			}
			reverse(A, A + N);
		}
		cout << (N - k) << '\n';
	}
	return 0;
}
