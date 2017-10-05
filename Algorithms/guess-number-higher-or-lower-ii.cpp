// 375. Guess Number Higher or Lower II
// https://leetcode.com/problems/guess-number-higher-or-lower-ii/

/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int getMoneyAmount(int n) {
		if (n <= 1) {
			return 0;
		}
		vector<vector<int>> A(n, vector<int>(n, 0));
		int a, b, i, j, k, l;
		for (i = 2; i <= n; ++i) {
			for (j = 0; i + j <= n; ++j) {
				k = i + j - 1;
				if (i == 2) {
					A[j][k] = j + 1;
				}
				else if (i == 3) {
					A[j][k] = j + 2;
				}
				else {
					a = j + 1 + A[j + 1][k];
					a = min(a, k + 1 + A[j][k - 1]);
					for (l = j + 1; l < k; ++l) {
						b = max(A[j][l - 1] + l + 1, l + 1 + A[l + 1][k]);
						if (b < a) {
							a = b;
						}
					}
					A[j][k] = a;
				}
			}
		}
		return A[0][n - 1];
	}
};


int main(void) {
	Solution solution;
	int n, result;

	n = 7;
	result = solution.getMoneyAmount(n);
	cout << result << '\n';

	n = 10;
	result = solution.getMoneyAmount(n);
	cout << result << '\n';
	
	return 0;
}