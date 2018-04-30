274. H-Index
https://leetcode.com/problems/h-index/

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int sz = citations.size(), i = 0, j = sz;
        while (i < j) {
            int k = i + (j - i) / 2;
            if (citations[k] > k) {
                i = k + 1;
            }
            else {
                j = k;
            }
        }
        return i;
    }
};

int main(void) {
    Solution solution;
    vector<int> citations;
    int result;

    citations = {3, 0, 6, 1, 5};
    result = solution.hIndex(citations);
    cout << result << '\n';

    return 0;
}
