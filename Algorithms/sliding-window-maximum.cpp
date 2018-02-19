239. Sliding Window Maximum
https://leetcode.com/problems/sliding-window-maximum/

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        list<int> curr;
        int sz = nums.size(), i = 0;
        while (i < sz and i < k) {
            f1(curr, nums[i]);
            ++i;
        }
        if (!curr.empty()) {
            result.push_back(curr.front());
        }
        while (i < sz) {
            if (nums[i - k] == curr.front()) {
                curr.pop_front();
            }
            f1(curr, nums[i]);
            if (!curr.empty()) {
                result.push_back(curr.front());
            }
            ++i;
        }
        return result;
    }
private:
    void f1(list<int> & curr, int val) {
        while (!curr.empty() and curr.back() < val) {
            curr.pop_back();
        }
        curr.push_back(val);
    }
};

int main(void) {
    Solution solution;
    vector<int> nums, result;
    int k;
    
    nums = {1, 3, -1, -3, 5, 3, 6, 7};
    k = 3;
    result = solution.maxSlidingWindow(nums, k);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}