/*
 * @lc app=leetcode id=1292 lang=cpp
 *
 * [1292] Maximum Side Length of a Square with Sum Less than or Equal to Threshold
 *
 * https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/
 *
 * algorithms
 * Medium (35.59%)
 * Likes:    32
 * Dislikes: 0
 * Total Accepted:    1.9K
 * Total Submissions: 5.3K
 * Testcase Example:  '[[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]\n4'
 *
 * Given a m x n matrix mat and an integer threshold. Return the maximum
 * side-length of a square with a sum less than or equal to threshold or return
 * 0 if there is no such square.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold =
 * 4
 * Output: 2
 * Explanation: The maximum side length of square with sum less than 4 is 2 as
 * shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]],
 * threshold = 1
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
 * Output: 3
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]],
 * threshold = 40184
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m, n <= 300
 * m == mat.length
 * n == mat[i].length
 * 0 <= mat[i][j] <= 10000
 * 0 <= threshold <= 10^5
 * 
 */

// @lc code=start
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        f0(mat);
        int X = mat.size();
        int Y = X ? mat[0].size() : 0;
        int i = 1;
        int j = min(X, Y) + 1;
        while (i < j)
        {
            int k = (i + j) >> 1;
            if (f1(mat, threshold, k))
            {
                i = k + 1;
            }
            else
            {
                j = k;
            }
        }
        return --i;
    }
private:
    void f0(vector<vector<int>>& mat)
    {
        int X = mat.size();
        int Y = X ? mat[0].size() : 0;
        for (int i = 0; i < X; ++i)
        {
            for (int j = 1; j < Y; ++j)
            {
                mat[i][j] += mat[i][j - 1];
            }
        }
        for (int i = 1; i < X; ++i)
        {
            for (int j = 0; j < Y; ++j)
            {
                mat[i][j] += mat[i - 1][j];
            }
        }
    }
    bool f1(vector<vector<int>>& mat, int threshold, int distance)
    {
        int X = mat.size();
        int Y = X ? mat[0].size() : 0;
        for (int top = 0; top + distance <= X; ++top)
        {
            int bottom = top + distance - 1;
            for (int left = 0; left + distance <= Y; ++left)
            {
                int right = left + distance - 1;
                int sum = top == 0 ? left == 0 ? mat[bottom][right] : mat[bottom][right] - mat[bottom][left - 1] : left == 0 ? mat[bottom][right] - mat[top - 1][right] : mat[bottom][right] - mat[bottom][left - 1] - mat[top - 1][right] + mat[top - 1][left - 1];
                if (sum <= threshold)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end