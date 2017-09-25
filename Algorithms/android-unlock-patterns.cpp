// 351. Android Unlock Patterns
// https://leetcode.com/problems/android-unlock-patterns/

/*
Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:
Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.

Explanation:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6 
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

Example:
Given m = 1, n = 1, return 9.
*/

#include <iostream>
#include <cassert>
#include <array>

using namespace std;

class Solution {
public:
	int numberOfPatterns(int m, int n) {
		array<bool, 9> A;
		A.fill(false);
		int result = 0;
		for (int step = m; step <= n; ++step) {
			result += f1(A, step, -1);
		}
		return result;
	}
private:
	int f1(array<bool, 9> & A, int step, int prev) {
		if (step == 0) {
			return 1;
		}
		int result = 0;
		for (int i = 0; i < 9; ++i) {
			if (f2(A, i, prev)) {
				A[i] = true;
				result += f1(A, step - 1, i);
				A[i] = false;            
			}
		}
		return result;
	}
	bool f2(array<bool, 9> & A, int curr, int prev) {
		if (prev == -1) {
			return true;
		}
		if (A[curr]) {
			return false;
		}
		if ((prev + curr) % 2) {
			return true;
		}
		int mid = (prev + curr) / 2;
		if (mid == 4 or curr / 3 == prev / 3 or curr % 3 == prev % 3) {
			return A[mid];
		}
		return true;
	}
};

int main(void) {
	Solution solution;
	int m, n, answer, result;

	m = 1;
	n = 2;
	answer = 65;
	result = solution.numberOfPatterns(m, n);
	assert(answer == result);
	
	cout << "\nPassed All\n";
	return 0;
}