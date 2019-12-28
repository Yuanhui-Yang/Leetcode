/*
 * @lc app=leetcode id=1296 lang=cpp
 *
 * [1296] Divide Array in Sets of K Consecutive Numbers
 *
 * https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/
 *
 * algorithms
 * Medium (47.19%)
 * Likes:    88
 * Dislikes: 4
 * Total Accepted:    5.8K
 * Total Submissions: 12.2K
 * Testcase Example:  '[1,2,3,3,4,4,5,6]\n4'
 *
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into sets of k consecutive numbers
 * Return True if its possible otherwise return False.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,3,4,4,5,6], k = 4
 * Output: true
 * Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
 * Output: true
 * Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and
 * [9,10,11].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,3,2,2,1,1], k = 3
 * Output: true
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [1,2,3,4], k = 3
 * Output: false
 * Explanation: Each array should be divided in subarrays of size 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= nums.length
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int sz = nums.size();
        if (sz % k)
        {
            return false;
        }
        map<int, int> A;
        for (const auto& i : nums)
        {
            ++A[i];
        }
        while (A.size() >= k)
        {
            int cnt = 0;
            int minFreq = INT_MAX;
            int curr = A.begin()->first;
            for (map<int, int>::iterator it = A.begin(); it != A.end() and cnt < k; ++it, ++cnt, ++curr)
            {
                if (it->first != curr)
                {
                    return false;
                }
                minFreq = min(minFreq, it->second);
            }
            queue<map<int, int>::iterator> toDelete;
            cnt = 0;
            for (map<int, int>::iterator it = A.begin(); it != A.end() and cnt < k; ++it, ++cnt)
            {
                it->second -= minFreq;
                if (it->second == 0)
                {
                    toDelete.push(it);
                }
            }
            while (!toDelete.empty())
            {
                A.erase(toDelete.front());
                toDelete.pop();
            }
        }
        return A.empty();
    }
};
// @lc code=end

