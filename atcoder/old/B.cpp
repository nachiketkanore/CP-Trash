#include <iostream>
#include <map>
#include <cassert>
using namespace std;

void test() {
	int hello_world;
	cin >> hello_world;
	cout << "# " << hello_world << endl;
}

int A[500500];

struct segment_tree {
	static const int N = 1e5 + 5;
	static int n;
	int *st;
	segment_tree(int n) {
		this->n = n;
		st = new int[n << 2];
		for (int i = 0; i < (n << 2); i++) {
			st[i] = 0;
		}
	}
	void build(int u = 1, int tl = 1, int tr = n) {
		if (tl == tr) {
			st[u] = A[tl];
		} else {
			const int mid = (tl + tr) >> 1;
			build(2 * u, tl, mid);
			build(2 * u + 1, mid + 1, tr);
			st[u] = st[2 * u] + st[2 * u + 1];
		}
	}
}

class Trie {
private:
	struct node {
		char ch;
		node* to[26];
		bool is_end = false;
		node(char ch_) {
			ch = ch_;
			for (int i = 0; i < 26; i++) {
				to[i] = nullptr;
			}
		}
		void add_child(char child) {
			assert(this->is_end == false);
			to[child-'a'] = new node(child);
		}
	};
public:
	node* root;
	Trie() {
		root = new node('$');
	}
	void test() {

	}
	void add(const string &add) {
		node* curr = root;
		for (const char& ch: add) {
			if (curr->to[ch-'a'] == nullptr) {
				curr->to[ch-'a'] = new node(ch);
			}
			curr = curr->to[ch-'a'];
		}
		curr->is_end = true;
	}
};

vector<int> test(int n) {
	n <<= 1;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int u;
		cin >> u;
		a.push_back(u);
	}
	return a;
}

void pattern(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0 || i == n-1 || j == n-1) {
				cout << "#";
			}
			else {
				cout << "_";
			}
		}
		cout << '\n';
	}
}

int main() {
	for (int i = 1; i <= 8; i++) {
		pattern(i);
		cout << endl;
	}
}

