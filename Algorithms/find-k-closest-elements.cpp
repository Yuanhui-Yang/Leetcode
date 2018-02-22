658. Find K Closest Elements
https://leetcode.com/problems/find-k-closest-elements/

Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
UPDATE (2017/9/19):
The arr parameter had been changed to an array of integers (instead of a list of integers). Please reload the code definition to get the latest changes.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>::iterator it = upper_bound(arr.begin(), arr.end(), x), begin = arr.begin(), end = arr.end();
        int sz = arr.size();
        if (it == end) {
            return vector<int>(prev(end, k), end);
        }
        else if (it == begin) {
            return vector<int>(begin, next(begin, k));
        }
        else {
            int j = distance(begin, it), i = j - 1;
            while (k-- > 0) {
                if (i < 0) {
                    ++j;
                }
                else if (j >= sz) {
                    --i;
                }
                else if (abs(arr[i] - x) <= abs(arr[j] - x)) {
                    --i;
                }
                else {
                    ++j;
                }
            }
            return vector<int>(next(begin, i + 1), next(begin, j));
        }
    }
};

int main(void) {
    Solution solution;
    vector<int> arr, result;
    int k, x;
    
    arr = {1, 2, 3, 4, 5};
    k = 4;
    x = 3;
    result = solution.findClosestElements(arr, k, x);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}