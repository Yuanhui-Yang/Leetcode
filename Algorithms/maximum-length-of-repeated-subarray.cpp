#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int sz1 = A.size(), sz2 = B.size(), i, j, result = 0;
        if (sz1 == 0 or sz2 == 0) {
            return 0;
        }
        vector<vector<int>> C(sz1 + 1, vector<int>(sz2 + 1, 0));
        for (i = sz1 - 1; i >= 0; --i) {
            for (j = sz2 - 1; j >= 0; --j) {
                if (A[i] == B[j]) {
                    C[i][j] = C[i + 1][j + 1] + 1;
                    result = max(result, C[i][j]);
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> A, B;
    int result;
    
    A = {1, 2, 3, 2, 1};
    B = {3, 2, 1, 4, 7};
    result = solution.findLength(A, B);
    cout << result << '\n';

    return 0;
}