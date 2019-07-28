1140. Stone Game II
https://leetcode.com/problems/stone-game-ii/

Alex and Lee continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alex and Lee take turns, with Alex starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alex and Lee play optimally, return the maximum number of stones Alex can get.

 

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alex takes one pile at the beginning, Lee takes two piles, then Alex takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles in total. If Alex takes two piles at the beginning, then Lee can take all three piles left. In this case, Alex get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
 

Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 10 ^ 4

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<array<int, 2>>>> A(2, vector<vector<array<int, 2>>>(101, vector<array<int, 2>>(101, array<int, 2>({-1, -1}))));
        return f1(A, piles, 0, 0, 1)[0];
    }
private:
    array<int, 2> f1(vector<vector<vector<array<int, 2>>>> & A, vector<int>& piles, int turn, int start, int M)
    {
        int sz = piles.size();
        M = min(M, sz);
        if (A[turn][start][M][0] >= 0)
        {
            return A[turn][start][M];
        }
        array<int, 2> result;
        result.fill(0);
        for (int i = start, sum = 0; i < sz and i < start + 2 * M; ++i)
        {
            sum += piles[i];
            array<int, 2> tmp = f1(A, piles, 1 - turn, i + 1, max(1 + i - start, M));
            if (result[turn] < sum + tmp[turn])
            {
                result[turn] = sum + tmp[turn];
                result[1 - turn] = tmp[1 - turn];
            }
        }
        return A[turn][start][M] = result;
    }
};