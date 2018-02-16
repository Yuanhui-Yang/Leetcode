719. Find K-th Smallest Pair Distance
https://leetcode.com/problems/find-k-th-smallest-pair-distance/

Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        int a = 0, b = nums.back() - nums.front();
        while (a < b) {
            int c = a + (b - a) / 2, cnt = f1(nums, c);
            if (cnt < k) {
                a = c + 1;
            }
            else {
                b = c;
            }
        }
        return a;
    }
private:
    int f1(vector<int>& nums, int c) {
        int sz = nums.size(), i = 0, j = 0, result = 0;
        for (j = 0; j < sz; ++j) {
            while (i < j and nums[j] - nums[i] > c) {
                ++i;
            }
            result += j - i;
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int k, result;
    
    nums = {1, 3, 1};
    result = solution.smallestDistancePair(nums, k);
    cout << result << '\n';
    
    return 0;
}