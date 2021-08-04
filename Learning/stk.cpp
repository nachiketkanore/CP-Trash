/**
 *    Author: Nachiket Kanore
 *    Created: Monday 26 July 2021 12:56:12 AM IST
 *    Task: Program to reverse a Stack using recursion
 *    Time Complexity: O(N * N)
**/
#include <iostream>
#include <vector>

using namespace std;

void insert_bottom(vector<int> &a, int val) {
	if (a.empty()) {
		a.push_back(val);
		return;
	}

	int rem = a.back();
	a.pop_back();
	insert_bottom(a, val);
	a.push_back(rem);
}

void reverse_stack(vector<int>& a) {
	if (a.empty()) return;
	int val = a.back();
	a.pop_back();
	reverse_stack(a);
	insert_bottom(a, val); // O(N)
}


int32_t main() {
	vector<int> a = {1, 2, 3, 4, 5, 6, 7};
	cout << "Before : ";
	for (int x: a) cout << x << ' '; cout << '\n';
	reverse_stack(a);
	cout << "After : ";
	for (int x: a) cout << x << ' '; cout << '\n';
}
