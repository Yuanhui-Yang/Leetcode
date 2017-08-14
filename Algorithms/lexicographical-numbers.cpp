// 386. Lexicographical Numbers
// https://leetcode.com/problems/lexicographical-numbers/

/*
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/

class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<int> result;
		for (int i = 1, j = 0; j < n; ++j) {
			result.push_back(i);
			if (10 * i <= n) {
				i *= 10;
			}
			else if (i % 10 < 9 and i + 1 <= n) {
				++i;
			}
			else {
				if (i >= n) {
					i /= 10;
				}
				while (i > 0 and i % 10 == 9) {
					i /= 10;
				}
				++i;
			}
		}
		return result;
	}
};