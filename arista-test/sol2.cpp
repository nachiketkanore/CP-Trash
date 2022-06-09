#include <bits/stdc++.h>
using namespace std;

/*
   - big file {
   - string input
   - number of occurences of input

   S = aababaasdfasdfasdfasdfasdf O(N)
   input = aba O(M)
   window = bab
   window = aba
	space: O(M)
*/

int solve(const string input, const string name = "file.txt") {
	freopen(name.c_str(), "r", stdin);

	int occurences = 0;
	string window;
	char ch;
	while (cin >> ch) {
		window += ch;
		if (window.size() > input.size()) {
			window = window.substr(1);
		}

		if (window == input) {
			occurences++;
		}
	}

	return occurences;
}

struct Node {
	string name;
	Node* next;
};

// A->B->C->D->E: playlist
// shuffle
// B->C->D->E-A

void shuffle_playlist(Node* head) {
	// O(N^2)

	// A->B->C->D->E: playlist
	// 0  1  2  3  4
	// 2  1  3  0  4

	// generate a random permutation
	// 0 1 2 3 4 5
	// ITER = 100
	// generate i, j
	// swap(P[i], P[j])
}

int main() {

	cout << solve("aba") << '\n';
	return 0;
}
