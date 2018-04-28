477. Total Hamming Distance
https://leetcode.com/problems/total-hamming-distance/

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0, sz = nums.size();
        for (int i = 31; i >= 0; --i) {
            int cnt = 0;
            for (const auto & num : nums) {
                cnt += (num >> i) & 1;
            }
            result += cnt * (sz - cnt);
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int result;

    nums = {4, 14, 2};
    result = solution.totalHammingDistance(nums);
    cout << result << '\n';

    return 0;
}
