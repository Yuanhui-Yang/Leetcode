/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (52.92%)
 * Likes:    702
 * Dislikes: 37
 * Total Accepted:    134.7K
 * Total Submissions: 254K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        f1(result, path, 1, k, n);
        return result;
    }
private:
    void f1(vector<vector<int>>& result, vector<int>& path, int lower, int k, int n)
    {
        if (n == 0)
        {
            if (k == 0)
            {
                result.push_back(path);
            }
        }
        else if (n > 0)
        {
            if (k > 0)
            {
                for (int i = lower; i <= 9; ++i)
                {
                    path.push_back(i);
                    f1(result, path, i + 1, k - 1, n - i);
                    path.pop_back();
                }
            }
        }
    }
};