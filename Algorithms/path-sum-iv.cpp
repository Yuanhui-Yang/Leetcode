// 666. Path Sum IV
// https://leetcode.com/problems/path-sum-iv/

/*
If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

For each integer in this list:
The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.
Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.

Example 1:
Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
	3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.
Example 2:
Input: [113, 221]
Output: 4
Explanation: 
The tree that the list represents is: 
	3
	 \
	  1

The path sum is (3 + 1) = 4.
*/

class Solution {
public:
	int pathSum(vector<int>& nums) {
		int sz = nums.size();
		if (sz == 0) {
			return 0;
		}
		int result = 0;
		vector<int> curr;
		curr.push_back(nums[0] % 10);
		int i = 1, j = 2;
		while (i < sz) {
			vector<int> next(j, 0);
			vector<bool> A(j / 2, true);
			int x = nums[i] / 100, y = (nums[i] % 100) / 10, z = nums[i] % 10;
			next[y - 1] = curr[(y - 1) / 2] + z;
			A[(y - 1) / 2] = false;
			while (i + 1 < sz and nums[i + 1] / 100 == x) {
				++i;
				int ny = (nums[i] % 100) / 10, nz = nums[i] % 10;
				next[ny - 1] = curr[(ny - 1) / 2] + nz;
				A[(ny - 1) / 2] = false;
				y = ny;
			}
			for (int k = 0; k < j / 2; ++k) {
				if (A[k]) {
					result += curr[k];
				}
			}
			curr = next;
			++i;
			j <<= 1;
		}
		result += accumulate(begin(curr), end(curr), 0);
		return result;
	}
};