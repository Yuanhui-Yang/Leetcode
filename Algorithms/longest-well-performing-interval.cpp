1124. Longest Well-Performing Interval
https://leetcode.com/problems/longest-well-performing-interval/

We are given hours, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

 

Example 1:

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
 

Constraints:

1 <= hours.length <= 10000
0 <= hours[i] <= 16

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int result = 0, sz = hours.size();
        for (auto & i : hours)
        {
            i = i > 8 ? 1 : -1;
        }
        unordered_map<int, int> A;
        for (int sum = 0, i = 0; i < sz; ++i)
        {
            int val = hours[i];
            sum += val;
            int target = sum - 1;
            if (sum > 0)
            {
                result = i + 1;
            }
            else if (A.count(target))
            {
                result = max(result, i - A[target]);
            }
            if (!A.count(sum))
            {
                A[sum] = i;
            }
        }
        return result;
    }
};