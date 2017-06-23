// 57. Insert Interval
// https://leetcode.com/problems/insert-interval/

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

#include <bits/stdc++.h>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(const int& s, const int& e) : start(s), end(e) {}
	bool operator== (const Interval& other) const {
		return this->start == other.start and this->end == other.end;
	}
	// bool operator< (const Interval& other) const {
	// 	return this->end < other.start;
	// }
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		pair<vector<Interval>::iterator, vector<Interval>::iterator> p = equal_range(begin(intervals), end(intervals), newInterval, Comp());
		// pair<vector<Interval>::iterator, vector<Interval>::iterator> p = equal_range(begin(intervals), end(intervals), newInterval);
		vector<Interval>::iterator a = p.first, b = p.second;
		if (a == b) {
			intervals.insert(a, newInterval);
		}
		else {
			a->start = min(a->start, newInterval.start);
			a->end = max(prev(b)->end, newInterval.end);
			intervals.erase(next(a), b);
		}
		return intervals;
	}
private:
	struct Comp {
		bool operator() (const Interval& a, const Interval& b) {
			return a.end < b.start;
		}
	};
};

int main(void) {
	Solution solution;
	vector<Interval> intervals, answer, result;
	Interval newInterval;

	intervals = {{1, 3}, {6, 9}};
	newInterval = Interval(2, 5);
	answer = {{1, 5}, {6, 9}};
	result = solution.insert(intervals, newInterval);
	assert(answer == result);

	intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
	newInterval = Interval(4, 9);
	answer = {{1, 2}, {3, 10}, {12, 16}};
	result = solution.insert(intervals, newInterval);
	assert(answer == result);

	intervals = {{1, 5}};
	newInterval = Interval(0, 0);
	answer = {{0, 0}, {1, 5}};
	result = solution.insert(intervals, newInterval);
	assert(answer == result);

	intervals = {{1, 5}};
	newInterval = Interval(0, 3);
	answer = {{0, 5}};
	result = solution.insert(intervals, newInterval);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}