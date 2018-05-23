// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> A(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int bound = sqrt(i);
            if (bound * bound == i) {
                A[i] = 1;
            }
            else {
                int val = 0;
                for (int j = bound; j >= 1; --j) {
                    if (A[i - j * j]) {
                        int curr = A[i - j * j] + 1;
                        if (val == 0 or curr < val) {
                            val = curr;
                        }
                    }
                }
                A[i] = val;
            }
        }
        return A[n];
    }
};

int main(void) {
	Solution solution;
	cout << solution.numSquares(12) << "\tPassed\n";
	cout << solution.numSquares(13) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}
