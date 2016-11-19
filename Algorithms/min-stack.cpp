// 155. Min Stack
// https://leetcode.com/problems/min-stack/
#include <iostream>
#include <vector>
using namespace std;
// BEGIN: http://www.jiuzhang.com/solutions/min-stack/
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		a.clear();
		b.clear();
	}

	void push(int x) {
		if (a.empty() || b.empty()) {
			a.push_back(x);
			b.push_back(x);
			return;
		}
		if (b.back() <= x) {
			a.push_back(x);
			b.push_back(b.back());
			return;
		}
		a.push_back(x);
		b.push_back(x);
	}

	void pop() {
		if (a.empty() || b.empty()) return;
		a.pop_back();
		b.pop_back();
	}

	int top() {
		return a.back();
	}

	int getMin() {
		return b.back();
	}
private:
	vector<int> a, b;
};
// END: http://www.jiuzhang.com/solutions/min-stack/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(void) {
	MinStack minStack;
	// minStack.push(-2);
	// minStack.push(0);
	// minStack.push(-3);
	// cout << minStack.getMin() << "\tPassed\n";
	// minStack.pop();
	// cout << minStack.top() << "\tPassed\n";
	// cout << minStack.getMin() << "\tPassed\n";
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-1);
	cout << minStack.getMin() << "\tPassed\n";
	cout << minStack.top() << "\tPassed\n";
	minStack.pop();
	cout << minStack.getMin() << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}