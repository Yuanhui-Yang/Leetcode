1074. Number of Submatrices That Sum to Target
https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

 

Example 1:


Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
Example 3:

Input: matrix = [[904]], target = 0
Output: 0
 

Constraints:

1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8

'''
M, N = min(X, Y), max(X, Y)
Time Complexity: M^2 * N
Space Complexity: M * N
'''

class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        X = len(matrix)
        Y = len(matrix[0]) if X > 0 else 0
        A = [[0 for j in range(Y)] for i in range(X)]
        for i in range(X):
            for j in range(Y):
                val = matrix[i][j]
                if i == 0 and j == 0:
                    A[i][j] = val
                elif i == 0:
                    A[i][j] = val + A[i][j - 1]
                elif j == 0:
                    A[i][j] = val + A[i - 1][j]
                else:
                    A[i][j] = val + A[i][j - 1] + A[i - 1][j] - A[i - 1][j - 1]
        
        result = 0
        for x2 in range(X):
            for x1 in range(x2 + 1):
                tab = collections.Counter()
                tab[0] = 1
                for y in range(Y):
                    area = A[x2][y]
                    if x1 > 0:
                        area -= A[x1 - 1][y]
                    diff = area - target
                    result += tab[diff]
                    tab[area] += 1
        return result