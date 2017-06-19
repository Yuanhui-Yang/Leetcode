// 38. Count and Say
// https://leetcode.com/problems/count-and-say/

/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string s("1");
		while (n-- > 1) {
			string t;
			for (int m = s.size(), i = 0; i < m; ++i) {
				int j = i;
				while (i + 1 < m and s[i] == s[i + 1]) {
					++i;
				}
				t.append(to_string(i + 1 - j));
				t.push_back(s[j]);
			}
			s =  t;
			}
		return s;
	}
};

int main(void) {
	Solution solution;
	int n;
	string answer, result;

	n = 1;
	answer = "1";
	result = solution.countAndSay(n);
	assert(answer == result);

	n = 4;
	answer = "1211";
	result = solution.countAndSay(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}