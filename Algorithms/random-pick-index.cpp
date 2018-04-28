398. Random Pick Index
https://leetcode.com/problems/random-pick-index/

Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int result = -1;
        for (int sz = nums.size(), cnt = 0, i = 0; i < sz; ++i) {
            if (nums[i] == target) {
                ++cnt;
                if (rand() % cnt == 0) {
                    result = i;
                }
            }
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
    vector<int> nums;
    int result;

    nums = {1, 2, 3, 3, 3};
    Solution solution(nums);
    result = solution.pick(3);
    cout << result << '\n';
    result = solution.pick(1);
    cout << result << '\n';

    return 0;
}
