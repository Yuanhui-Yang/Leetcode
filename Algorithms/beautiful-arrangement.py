526. Beautiful Arrangement
https://leetcode.com/problems/beautiful-arrangement/

Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

 

Example 1:

Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 15

class Solution:
    def countArrangement(self, n: int) -> int:
        A = [set() for i in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if i % j == 0 or j % i == 0:
                    A[i].add(j)
        B = [True for i in range(n + 1)]
        
        def f1(start):
            if start > n:
                return 1
            result = 0
            for i in A[start]:
                if B[i]:
                    B[i] = False
                    result += f1(start + 1)
                    B[i] = True
            return result
        
        return f1(1)

if __name__ == "__main__":
    sol = Solution()
    n = 15
    A = [0 for i in range(n)]
    for i in range(n):
        A[i] = sol.countArrangement(i + 1)
    print(A)