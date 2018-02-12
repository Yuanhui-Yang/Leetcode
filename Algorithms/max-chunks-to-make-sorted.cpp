769. Max Chunks To Make Sorted
https://leetcode.com/problems/max-chunks-to-make-sorted/

Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 10].
arr[i] will be a permutation of [0, 1, ..., arr.length - 1].

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sz = arr.size();
        if (sz <= 1) {
            return sz;
        }
        int result = 0, lmax = -1;
        for (int i = 0; i < sz; ++i) {
            if (lmax < arr[i]) {
                lmax = arr[i];
            }
            if (lmax == i) {
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
    
    arr = {0, 1};
    result = solution.maxChunksToSorted(arr);
    cout << result << '\n';
    
    arr = {1, 0, 2, 3, 4};
    result = solution.maxChunksToSorted(arr);
    cout << result << '\n';

    arr = {1, 2, 0, 3};
    result = solution.maxChunksToSorted(arr);
    cout << result << '\n';

    arr = {4, 3, 2, 1, 0};
    result = solution.maxChunksToSorted(arr);
    cout << result << '\n';
    
    arr = {1, 0, 2, 3, 4};
    result = solution.maxChunksToSorted(arr);
    cout << result << '\n';

    arr = {1, 2, 0, 3};
    result = solution.maxChunksToSorted(arr);
    cout << result << '\n';
    
    return 0;
}