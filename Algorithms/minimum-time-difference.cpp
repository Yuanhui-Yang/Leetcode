// 539. Minimum Time Difference
// https://leetcode.com/problems/minimum-time-difference/

/*
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
*/

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		vector<int> A;
		int sz = timePoints.size();
		for (int i = 0; i < sz; ++i) {
			A.push_back(f(timePoints[i]));
		}
		sort(begin(A), end(A));
		int result = INT_MAX;
		for (int i = 0; i + 1 < sz; ++i) {
			int diff = A[i + 1] - A[i];
			result = min(result, diff);
		}
		if (sz >= 2) {
			int diff = A[0] + 24 * 60 - A[sz - 1];
			result = min(result, diff);
		}
		return result == INT_MAX ? 0 : result;
	}
private:
	int f(const string & s) {
		int sz = s.size(), i = 0;
		while (i < sz and s[i] != ':') {
			++i;
		}
		return stoi(s.substr(0, i)) * 60 + stoi(s.substr(i + 1));
	}
};