// 715. Range Module
// https://leetcode.com/problems/range-module/

/*
A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces in an efficient manner.

addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being tracked.
removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).
Example 1:
addRange(10, 20): null
removeRange(14, 16): null
queryRange(10, 14): true (Every number in [10, 14) is being tracked)
queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
Note:

A half open interval [left, right) denotes all real numbers left <= x < right.
0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
The total number of calls to addRange in a single test case is at most 1000.
The total number of calls to queryRange in a single test case is at most 5000.
The total number of calls to removeRange in a single test case is at most 1000.
*/

#include <iostream>
#include <array>
#include <climits>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

class RangeModule {
public:
	RangeModule() {
		A.clear();
	}
	
	void addRange(int left, int right) {
		if (left >= right) {
			return;
		}
		if (A.empty()) {
			A.insert({left, right});
			return;
		}
		set<array<int, 2>>::iterator a, b;
		a = A.upper_bound({left, INT_MAX});
		b = A.upper_bound({right, INT_MAX});
		if (a != begin(A) and left <= prev(a)->at(1)) {
			a = prev(a);
			left = a->at(0);
		}
		if (b != begin(A) and right < prev(b)->at(1)) {
			right = prev(b)->at(1);
		}
		A.erase(a, b);
		A.insert({left, right});
	}
	
	bool queryRange(int left, int right) {
		if (left >= right or A.empty()) {
			return false;
		}
		set<array<int, 2>>::iterator a, b;
		a = A.upper_bound({left, INT_MAX});
		b = A.upper_bound({right, INT_MAX});
		return a == b and a != begin(A) and prev(a)->at(0) <= left and right <= prev(a)->at(1);
	}
	
	void removeRange(int left, int right) {
		if (left >= right or A.empty()) {
			return;
		}
		int left1 = 0, right1 = 0, left2 = 0, right2 = 0;
		set<array<int, 2>>::iterator a, b;
		a = A.upper_bound({left, INT_MAX});
		b = A.upper_bound({right, INT_MAX});
		if (a != begin(A) and left < prev(a)->at(1)) {
			a = prev(a);
			left1 = a->at(0);
			right1 = left;
		}
		if (b != begin(A) and right < prev(b)->at(1)) {
			left2 = right;
			right2 = prev(b)->at(1);
		}
		A.erase(a, b);
		if (left1 < right1) {
			A.insert({left1, right1});
		}
		if (left2 < right2) {
			A.insert({left2, right2});
		}
	}
private:
	set<array<int, 2>> A;
};

int main(void) {
	RangeModule obj;

	obj.addRange(10, 20);
	obj.removeRange(14, 16);
	cout << boolalpha << obj.queryRange(10, 14) << '\n';
	cout << boolalpha << obj.queryRange(13, 15) << '\n';
	cout << boolalpha << obj.queryRange(16, 17) << '\n';

	obj = RangeModule();
	obj.addRange(10, 180);
	obj.addRange(150, 200);
	obj.addRange(250, 500);
	cout << boolalpha << obj.queryRange(50, 100) << '\n';
	cout << boolalpha << obj.queryRange(180, 300) << '\n';
	cout << boolalpha << obj.queryRange(600, 1000) << '\n';
	obj.removeRange(50, 150);
	cout << boolalpha << obj.queryRange(50, 100) << '\n';

	return 0;
}