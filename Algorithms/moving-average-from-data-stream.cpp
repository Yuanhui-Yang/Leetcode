// 346. Moving Average from Data Stream
// https://leetcode.com/problems/moving-average-from-data-stream/

/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

#include <bits/stdc++.h>
using namespace std;

class MovingAverage {
public:
	/** Initialize your data structure here. */
	MovingAverage(int size) {
		sz = size;
		l.clear();
		s = 0;
	}

	double next(int val) {
		if (l.size() == sz) {
			s -= l.front();
			l.pop_front();
		}
		s += val;
		l.push_back(val);
		return double(s) / double(l.size());
	}
private:
	size_t sz;
	list<int> l;
	int s;
};

/**
* Your MovingAverage object will be instantiated and called as such:
* MovingAverage obj = new MovingAverage(size);
* double param_1 = obj.next(val);
*/

int main(void) {
	int size, val;
	double answer, result;

	size = 3;
	MovingAverage m(size);

	val = 1;
	answer = 1;
	result = m.next(val);
	assert(fabs(answer - result) < DBL_EPSILON);

	val = 10;
	answer = 5.5;
	result = m.next(val);
	assert(fabs(answer - result) < DBL_EPSILON);

	val = 3;
	answer = 14.0 / 3.0;
	result = m.next(val);
	assert(fabs(answer - result) < DBL_EPSILON);

	val = 5;
	answer = 6;
	result = m.next(val);
	assert(fabs(answer - result) < DBL_EPSILON);

	cout << "\nPassed All\n";
	return 0;
}