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
        string result;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                result = "1";
            }
            else {
                string s;
                int sz = result.size(), j = 0;
                while (j < sz) {
                    int cnt = 1;
                    while (j + 1 < sz and result[j] == result[j + 1]) {
                        ++cnt;
                        ++j;
                    }
                    s.append(to_string(cnt));
                    s.push_back(result[j]);
                    ++j;
                }
                result = s;
            }
        }
        return result;
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
