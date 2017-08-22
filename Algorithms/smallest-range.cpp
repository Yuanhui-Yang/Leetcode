// 632. Smallest Range
// https://leetcode.com/problems/smallest-range/

/*
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Note:
The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.
For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.
*/

class Solution {
public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		int k = nums.size();
		multiset<array<int, 4>> tree;
		for (int i = 0; i < k; ++i) {
			if (nums[i].empty()) {
				return {};
			}
			else {
				tree.insert({nums[i][0], i, 0, nums[i].size()});
			}
		}
		int A = 0, B = INT_MAX;
		while (1) {
			array<int, 4> a = *begin(tree), b = *prev(end(tree));
			if (b[0] - a[0] < B - A) {
				A = a[0];
				B = b[0];
			}
			else if (b[0] - a[0] == B - A and a[0] < A) {
				A = a[0];
				B = b[0];
			}
			++a[2];
			if (a[2] < a[3]) {
				tree.erase(begin(tree));
				tree.insert({nums[a[1]][a[2]], a[1], a[2], a[3]});
			}
			else {
				return {A, B};
			}
		}
		return {A, B};
	}
};