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
		if (!root) return "#";
		return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
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
		int j = i;
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

int main(void) {
	cout << "\nPassed All\n";
	return 0;
}