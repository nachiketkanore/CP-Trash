/**
 *    Author: Nachiket Kanore
 *    Created: Friday 13 August 2021 03:59:05 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

class Name {
	public:
	string fname, lname;
	Name(const string& fname, const string& lname) : fname(fname), lname(lname) {
	}
	void print() {
		cout << "First Name: " << fname << '\n';
		cout << "Second Name: " << lname << '\n';
	}
};

void Tests() {
	cout << "HELLO WORLD\n";
}

void test3() {
	struct LinkedList {
		struct Node {
			Node* next;
			Node* prev;
			int value;
			Node(int value, Node* next, Node* prev) : next(next), prev(prev), value(value) {
			}
		};
		Node* root;
		LinkedList() {
			root = new Node(0, NULL, NULL);
		}
	};
}

void test2() {
	cout << "HELLO WORLD\n";
}

int Main() {
	return -1;
}

void test() {
	int n;
	cin >> n;
	int A[n];
	memset(A, -1, sizeof(A));
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
}

int32_t main() {
	srand(time(0));
	pair<int, int> f = make_pair(20, 21);
	auto [one, two] = f;
	cout << one << ' ' << two << endl;
}
