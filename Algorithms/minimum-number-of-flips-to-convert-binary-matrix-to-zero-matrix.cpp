/*
 * @lc app=leetcode id=1284 lang=cpp
 *
 * [1284] Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
 *
 * https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/description/
 *
 * algorithms
 * Hard (69.93%)
 * Likes:    18
 * Dislikes: 6
 * Total Accepted:    1.6K
 * Total Submissions: 2.3K
 * Testcase Example:  '[[0,0],[0,1]]\r'
 *
 * Given a m x n binary matrix mat. In one step, you can choose one cell and
 * flip it and all the four neighbours of it if they exist (Flip is changing 1
 * to 0 and 0 to 1). A pair of cells are called neighboors if they share one
 * edge.
 * 
 * Return the minimum number of steps required to convert mat to a zero matrix
 * or -1 if you cannot.
 * 
 * Binary matrix is a matrix with all cells equal to 0 or 1 only.
 * 
 * Zero matrix is a matrix with all cells equal to 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[0,0],[0,1]]
 * Output: 3
 * Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally
 * (1, 1) as shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[0]]
 * Output: 0
 * Explanation: Given matrix is a zero matrix. We don't need to change it.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: mat = [[1,1,1],[1,0,1],[0,0,0]]
 * Output: 6
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: mat = [[1,0,0],[1,0,0]]
 * Output: -1
 * Explanation: Given matrix can't be a zero matrix
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[0].length
 * 1 <= m <= 3
 * 1 <= n <= 3
 * mat[i][j] is 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        map<vector<vector<int>>, int> A;
        return f1(A, mat, 0);
    }
private:
    int f1(map<vector<vector<int>>, int>& A, vector<vector<int>>& mat, int start)
    {
        int X = mat.size();
        int Y = X ? mat[0].size() : 0;
        bool flag = false;
        for (int i = 0; i < X and !flag; ++i)
        {
            for (int j = 0; j < Y and !flag; ++j)
            {
                if (mat[i][j])
                {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
        {
            return 0;
        }
        if (A.count(mat))
        {
            return A[mat];
        }
        if (start >= X * Y)
        {
            return -1;
        }
        int result = -1;

        int x = start / Y;
        int y = start % Y;

        this->f2(mat, x, y);
        int nresult = this->f1(A, mat, start + 1);
        if (nresult >= 0)
        {
            if (result < 0 or nresult + 1 < result)
            {
                result = nresult + 1;
            }
        }
        this->f2(mat, x, y);
        
        nresult = this->f1(A, mat, start + 1);
        if (nresult >= 0)
        {
            if (result < 0 or nresult < result)
            {
                result = nresult;
            }
        }
        
        return A[mat] = result;
    }
    void f2(vector<vector<int>>& mat, int x, int y)
    {
        int X = mat.size(), Y = X ? mat[0].size() : 0;
        array<int, 4> dx = {-1, 0, 1, 0};
        array<int, 4> dy = {0, -1, 0, 1};
        mat[x][y] = 1 - mat[x][y];
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx and nx < X and 0 <= ny and ny < Y)
            {
                mat[nx][ny] = 1 - mat[nx][ny];
            }
        }
    }
};
// @lc code=end