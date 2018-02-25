128. Longest Consecutive Sequence
https://leetcode.com/problems/longest-consecutive-sequence/

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> A;
        int result = 0;
        for (const auto & i : nums) {
            if (!A.count(i)) {
                int left = A.count(i - 1) ? A[i - 1] : 0, right = A.count(i + 1) ? A[i + 1] : 0, total = left + 1 + right;
                if (result < total) {
                    result = total;
                }
                A[i] = total;
                A[i - left] = total;
                A[i + right] = total;
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int result;
    
    nums = {100, 4, 200, 1, 3, 2};
    result = solution.longestConsecutive(nums);
    cout << result << '\n';
    
    return 0;
}