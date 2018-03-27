27. Remove Element
https://leetcode.com/problems/remove-element/

Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size(), i = 0, j = 0;
        while (j < sz) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                ++i;
            }
            ++j;
        }
        return i;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int val, result;
    
    nums = {3, 2, 2, 3};
    val = 3;
    result = solution.removeElement(nums, val);
    for (int i = 0; i < result; ++i) {
        cout << nums[i] << '\t';
    }
    cout << '\n';
    
    return 0;
}
