275. H-Index II
https://leetcode.com/problems/h-index-ii/

Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = citations.size(), i = 0, j = sz;
        while (i < j) {
            int k = i + (j - i) / 2;
            if (citations[k] < sz - k) {
                i = k + 1;
            }
            else {
                j = k;
            }
        }
        return sz - i;
    }
};

int main(void) {
    Solution solution;
    vector<int> citations;
    int result;

    citations = {0, 1, 3, 5, 6};
    result = solution.hIndex(citations);
    cout << result << '\n';

    return 0;
}
