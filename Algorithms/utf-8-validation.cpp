// 393. UTF-8 Validation
// https://leetcode.com/problems/utf-8-validation/
#include <iostream>
#include <vector>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/57195/concise-c-implementation
class Solution {
public:
	bool validUtf8(vector<int>& data) {
		int n = 0;
		for (const auto &i : data) {
			if (n == 0) {
				if ((i >> 5) == 0b110) {
					n = 1;
					continue;
				}
				if ((i >> 4) == 0b1110) {
					n = 2;
					continue;
				}
				if ((i >> 3) == 0b11110) {
					n = 3;
					continue;
				}
				if (i >> 7) return false;
				continue;
			}
			if ((i >> 6) != 0b10) return false;
			n--; 
		}
		return n == 0;
	}
};
// END: https://discuss.leetcode.com/topic/57195/concise-c-implementation
int main(void) {
	Solution solution;
	vector<int> data;
	cout << boolalpha << solution.validUtf8(data) << "\tPassed\n";
	data = {197, 130, 1};
	cout << boolalpha << solution.validUtf8(data) << "\tPassed\n";
	data = {235, 140, 4};
	cout << boolalpha << solution.validUtf8(data) << "\tPassed\n";
	data = {240, 162, 138, 147, 17};
	cout << boolalpha << solution.validUtf8(data) << "\tPassed\n";
	data = {240, 162, 138, 147, 145};
	cout << boolalpha << solution.validUtf8(data) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}