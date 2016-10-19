// 398. Random Pick Index
// https://leetcode.com/problems/random-pick-index/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
class Solution {
public:
	Solution(vector<int> nums): nums(nums) {srand (time(NULL));}

	int pick(int target) {
		int result = 0;
		for (int i = result, n = 1; i < (int)nums.size(); i++) {
			if (nums[i] == target)
				if (rand() % n++ == 0)
					result = i;
		}
		return result;
	}
private:
	vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int main(void) {
	vector<int> nums = {1, 2, 3, 3, 3};
	Solution solution(nums);
	cout << solution.pick(3) << "\tPassed\n";
	cout << solution.pick(1) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}