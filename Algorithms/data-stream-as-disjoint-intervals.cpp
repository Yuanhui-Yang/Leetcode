// 352. Data Stream as Disjoint Intervals
// https://leetcode.com/problems/data-stream-as-disjoint-intervals/

/*
Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
*/

#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

struct Interval {
	int start, end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

struct Comp {
	bool operator() (const Interval & a, const Interval & b) {
		return a.start < b.start;
	}
};

class SummaryRanges {
public:
	/** Initialize your data structure here. */
	SummaryRanges() {
		tree.clear();
	}
	
	void addNum(int val) {
		Interval target(val, val);
		if (tree.empty()) {
			tree.insert(target);
			return;
		}
		set<Interval, Comp>::iterator currIter = tree.lower_bound(target), prevIter;
		if (currIter == begin(tree)) {
			if (currIter->start - 1 <= val) {
				target.start = min(currIter->start, val);
				target.end = currIter->end;
				tree.erase(currIter);
			}
			tree.insert(target);
			return;
		}
		if (currIter == end(tree)) {
			prevIter = prev(currIter);
			if (val <= prevIter->end + 1) {
				target.start = prevIter->start;
				target.end = max(prevIter->end, val);
				tree.erase(prevIter);
			}
			tree.insert(target);
			return;
		}
		prevIter = prev(currIter);
		if (prevIter->end + 1 < val and currIter->start - 1 <= val) {
			target.start = min(currIter->start, val);
			target.end = currIter->end;
			tree.erase(currIter);
		}
		else if (val <= prevIter->end + 1 and val < currIter->start - 1) {
			target.start = prevIter->start;
			target.end = max(prevIter->end, val);
			tree.erase(prevIter);
		}
		else if (val <= prevIter->end + 1 and currIter->start - 1 <= val) {
			target.start = prevIter->start;
			target.end = currIter->end;
			tree.erase(prevIter);
			tree.erase(currIter);
		}
		tree.insert(target);
	}
	
	vector<Interval> getIntervals() {
		return vector<Interval>(begin(tree), end(tree));
	}
private:
	set<Interval, Comp> tree;
};

int main(void) {
	SummaryRanges obj;
	vector<Interval> result;
	int val;

	val = 1;
	obj.addNum(val);
	result = obj.getIntervals();
	for (const auto & i : result) {
		cout << '(' << i.start << ',' << i.end << ')' << '\t';
	}
	cout << '\n';

	val = 3;
	obj.addNum(val);
	result = obj.getIntervals();
	for (const auto & i : result) {
		cout << '(' << i.start << ',' << i.end << ')' << '\t';
	}
	cout << '\n';

	val = 7;
	obj.addNum(val);
	result = obj.getIntervals();
	for (const auto & i : result) {
		cout << '(' << i.start << ',' << i.end << ')' << '\t';
	}
	cout << '\n';

	val = 2;
	obj.addNum(val);
	result = obj.getIntervals();
	for (const auto & i : result) {
		cout << '(' << i.start << ',' << i.end << ')' << '\t';
	}
	cout << '\n';

	val = 6;
	obj.addNum(val);
	result = obj.getIntervals();
	for (const auto & i : result) {
		cout << '(' << i.start << ',' << i.end << ')' << '\t';
	}
	cout << '\n';

	return 0;
}
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */