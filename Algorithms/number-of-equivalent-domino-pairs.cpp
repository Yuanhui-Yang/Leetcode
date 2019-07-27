1128. Number of Equivalent Domino Pairs
https://leetcode.com/problems/number-of-equivalent-domino-pairs/

Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

 

Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
 

Constraints:

1 <= dominoes.length <= 40000
1 <= dominoes[i][j] <= 9

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> A;
        int result = 0;
        for (auto & i : dominoes)
        {
            int key = f1(i);
            unordered_map<int, int>::iterator it = A.find(key);
            if (it != A.end())
            {
                result += it->second;
            }
            ++A[key];
        }
        return result;
    }
private:
    int f1(vector<int> & domino)
    {
        sort(domino.begin(), domino.end());
        return 10 * domino[0] + domino[1];
    }
};