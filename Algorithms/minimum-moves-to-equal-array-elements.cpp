// 453. Minimum Moves to Equal Array Elements
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int minMoves(vector<int>& nums) {
		return accumulate(begin(nums), end(nums), 0) - nums.size() * (*min_element(begin(nums), end(nums)));
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {1, 2, 3};
	cout << solution.minMoves(nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}