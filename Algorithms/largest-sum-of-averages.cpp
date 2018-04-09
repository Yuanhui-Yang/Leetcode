813. Largest Sum of Averages
https://leetcode.com/problems/largest-sum-of-averages/

We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input: 
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation: 
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 

Note:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
Answers within 10^-6 of the correct answer will be accepted as correct.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int sz = A.size();
        vector<double> B(sz + 1, 0), C(sz + 1, 0);
        double sum = 0;
        for (int i = 1; i <= sz; ++i) {
            sum += A[i - 1];
            B[i] = sum;
            C[i] = sum / i;
        }
        for (int k = 2; k <= K; ++k) {
            for (int i = sz; i >= k; --i) {
                for (int j = k - 1; j < i; ++j) {
                    double value = C[j] + (B[i] - B[j]) / (i - j);
                    C[i] = max(C[i], value);
                }
            }
        }
        return C[sz];
    }
};

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int sz = A.size();
        vector<vector<double>> B(sz + 1, vector<double>(sz + 1, 0));
        double sum = 0;
        for (int i = 1; i <= sz; ++i) {
            sum += A[i - 1];
            B[i][i] = sum;
            B[i][1] = sum / i;
        }
        for (int k = 2; k <= K; ++k) {
            for (int i = 1; i <= sz; ++i) {
                for (int j = 1; j < i; ++j) {
                    double value = B[j][k - 1] + (B[i][i] - B[j][j]) / (i - j);
                    B[i][k] = max(B[i][k], value);
                }
            }
        }
        return B[sz][K];
    }
};

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int sz = A.size();
        vector<vector<vector<double>>> B(sz, vector<vector<double>>(sz, vector<double>(sz + 1, 0)));
        for (int l = 1; l <= sz; ++l) {
            for (int i = 0; i + l <= sz; ++i) {
                int j = i + l - 1;
                B[i][j][l] = accumulate(next(A.begin(), i), next(A.begin(), j + 1), 0);
                B[i][j][1] = B[i][j][l] / l;
            }
        }
        for (int l = 2; l <= sz; ++l) {
            for (int k = 2; k < l; ++k) {
                for (int i = 0; i + l <= sz; ++i) {
                    int j = i + l - 1;
                    for (int m = i + k - 1; m <= j; ++m) {
                        double value = B[i][m - 1][k - 1] + B[m][j][1];
                        B[i][j][k] = max(B[i][j][k], value);
                    }
                }
            }
        }
        return B[0][sz - 1][K];
    }
};

int main(void) {
    Solution solution;
    
    vector<int> A;
    int K;
    double result;
    
    A = {9, 1, 2, 3, 9};
    K = 3;
    result = solution.largestSumOfAverages(A, K);
    cout << result << '\n';
    
    
    return 0;
}
