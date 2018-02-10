779. K-th Symbol in Grammar
https://leetcode.com/problems/k-th-symbol-in-grammar/

On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).

Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
Note:

N will be an integer in the range [1, 30].
K will be an integer in the range [1, 2^(N-1)].

#include <iostream>

using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) {
            return 0;
        }
        if (N % 2) {
            return kthGrammar(N - 1, min(K, (1 << (N - 1)) - K + 1));
        }
        if (K >= (1 << (N - 2)) + 1) {
            return 1 - kthGrammar(N - 1, (1 << (N - 1)) - K + 1);
        }
        return kthGrammar(N - 1, K);
    }
};

int main(void) {
    Solution solution;
    int N, K, result;
    
    N = 1;
    K = 1;
    result = solution.kthGrammar(N, K);
    cout << result << '\n';

    N = 2;
    K = 1;
    result = solution.kthGrammar(N, K);
    cout << result << '\n';

    N = 2;
    K = 2;
    result = solution.kthGrammar(N, K);
    cout << result << '\n';

    N = 4;
    K = 5;
    result = solution.kthGrammar(N, K);
    cout << result << '\n';

    N = 30;
    K = 434991989;
    result = solution.kthGrammar(N, K);
    cout << result << '\n';
    
    return 0;
}