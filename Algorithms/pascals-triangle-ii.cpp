// 119. Pascal's Triangle II
// https://leetcode.com/problems/pascals-triangle-ii/

/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result(rowIndex + 1);
		for (int i = 0; i <= rowIndex; ++i) {
			if (i == 0 or i == rowIndex) {
				result[i] = 1;
			}
			else {
				result[i] = result[i - 1] * double(rowIndex - i + 1) / i;
			}
		}
		return result;
	}
};