// 248. Strobogrammatic Number III
// https://leetcode.com/problems/strobogrammatic-number-iii/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <iterator>
#include <map>
using namespace std;
class Solution {
public:
	int strobogrammaticInRange(string low, string high) {
		const int low_size = low.size();
		const int high_size = high.size();
		if (low_size > high_size) return 0;
		if (low_size == high_size && low > high) return 0;
		map<char, char> rbtree;
		rbtree['0'] = '0';
		rbtree['1'] = '1';
		rbtree['6'] = '9';
		rbtree['8'] = '8';
		rbtree['9'] = '6';
		if (low_size == high_size) {

		}
	}
private:
	bool helper(const string& str) {
		
	}
};
// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	int strobogrammaticInRange(string low, string high) {
// 		const int low_size = low.size();
// 		const int high_size = high.size();
// 		if (low_size > high_size) return 0;
// 		if (low_size == high_size && low > high) return 0;
// 		vector<char> hashmap(256, 0);
// 		hashmap['0'] = '0';
// 		hashmap['1'] = '1';
// 		hashmap['6'] = '9';
// 		hashmap['8'] = '8';
// 		hashmap['9'] = '6';
// 		int result = 0;
// 		const string high_next = str_next(high);
// 		for (string str = low; str != high_next; str = str_next(str)) {
// 			const int str_size = str.size();
// 			int i = 0, j = str_size - 1;
// 			while (i < j) {
// 				const char c_i = str[i];
// 				const char c_j = str[j];
// 				if (hashmap[c_i] == c_j) {
// 					i++;
// 					j--;
// 				}
// 				else break;
// 			}
// 			if (str_size & 1) {
// 				if (i == j) {
// 					if (str[i] == '0') {
// 						result++;
// 					}
// 					else if (str[i] == '1') {
// 						result++;
// 					}
// 					else if (str[i] == '8') {
// 						result++;
// 					}
// 					else continue;
// 				}
// 				else continue;
// 			}
// 			else {
// 				if (i == (j + 1)) {
// 					result++;
// 				}
// 				else continue;
// 			}
// 		}
// 		return result;
// 	}
// private:
// 	string str_next(string str) {
// 		const int str_size = str.size();
// 		int carry = 1;
// 		for (int i = str_size - 1; i >= 0; i--) {
// 			char c = str[i];
// 			int c_val = c - '0';
// 			int new_val = carry + c_val;
// 			carry = new_val / 10;
// 			new_val %= 10;
// 			char new_c = '0' + new_val;
// 			str[i] = new_c;
// 		}
// 		if (carry) {
// 			char new_c = '0' + carry;
// 			str.insert(begin(str), new_c);
// 		}
// 		return str;
// 	}
// };
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	int result = 0;
	result = solution.strobogrammaticInRange("50", "100");
	assert(3 == result);
	result = solution.strobogrammaticInRange("100", "50");
	assert(0 == result);
	result = solution.strobogrammaticInRange("10000001", "20000000");
	assert(125 == result);
	cout << "\nPassed All\n";
	return 0;
}