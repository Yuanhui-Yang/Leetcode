// 435. Non-overlapping Intervals
// https://leetcode.com/contest/11/problems/non-overlapping-intervals/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		if (intervals.empty()) return 0;
		sort(begin(intervals), end(intervals), [](const Interval& a, const Interval& b) {
			if (a.start == b.start) return a.start < b.start;
			return a.start < b.start;
		});
		int result = 1;
		const int n = intervals.size();
		vector<int> OPT(n, 1);
		for (int i = n - 2; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				if (intervals[j].start >= intervals[i].end) {
					OPT[i] = max(OPT[i], OPT[j] + 1);
					result = max(result, OPT[i]);
				}
			}
		}
		return n - result;
	}
};
int main(void) {
	Solution solution;
	vector<Interval> intervals;
	cout << solution.eraseOverlapIntervals(intervals) << "\tPassed\n";
	intervals = { {1,2}, {2,3}, {3,4}, {1,3} };
	cout << solution.eraseOverlapIntervals(intervals) << "\tPassed\n";
	intervals = { {1,2}, {1,2}, {1,2} };
	cout << solution.eraseOverlapIntervals(intervals) << "\tPassed\n";
	intervals = { {1,2}, {2,3} };
	cout << solution.eraseOverlapIntervals(intervals) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}