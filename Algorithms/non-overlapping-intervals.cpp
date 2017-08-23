// 435. Non-overlapping Intervals
// https://leetcode.com/problems/non-overlapping-intervals/

/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		sort(begin(intervals), end(intervals), Comp());
		int sz = intervals.size(), result = 0;
		for (int i = 0; i < sz; ++i) {
			int y = intervals[i].end;
			while (i + 1 < sz and intervals[i + 1].start < y) {
				++result;
				++i;
			}
		}
		return result;
	}
private:
	struct Comp {
		bool operator() (const Interval & a, const Interval & b) {
			return a.end < b.end;
		}
	};
};