1550. Three Consecutive Odds
https://leetcode.com/problems/three-consecutive-odds/

Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
 

Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.
Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int sz = arr.size(), i = 0; i < sz; ++i)
        {
            if (i + 2 < sz)
            {
                int a = arr[i];
                int b = arr[i + 1];
                int c = arr[i + 2];
                if (a % 2 != 0 and b % 2 != 0 and c % 2 != 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};