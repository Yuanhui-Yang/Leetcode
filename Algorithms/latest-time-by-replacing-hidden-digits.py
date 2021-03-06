1736. Latest Time by Replacing Hidden Digits
https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/

You are given a string time in the form of hh:mm, where some of the digits in the string are hidden (represented by ?).

The valid times are those inclusively between 00:00 and 23:59.

Return the latest valid time you can get from time by replacing the hidden digits.

 

Example 1:

Input: time = "2?:?0"
Output: "23:50"
Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
Example 2:

Input: time = "0?:3?"
Output: "09:39"
Example 3:

Input: time = "1?:22"
Output: "19:22"
 

Constraints:

time is in the format hh:mm.
It is guaranteed that you can produce a valid time from the given string.

class Solution:
    def maximumTime(self, time: str) -> str:
        a = ['?'] * 4
        if time[0] == '?':
            if time[1] == '?':
                a[0] = '2'
            elif time[1] >= '4':
                a[0] = '1'
            else:
                a[0] = '2'
        else:
            a[0] = time[0]
        if time[1] == '?':
            if a[0] == '2':
                a[1] = '3'
            else:
                a[1] = '9'
        else:
            a[1] = time[1]
        if time[3] == '?':
            a[2] = '5'
        else:
            a[2] = time[3]
        if time[4] == '?':
            a[3] = '9'
        else:
            a[3] = time[4]
        return a[0] + a[1] + ':' + a[2] + a[3]