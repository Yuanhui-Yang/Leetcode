887. Super Egg Drop
https://leetcode.com/problems/super-egg-drop/

You are given K eggs, and you have access to a building with N floors from 1 to N. 

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 

Your goal is to know with certainty what the value of F is.

What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

 

Example 1:

Input: K = 1, N = 2
Output: 2
Explanation: 
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.
Example 2:

Input: K = 2, N = 6
Output: 3
Example 3:

Input: K = 3, N = 14
Output: 4
 

Note:

1 <= K <= 100
1 <= N <= 10000

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        @cache
        def f1(k, n):
            if k == 1:
                return n
            if n == 0:
                return 0
            result = -1
            left = 1
            right = n + 1
            while left < right:
                mid = (left + right) >> 1
                a = 1 + f1(k, n - mid)
                b = 1 + f1(k - 1, mid - 1)
                if a > b:
                    left = mid + 1
                else:
                    right = mid
            a = 1 + f1(k, n - left)
            b = 1 + f1(k - 1, left - 1)
            result = max(a, b)
            return result
        return f1(K, N)

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        A = [[-1 for i in range(N + 1)] for j in range(K + 1)]
        def f1(k, n):
            if k == 1:
                return n
            if n == 0:
                return 0
            result = A[k][n]
            if result >= 0:
                return result
            left = 1
            right = n + 1
            while left < right:
                mid = (left + right) >> 1
                a = 1 + f1(k, n - mid)
                b = 1 + f1(k - 1, mid - 1)
                if a > b:
                    left = mid + 1
                else:
                    right = mid
            a = 1 + f1(k, n - left)
            b = 1 + f1(k - 1, left - 1)
            result = max(a, b)
            A[k][n] = result
            return result
        return f1(K, N)

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        @cache
        def f1(X, Y):
            if Y == 0:
                return 0
            if X == 1:
                return Y
            result = -1
            for i in range(1, Y + 1):
                a = 1 + f1(X, Y - i)
                b = 1 + f1(X - 1, i - 1)
                c = max(a, b)
                if result < 0 or c < result:
                    result = c
            return result
        return f1(K, N)

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        A = [[-1 for i in range(N + 1)] for j in range(K + 1)]
        def f1(k, n):
            if k == 1:
                return n
            if n == 0:
                return 0
            result = A[k][n]
            if result >= 0:
                return result
            for i in range(1, n + 1):
                a = 1 + f1(k, n - i)
                b = 1 + f1(k - 1, i - 1)
                c = max(a, b)
                if result < 0 or c < result:
                    result = c
            A[k][n] = result
            return result
        return f1(K, N)