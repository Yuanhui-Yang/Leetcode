786. K-th Smallest Prime Fraction
https://leetcode.com/problems/k-th-smallest-prime-fraction/

A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.

What is the K-th smallest fraction considered?  Return your answer as an array of ints, where answer[0] = p and answer[1] = q.

Examples:
Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]
Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.

Input: A = [1, 7], K = 1
Output: [1, 7]
Note:

A will have length between 2 and 2000.
Each A[i] will be between 1 and 30000.
K will be between 1 and A.length * (A.length + 1) / 2.

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double a = double(A.front()) / A.back(), b = 1;
        while (b - a >= 1e-8) {
            double c = a + (b - a) / 2;
            if (f1(A, c, K)) {
                a = c;
            }
            else {
                b = c;
            }
        }
        return f3(A, a);
    }
private:
    bool f1(vector<int> & A, double c, int K) {
        return f2(A, c) < K;
    }
    int f2(vector<int> & A, double c) {
        int sz = A.size(), result = 0;
        vector<int>::iterator b = A.end();
        for (int i = 0; i + 1 < sz; ++i) {
            vector<int>::iterator a = lower_bound(A.begin(), A.end(), ceil(A[i] / c));
            result += distance(a, b);
        }
        return result;
    }
    vector<int> f3(vector<int> & A, double a) {
        vector<int> result({A.front(), A.back()});
        for (int sz = A.size(), i = 0; i + 1 < sz; ++i) {
            double b = double(result[0]) / result[1];
            vector<int>::iterator ct = lower_bound(A.begin(), A.end(), round(A[i] / a));
            if (ct != A.end()) {
                double c = double(A[i]) / *ct;
                if (fabs(a - c) < fabs(a - b)) {
                    result[0] = A[i];
                    result[1] = *ct;
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> A, result;
    int K;
    
    A = {1, 2, 3, 5};
    K = 3;
    result = solution.kthSmallestPrimeFraction(A, K);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}