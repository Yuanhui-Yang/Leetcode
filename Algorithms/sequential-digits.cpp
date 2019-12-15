/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 *
 * https://leetcode.com/problems/sequential-digits/description/
 *
 * algorithms
 * Medium (47.71%)
 * Likes:    22
 * Dislikes: 4
 * Total Accepted:    3K
 * Total Submissions: 6.2K
 * Testcase Example:  '100\n300'
 *
 * An integer has sequential digits if and only if each digit in the number is
 * one more than the previous digit.
 * 
 * Return a sorted list of all the integers in the range [low, high] inclusive
 * that have sequential digits.
 * 
 * 
 * Example 1:
 * Input: low = 100, high = 300
 * Output: [123,234]
 * Example 2:
 * Input: low = 1000, high = 13000
 * Output: [1234,2345,3456,4567,5678,6789,12345]
 * 
 * 
 * Constraints:
 * 
 * 
 * 10 <= low <= high <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        return f1(low, high);
    }
private:
    vector<int> f1(long low, long high)
    {
        vector<int> result;
        for (long i = 1; i < 9; ++i)
        {
            long j = i;
            while (j <= high and (1 <= j % 10) and (j % 10 <= 9))
            {
                if (low <= j)
                {
                    result.push_back(j);
                }
                j = 10 * j + (j % 10 + 1);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
// @lc code=end