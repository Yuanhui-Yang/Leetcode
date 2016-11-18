// 352. Data Stream as Disjoint Intervals
// https://leetcode.com/problems/data-stream-as-disjoint-intervals/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class SummaryRanges {
public:
	/** Initialize your data structure here. */
	SummaryRanges() {
		this->intervals.clear();
	}

	void addNum(int val) {
		Interval newInterval(val, val);
		if (this->intervals.empty()) {
			this->intervals.insert(newInterval);
			return;
		}
		set<Interval, comp>::iterator it = this->intervals.lower_bound(newInterval), jt = it;
		jt--;
		if (it == begin(this->intervals)) {
			if (val + 1 < it->start) {
				this->intervals.insert(newInterval);
				return;				
			}
			newInterval.start = min(newInterval.start, it->start);
			newInterval.end = max(newInterval.end, it->end);
			this->intervals.erase(it);
			this->intervals.insert(newInterval);
			return;
		}
		if (it == end(this->intervals)) {
			if (jt->end + 1 < val) {
				this->intervals.insert(newInterval);
				return;				
			}
			newInterval.start = jt->start;
			newInterval.end = max(newInterval.end, jt->end);
			this->intervals.erase(jt);
			this->intervals.insert(newInterval);
			return;
		}
		if (jt->end + 1 < val) {
			if (val + 1 < it->start) {
				this->intervals.insert(newInterval);
				return;
			}
			newInterval.end = max(newInterval.end, it->end);
			this->intervals.erase(it);
			this->intervals.insert(newInterval);
			return;
		}
		newInterval.start = jt->start;
		newInterval.end = max(newInterval.end, jt->end);
		if (val + 1 < it->start) {
			this->intervals.erase(jt);
			this->intervals.insert(newInterval);
			return;
		}
		newInterval.end = max(newInterval.end, it->end);
		this->intervals.erase(it);
		this->intervals.erase(jt);
		this->intervals.insert(newInterval);
		return;
	}

	vector<Interval> getIntervals() {
		return vector<Interval>(begin(this->intervals), end(this->intervals));
	}
private:
	struct comp {
		bool operator() (const Interval& a, const Interval& b) {
			return a.start < b.start;
		}
	};
	set<Interval, comp> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
int main(void) {
	SummaryRanges obj;
	// obj.addNum(1);
	// for (const auto &i : obj.getIntervals()) cout << '[' << i.start << ',' << i.end << ']' << '\t';
	// cout << "\tPassed\n";
	// obj.addNum(3);
	// for (const auto &i : obj.getIntervals()) cout << '[' << i.start << ',' << i.end << ']' << '\t';
	// cout << "\tPassed\n";
	// obj.addNum(7);
	// for (const auto &i : obj.getIntervals()) cout << '[' << i.start << ',' << i.end << ']' << '\t';
	// cout << "\tPassed\n";
	// obj.addNum(2);
	// for (const auto &i : obj.getIntervals()) cout << '[' << i.start << ',' << i.end << ']' << '\t';
	// cout << "\tPassed\n";
	// obj.addNum(6);
	// for (const auto &i : obj.getIntervals()) cout << '[' << i.start << ',' << i.end << ']' << '\t';
	// cout << "\tPassed\n";
	// obj.addNum(8);
	// for (const auto &i : obj.getIntervals()) cout << '[' << i.start << ',' << i.end << ']' << '\t';
	// cout << "\tPassed\n";

	obj.addNum(1);
	for (const auto &i : obj.getIntervals()) cout << '[' << i.start << ',' << i.end << ']' << '\t';
	cout << "\tPassed\n";
	obj.addNum(0);
	for (const auto &i : obj.getIntervals()) cout << '[' << i.start << ',' << i.end << ']' << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}