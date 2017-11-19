// 716. Max Stack
// https://leetcode.com/problems/max-stack/

/*
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
*/

#include <iostream>
#include <climits>
#include <stack>

using namespace std;

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}
    
    void push(int x) {
        a.push(x);
        if (b.empty() or b.top() <= x) {
            b.push(x);
        }
    }
    
    int pop() {
        if (a.empty() or b.empty()) {
            return INT_MIN;
        }
        if (a.top() == b.top()) {
            b.pop();
        }
        int result = a.top();
        a.pop();
        return result;
    }
    
    int top() {
        return a.empty() ? INT_MIN : a.top();
    }
    
    int peekMax() {
        return b.empty() ? INT_MIN : b.top();
    }
    
    int popMax() {
        stack<int> c;
        while (!a.empty() and !b.empty() and a.top() < b.top()) {
            c.push(a.top());
            a.pop();
        }
        int result = b.top();
        a.pop();
        b.pop();
        while (!c.empty()) {
            push(c.top());
            c.pop();
        }
        return result;
    }
private:
    stack<int> a, b;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */

int main(void) {
    MaxStack obj;
    obj.push(5); 
    obj.push(1);
    obj.push(5);
    cout << obj.top() << '\t';
    cout << obj.popMax() << '\t';
    cout << obj.top() << '\t';
    cout << obj.peekMax() << '\t';
    cout << obj.pop() << '\t';
    cout << obj.top() << '\t';
    cout << '\n';

    return 0;
}