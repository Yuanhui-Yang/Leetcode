// 306. Additive Number
// https://leetcode.com/problems/additive-number/
#include <iostream>
#include <cassert>
#include <string>
using namespace std;
class Solution {
public:
	bool isAdditiveNumber(string num) {
		const int n = num.size();
		if (n < 3) return false;
		for (int i = 1; i <= n / 2; i++) {
			if (num[0] == '0' && i > 1) return false;
			string str1 = num.substr(0, i);
			long val1 = stol(str1);
			for (int j = 1; i + j < n; j++) {
				if (num[i] == '0' && j > 1) break;
				string str2 = num.substr(i, j);
				long val2 = stol(str2);
				long val3 = val1 + val2;
				string str3 = to_string(val3);
				int k = str3.size();
				if (i + j + k > n) break;
				if (str3 == num.substr(i + j, k)) {
					if (helper(i, j, k, num)) {
						return true;
					}
				}
			}
		}
		return false;
	}
private:
	bool helper (int i, int j, int k, string& num) {
		const int n = num.size();
		if (n < 3) return false;
		if (i + j + k > n) return false;
		if (i + j + k == n) return true;
		string str1 = num.substr(i, j);
		long val1 = stol(str1);
		string str2 = num.substr(i + j, k);
		long val2 = stol(str2);
		long val3 = val1 + val2;
		string str3 = to_string(val3);
		int l = str3.size();
		if (i + j + k + l > n) return false;
		if (str3 == num.substr(i + j + k, l)) {
			if (helper(i + j, k, l, num)) {
				return true;
			}
		}
		return false;
	}
};
int main(void) {
	Solution solution;
	assert(true == solution.isAdditiveNumber("112358"));
	assert(true == solution.isAdditiveNumber("199100199"));
	assert(false == solution.isAdditiveNumber("11235813213455890144"));
	assert(true == solution.isAdditiveNumber("011235"));
	assert(false == solution.isAdditiveNumber("0235813"));
	assert(false == solution.isAdditiveNumber("120122436"));
	assert(false == solution.isAdditiveNumber("2461016264268110179"));
	assert(true == solution.isAdditiveNumber("121474836472147483648"));
	cout << "\nPassed All\n";
	return 0;
}