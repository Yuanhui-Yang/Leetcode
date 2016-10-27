// 331. Verify Preorder Serialization of a Binary Tree
// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
#include <iostream>
#include <string>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/35976/7-lines-easy-java-solution/
class Solution {
public:
	bool isValidSerialization(string preorder) {
		int diff = 1;
		for (size_t i = 0, j = 0; i < preorder.size(); j = ++i) {
			if (--diff < 0) return false;
			while (i < preorder.size() && preorder[i] != ',') i++;
			if (preorder.substr(j, i - j) != "#") diff += 2;
		}
		return diff == 0;
	}
};
// END: https://discuss.leetcode.com/topic/35976/7-lines-easy-java-solution/
int main(void) {
	Solution solution;
	cout << boolalpha << solution.isValidSerialization("#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("#,#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("#,#,#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("7,2,#,2,#,#,#,6,#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("1,#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("9,#,#,1") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}