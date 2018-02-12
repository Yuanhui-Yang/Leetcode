768. Max Chunks To Make Sorted II
https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily distinct, the input array could be up to length 2000, and the elements could be up to 10**8.

Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 2000].
arr[i] will be an integer in range [0, 10**8].

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sz = arr.size();
        if (sz <= 1) {
            return sz;
        }
        int lmax = -1, result = 0;
        multiset<int> right(arr.begin(), arr.end());
        for (int i = 0; i < sz; ++i) {
            if (lmax < arr[i]) {
                lmax = arr[i];
            }
            right.erase(right.find(arr[i]));
            if (right.empty() or lmax <= *(right.begin())) {
                ++result;
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> arr;
    int result;
    
    arr = {5, 4, 3, 2, 1};
    result = solution.maxChunksToSorted(arr);
    cout << result << '\n';
    
    arr = {2, 1, 3, 4, 4};
    result = solution.maxChunksToSorted(arr);
    cout << result << '\n';
    
    return 0;
}