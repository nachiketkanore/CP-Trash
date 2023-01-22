/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 12 September 2021 03:23:45 PM IST
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

struct linked_list {
	struct node {
		int val;
		node* next;
		node(int val) : val(val) {
			next = NULL;
		}
		node() {
			val = 0;
			next = NULL;
		}
	};
	node* head;
	linked_list() {
		head = NULL;
	}
	void push_back(int val) {
		if (head == NULL) {
			head = new node(val);
			return;
		}
		node* curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new node(val);
	}
	void print() {
		node* curr = head;
		while (curr != NULL) {
			cout << curr->val << ' ';
			curr = curr->next;
		}
	}
	void print_reverse(node* curr) {
		if (curr == NULL)
			return;
		print_reverse(curr->next);
		cout << curr->val << ' ';
	}
	void print_reverse() {
		node* curr = head;
		print_reverse(curr);
	}
	void clear() {
		node* curr = head;
		while (curr) {
			node* to = curr->next;
			delete (curr);
			curr = to;
		}
		head = NULL;
	}
};

int32_t main() {
	int N;
	cin >> N;
	linked_list list;
	int old = -1;
	FOR(i, 1, N) {
		int val;
		cin >> val;
		if (old == -1 || (old % 2 == val % 2)) {
			list.push_back(val);
		} else {
			assert(~old);
			if (old % 2 == 1)
				list.print();
			else
				list.print_reverse();
			list.clear();
			list.push_back(val);
		}
		old = val % 2;
	}
	if (old % 2 == 1)
		list.print();
	else
		list.print_reverse();
}
