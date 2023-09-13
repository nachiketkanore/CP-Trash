#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {
	}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
	}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {
	}
};

class Solution {
	public:
	bool evaluateTree(TreeNode* root) {
		bool ok;
		if (root->left == NULL && root->right == NULL) {
			ok = root->val;
		} else {
			if (root->val == 2) {
				ok = evaluateTree(root->left) | evaluateTree(root->right);
			} else if (root->val == 3) {
				ok = evaluateTree(root->left) & evaluateTree(root->right);
			}
		}
		return ok;
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
