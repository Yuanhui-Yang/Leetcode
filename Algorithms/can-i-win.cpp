// 464. Can I Win
// https://leetcode.com/problems/can-i-win/

/*
In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
*/

class Solution {
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (maxChoosableInteger * (1 + maxChoosableInteger) < desiredTotal * 2) {
			return false;
		}
		if (desiredTotal <= 0) {
			return true;
		}
		unordered_map<bitset<20>, bool> A;
		bitset<20> B;
		return f(A, B, maxChoosableInteger, desiredTotal);
	}
private:
	bool f(unordered_map<bitset<20>, bool> & A, bitset<20> & B, int maxVal, int curr) {
		if (A.count(B)) {
			return A[B];
		}
		for (int i = 0; i < maxVal; ++i) {
			if (!B[i]) {
				B[i] = 1;
				if (i + 1 >= curr or !f(A, B, maxVal, curr - i - 1)) {
					B[i] = 0;
					return A[B] = true;
				}
				B[i] = 0;
			}
		}
		return A[B] = false;
	}
};