// 449. Serialize and Deserialize BST
// https://leetcode.com/problems/serialize-and-deserialize-bst/
#include <iostream>
#include <cassert>
#include <string>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		return root ? to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right) : "#";

	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int i = 0;
		return deserialize(i, data);
	}
private:
	TreeNode* deserialize(int& i, const string& data) {
		const int data_size = data.size();
		if (i >= data_size) return NULL;
		if (data[i] == '#') {
			i += 2;
			return NULL;
		}
		const int j = i;
		while (i < data_size && data[i] != ',') i++;
		TreeNode *root = new TreeNode(stoi(data.substr(j, i++ - j)));
		root->left = deserialize(i, data);
		root->right = deserialize(i, data);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

bool helper(TreeNode* root, TreeNode* result) {
	if (!root && !result) return true;
	if (!root && result) return false;
	if (root && !result) return false;
	if (root->val != result->val) return false;
	return helper(root->left, result->left) && helper(root->right, result->right);
}
 
int main(void) {
	Codec codec;
	TreeNode *root = NULL;
	root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	TreeNode *result = codec.deserialize(codec.serialize(root));
	assert(helper(root, result));
	cout << "\nPassed All\n";
	return 0;
}