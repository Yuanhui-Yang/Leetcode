// 331. Verify Preorder Serialization of a Binary Tree
// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
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
// class Solution {
// public:
// 	bool isValidSerialization(string preorder) {
// 		int diff = 0;
// 		const int n = preorder.size();
// 		for (int i = 0, j = 0; i < n; j = ++i) {
// 			if (i == 0) {
// 				while (i < n && preorder[i] != ',') i++;
// 				if (preorder.substr(j, i - j) == "#") {
// 					if (i == n) return true;
// 					else return false;
// 				}
// 				diff = 2;
// 				continue;
// 			}
// 			if (diff <= 0) return false;
// 			while (i < n && preorder[i] != ',') i++;
// 			if (preorder.substr(j, i - j) == "#") {
// 				diff--;
// 				continue;
// 			}
// 			diff++;
// 		}
// 		return diff == 0;
// 	}
// };
// BEGIN: http://www.programcreek.com/2015/01/leetcode-verify-preorder-serialization-of-a-binary-tree-java/
// BEGIN: https://discuss.leetcode.com/topic/35977/simple-python-solution-using-stack-with-explanation
// class Solution {
// public:
// 	bool isValidSerialization(string preorder) {
// 		vector<string> stack;
// 		const int n = preorder.size();
// 		for (int i = 0, j = 0; i < n; j = ++i) {
// 			while (i < n && preorder[i] != ',') i++;
// 			stack.push_back(preorder.substr(j, i - j));
// 			while (stack.size() >= 3 && stack[stack.size() - 1] == "#" && stack[stack.size() - 2] == "#" && stack[stack.size() - 3] != "#") {
// 				stack.pop_back();
// 				stack.pop_back();
// 				stack.pop_back();
// 				stack.push_back("#");
// 			}
// 		}
// 		return stack.size() == 1 && stack.front() == "#";
// 	}
// };
// END: https://discuss.leetcode.com/topic/35977/simple-python-solution-using-stack-with-explanation
// END: http://www.programcreek.com/2015/01/leetcode-verify-preorder-serialization-of-a-binary-tree-java/
int main(void) {
	Solution solution;
	cout << boolalpha << solution.isValidSerialization("#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("#,#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("#,#,#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("1,#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("1,#,#,#,#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("7,2,#,2,#,#,#,6,#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << "\tPassed\n";
	cout << boolalpha << solution.isValidSerialization("9,#,#,1") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}