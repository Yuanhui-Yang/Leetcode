/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (49.62%)
 * Likes:    927
 * Dislikes: 52
 * Total Accepted:    227.2K
 * Total Submissions: 456.2K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        f1(result, path, 1, n, k);
        return result;
    }
private:
    void f1(vector<vector<int>>& result, vector<int>& path, int lower, int upper, int k)
    {
        if (k == 0)
        {
            result.push_back(path);
        }
        else if (k > 0)
        {
            for (int i = lower; i <= upper; ++i)
            {
                path.push_back(i);
                f1(result, path, i + 1, upper, k - 1);
                path.pop_back();
            }
        }
    }
};