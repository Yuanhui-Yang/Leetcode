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
        stk.push({nestedList.begin(), nestedList.end()});
    }

    int next() {
        array<vector<NestedInteger>::iterator, 2> top = stk.top();
        int result = top[0]->getInteger();
        ++stk.top()[0];
        return result;
    }

    bool hasNext() {
        while (!stk.empty()) {
            array<vector<NestedInteger>::iterator, 2> top = stk.top();
            if (top[0] == top[1]) {
                stk.pop();
            }
            else if (top[0]->isInteger()) {
                return true;
            }
            else {
                ++stk.top()[0];
                stk.push({top[0]->getList().begin(), top[0]->getList().end()});
            }
        }
        return !stk.empty();
    }
private:
    stack<array<vector<NestedInteger>::iterator, 2>> stk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
