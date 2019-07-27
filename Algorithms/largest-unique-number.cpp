1133. Largest Unique Number
https://leetcode.com/problems/largest-unique-number/

Given an array of integers A, return the largest integer that only occurs once.

If no integer occurs once, return -1.

 

Example 1:

Input: [5,7,3,9,4,9,8,3,1]
Output: 8
Explanation: 
The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it's the answer.
Example 2:

Input: [9,9,8,8]
Output: -1
Explanation: 
There is no number that occurs only once.
 

Note:

1 <= A.length <= 2000
0 <= A[i] <= 1000

class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        vector<int> B(1001, 0);
        for (auto i : A)
        {
            ++B[i];
        }
        int result = 1000;
        while (result >= 0 and B[result] != 1)
        {
            --result;
        }
        return result;
    }
};