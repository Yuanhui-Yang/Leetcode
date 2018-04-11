/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        A.push(nestedList.begin());
        B.push(nestedList.end());
    }

    int next() {
        vector<NestedInteger>::iterator & top = A.top();
        int result = top->getInteger();
        ++top;
        return result;
    }

    bool hasNext() {
        while (!A.empty()) {
            vector<NestedInteger>::iterator & a = A.top(), & b = B.top();
            if (a == b) {
                A.pop();
                B.pop();
            }
            else if (a->isInteger()) {
                return true;
            }
            else {
                vector<NestedInteger> & v = a->getList();
                ++a;
                A.push(v.begin());
                B.push(v.end());
            }
        }
        return false;
    }
private:
    stack<vector<NestedInteger>::iterator> A, B;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
