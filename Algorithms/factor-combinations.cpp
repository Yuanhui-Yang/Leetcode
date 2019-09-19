/*
 * @lc app=leetcode id=254 lang=cpp
 *
 * [254] Factor Combinations
 *
 * https://leetcode.com/problems/factor-combinations/description/
 *
 * algorithms
 * Medium (44.94%)
 * Likes:    440
 * Dislikes: 20
 * Total Accepted:    58.5K
 * Total Submissions: 130K
 * Testcase Example:  '1'
 *
 * Numbers can be regarded as product of its factors. For example,
 * 
 * 
 * 8 = 2 x 2 x 2;
 * ⁠ = 2 x 4.
 * 
 * 
 * Write a function that takes an integer n and return all possible
 * combinations of its factors.
 * 
 * Note:
 * 
 * 
 * You may assume that n is always positive.
 * Factors should be greater than 1 and less than n.
 * 
 * 
 * Example 1: 
 * 
 * 
 * Input: 1
 * Output: []
 * 
 * 
 * Example 2: 
 * 
 * 
 * Input: 37
 * Output:[]
 * 
 * Example 3: 
 * 
 * 
 * Input: 12
 * Output:
 * [
 * ⁠ [2, 6],
 * ⁠ [2, 2, 3],
 * ⁠ [3, 4]
 * ]
 * 
 * Example 4: 
 * 
 * 
 * Input: 32
 * Output:
 * [
 * ⁠ [2, 16],
 * ⁠ [2, 2, 8],
 * ⁠ [2, 2, 2, 4],
 * ⁠ [2, 2, 2, 2, 2],
 * ⁠ [2, 4, 4],
 * ⁠ [4, 8]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> path;
        f1(result,  path, n, 2, n, 1);
        return result;
    }
private:
    void f1(vector<vector<int>>& result, vector<int> & path, int n, int lower, int upper, int product)
    {
        if (n > 1)
        {
            if (product == n)
            {
                result.push_back(path);
            }
            else if (product < n)
            {
                for (int i = lower; i < upper; ++i)
                {
                    int target = n / product;
                    if (target % i == 0)
                    {
                        path.push_back(i);
                        f1(result, path, n, i, upper, product * i);
                        path.pop_back();
                    }
                }
            }
        }
    }
};