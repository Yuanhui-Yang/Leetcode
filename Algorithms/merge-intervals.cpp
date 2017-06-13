// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

#include <bits/stdc++.h>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

struct Comp {
	bool operator() (const struct Interval& a, const struct Interval& b) {
		return a.start == b.start ? a.end < b.end : a.start < b.start;
	}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		sort(begin(intervals), end(intervals), Comp());
		vector<Interval> result;
		for (int n = intervals.size(), i = 0; i < n; ++i) {
			int x = intervals[i].start, y = intervals[i].end;
			while (i + 1 < n and intervals[i + 1].start <= y) {
				y = max(y, intervals[i + 1].end);
				++i;
			}
			result.push_back(Interval(x, y));
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<Interval> intervals, answer, result;

	intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
	answer = {{1, 6}, {8, 10}, {15, 18}};
	sort(begin(answer), end(answer), Comp());
	result = solution.merge(intervals);
	sort(begin(result), end(result), Comp());
	assert(answer.size() == result.size());
	for (size_t n = answer.size(), i = 0; i < n; ++i) {
		assert(answer[i].start == result[i].start);
		assert(answer[i].end == result[i].end);
	}

	cout << "\nPassed All\n";
	return 0;
}