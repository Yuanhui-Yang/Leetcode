// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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
	vector<Interval> merge(vector<Interval>& intervals) {
		sort(begin(intervals), end(intervals), Comp());
		vector<Interval> result;
		for (int sz = intervals.size(), i = 0; i < sz; ++i) {
			int a = intervals[i].start, b = intervals[i].end;
			while (i + 1 < sz and intervals[i + 1].start <= b) {
				++i;
				b = max(b, intervals[i].end);
			}
			result.push_back({a, b});
		}
		return result;
	}
private:
	struct Comp {
		bool operator () (const Interval & a, const Interval & b) {
			return a.start < b.start;
		}
	};
};