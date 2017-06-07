// 600. Non-negative Integers without Consecutive Ones
// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/

/*
Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain consecutive ones.

Example 1:
Input: 5
Output: 5
Explanation: 
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
Note: 1 <= n <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findIntegers(int num) {
		vector<int> OPT(32, 0);
		OPT[0] = 1;
		OPT[1] = 2;
		for (int i = 2; i < 32; ++i) {
			OPT[i] = OPT[i - 1] + OPT[i - 2];
		}
		size_t result = 0, flag = 1;
		string s = bitset<32>(num).to_string();
		for (int i = 0; flag and i < 32; ++i) {
			if (s[i] == '0') {
				continue;
			}
			if (i > 0 and s[i - 1] == '1') {
				flag = 0;
			}
			result += OPT[31 - i];
		}
		return result + flag;
	}
};

int main(void) {
	Solution solution;
	int num, answer, result;

	num = 5;
	answer = 5;
	result = solution.findIntegers(num);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}