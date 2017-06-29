// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/

/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
*/

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {}

	void addNum(int num) {
		if (a.size() <= b.size()) {
			a.push(num);
		}
		else {
			b.push(num);
		}
		if (!a.empty() and !b.empty() and a.top() > b.top()) {
			int x = a.top(), y = b.top();
			a.pop(); b.pop();
			a.push(y);
			b.push(x);
		}
	}

	double findMedian() {
		if (a.size() < b.size()) {
			return b.top();
		}
		if (a.size() > b.size()) {
			return a.top();
		}
		return 0.5 * a.top() + 0.5 * b.top();
	}
private:
	priority_queue<int> a;
	priority_queue<int, vector<int>, greater<int>> b;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */