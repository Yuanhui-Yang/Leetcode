// 402. Remove K Digits
// https://leetcode.com/problems/remove-k-digits/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	string removeKdigits(string num, int k) {
		string result = helper(num, k);
		if (result.empty()) return "0";
		const int result_size = result.size();
		int i = 0;
		for (i = 0; i < result_size && result[i] == '0'; i++) ;
		if (i == result_size) return "0";
		return result.substr(i);
	}
private:
	string helper(string num, int k) {
		if (!k) return num;
		const int num_size = num.size();
		if (k >= num_size) return "";
		int j = 0;
		for (int i = 0; i <= k && i < num_size; i++) {
			if (num[j] > num[i]) {
				j = i;
			}
		}
		string result;
		result.push_back(num[j]);
		result += helper(num.substr(j + 1), k - j);
		return result;
	}
};
int main(void) {
	Solution solution;
	assert("1219" == solution.removeKdigits("1432219", 3));
	assert("200" == solution.removeKdigits("10200", 1));
	assert("0" == solution.removeKdigits("10", 2));
	cout << "\nPassed All\n";
	return 0;
}