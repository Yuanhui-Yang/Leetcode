/*
 * @lc app=leetcode id=1341 lang=cpp
 *
 * [1341] The K Weakest Rows in a Matrix
 *
 * https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
 *
 * algorithms
 * Easy (67.24%)
 * Likes:    7
 * Dislikes: 2
 * Total Accepted:    4.2K
 * Total Submissions: 6.3K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]\n3'
 *
 * Given a m * n matrix mat of ones (representing soldiers) and zeros
 * (representing civilians), return the indexes of the k weakest rows in the
 * matrix ordered from the weakest to the strongest.
 * 
 * A row i is weaker than row j, if the number of soldiers in row i is less
 * than the number of soldiers in row j, or they have the same number of
 * soldiers but i is less than j. Soldiers are always stand in the frontier of
 * a row, that is, always ones may appear first and then zeros.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = 
 * [[1,1,0,0,0],
 * ⁠[1,1,1,1,0],
 * ⁠[1,0,0,0,0],
 * ⁠[1,1,0,0,0],
 * ⁠[1,1,1,1,1]], 
 * k = 3
 * Output: [2,0,3]
 * Explanation: 
 * The number of soldiers for each row is: 
 * row 0 -> 2 
 * row 1 -> 4 
 * row 2 -> 1 
 * row 3 -> 2 
 * row 4 -> 5 
 * Rows ordered from the weakest to the strongest are [2,0,3,1,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = 
 * [[1,0,0,0],
 * [1,1,1,1],
 * [1,0,0,0],
 * [1,0,0,0]], 
 * k = 2
 * Output: [0,2]
 * Explanation: 
 * The number of soldiers for each row is: 
 * row 0 -> 1 
 * row 1 -> 4 
 * row 2 -> 1 
 * row 3 -> 1 
 * Rows ordered from the weakest to the strongest are [0,2,3,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 2 <= n, m <= 100
 * 1 <= k <= m
 * matrix[i][j] is either 0 or 1.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        typedef array<int, 2> Element;
        priority_queue<Element> max_heap;
        for (int sz = mat.size(), i = 0; i < sz; ++i)
        {
            vector<int>& row = mat[i];
            int cnt = f1(row);
            Element e = {cnt, i};
            max_heap.push(e);
            while (max_heap.size() > k)
            {
                max_heap.pop();
            }
        }
        vector<int> result(max_heap.size());
        for (int sz = max_heap.size(), i = sz - 1; i >= 0; --i)
        {
            result[i] = max_heap.top()[1];
            max_heap.pop();
        }
        return result;
    }
private:
    int f1(vector<int>& row)
    {
        int sz = row.size();
        int i = 0;
        int j = sz;
        while (i < j)
        {
            int k = (i + j) >> 1;
            if (row[k])
            {
                i = k + 1;
            }
            else
            {
                j = k;
            }
        }
        return i;
    }
};
// @lc code=end

