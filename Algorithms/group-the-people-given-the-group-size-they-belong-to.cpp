/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
 *
 * https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/
 *
 * algorithms
 * Medium (84.63%)
 * Likes:    23
 * Dislikes: 2
 * Total Accepted:    3.2K
 * Total Submissions: 3.8K
 * Testcase Example:  '[3,3,3,3,3,1,3]'
 *
 * There are n people whose IDs go from 0 to n - 1 and each person belongs
 * exactly to one group. Given the array groupSizes of length n telling the
 * group size each person belongs to, return the groups there are and the
 * people's IDs each group includes.
 * 
 * You can return any solution in any order and the same applies for IDs. Also,
 * it is guaranteed that there exists at least one solution. 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: groupSizes = [3,3,3,3,3,1,3]
 * Output: [[5],[0,1,2],[3,4,6]]
 * Explanation: 
 * Other possible solutions are [[2,1,6],[5],[0,4,3]] and
 * [[5],[0,6,2],[4,3,1]].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: groupSizes = [2,1,3,3,3,2]
 * Output: [[1],[0,5],[2,3,4]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * groupSizes.length == n
 * 1 <= n <= 500
 * 1 <= groupSizes[i] <= n
 * 
 * 
 */

// @lc code=start
class Solution {
    typedef array<int, 2> Element;
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int sz = groupSizes.size();
        vector<Element> A(sz);
        for (int i = 0; i < sz; ++i)
        {
            A[i][0] = groupSizes[i];
            A[i][1] = i;
        }
        sort(A.begin(), A.end());
        vector<vector<int>> result;
        int i = 0;
        while (i < sz)
        {
            int n = A[i][0];
            vector<int> tmp;
            while (n-- > 0)
            {
                tmp.push_back(A[i++][1]);
            }
            result.push_back(tmp);
        }
        return result;
    }
};
// @lc code=end

