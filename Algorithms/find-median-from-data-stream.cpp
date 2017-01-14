// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/
#include <iostream>
#include <cassert>
#include <cmath>
#include <set>
#include <cfloat>
#include <algorithm>
#include <iterator>
using namespace std; 
class MedianFinder {
public:

	// Adds a number into the data structure.
	void addNum(int num) {
		if (minSet.empty() && maxSet.empty()) {
			minSet.insert(num);
			return;
		}
		if (minSet.size() < maxSet.size()) {
			if (num <= *begin(maxSet)) {
				minSet.insert(num);
				return;
			}
			if (num > *begin(maxSet)) {
				minSet.insert(*begin(maxSet));
				maxSet.erase(begin(maxSet));
				maxSet.insert(num);
				return;
			}
			return;
		}
		if (minSet.size() > maxSet.size()) {
			if (num >= *prev(end(minSet))) {
				maxSet.insert(num);
				return;
			}
			if (num < *prev(end(minSet))) {
				maxSet.insert(*prev(end(minSet)));
				minSet.erase(prev(end(minSet)));
				minSet.insert(num);
				return;
			}
			return;
		}
		if (minSet.size() == maxSet.size()) {
			if (num <= *begin(maxSet)) {
				minSet.insert(num);
				return;
			}
			if (num > *begin(maxSet)) {
				maxSet.insert(num);
				return;
			}
			return;
		}
		return;
	}

	// Returns the median of current data stream
	double findMedian() {
		if (minSet.size() < maxSet.size()) {
			return double(*begin(maxSet));
		}
		if (minSet.size() > maxSet.size()) {
			return double(*prev(end(minSet)));
		}
		if (minSet.size() == maxSet.size()) {
			double minSetMaxVal = double(*prev(end(minSet)));
			double maxSetMinVal = double(*begin(maxSet));	
			return minSetMaxVal / 2.0 + maxSetMinVal / 2.0;
		}
		return 0.0;
	}

private:
	multiset<int> minSet;
	multiset<int> maxSet;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main(void) {
	MedianFinder mf;
	double result = 0.0;
	mf.addNum(1);
	mf.addNum(2);

	result = mf.findMedian();
	assert(fabs(1.5 - result) < DBL_EPSILON);
	
	mf.addNum(3);
	
	result = mf.findMedian();
	assert(fabs(2.0 - result) < DBL_EPSILON);

	mf = MedianFinder();

	mf.addNum(6);
	result = mf.findMedian();
	assert(fabs(6.0 - result) < DBL_EPSILON);
	
	mf.addNum(10);
	result = mf.findMedian();
	assert(fabs(8.0 - result) < DBL_EPSILON);
	
	mf.addNum(2);
	result = mf.findMedian();
	assert(fabs(6.0 - result) < DBL_EPSILON);
	
	mf.addNum(6);
	result = mf.findMedian();
	assert(fabs(6.0 - result) < DBL_EPSILON);
	
	mf.addNum(5);
	result = mf.findMedian();
	assert(fabs(6.0 - result) < DBL_EPSILON);
	
	mf.addNum(0);
	result = mf.findMedian();
	assert(fabs(5.5 - result) < DBL_EPSILON);
	
	mf.addNum(6);
	result = mf.findMedian();
	assert(fabs(6.0 - result) < DBL_EPSILON);
	
	mf.addNum(3);
	result = mf.findMedian();
	assert(fabs(5.5 - result) < DBL_EPSILON);
	
	mf.addNum(1);
	result = mf.findMedian();
	assert(fabs(5.0 - result) < DBL_EPSILON);
	
	mf.addNum(0);
	result = mf.findMedian();
	assert(fabs(4.0 - result) < DBL_EPSILON);
	
	mf.addNum(0);
	result = mf.findMedian();
	assert(fabs(3.0 - result) < DBL_EPSILON);
	
	cout << "\nPassed All\n";
	return 0;
}