341. Flatten Nested List Iterator
https://leetcode.com/problems/flatten-nested-list-iterator/

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
        for (int sz = nestedList.size(), i = sz - 1; i >= 0; --i) {
            stk.push(nestedList[i]);
        }
    }

    int next() {
        int result = stk.top().getInteger();
        stk.pop();
        return result;
    }

    bool hasNext() {
        while (!stk.empty()) {
            if (stk.top().isInteger()) {
                return true;
            }
            vector<NestedInteger> v = stk.top().getList();
            stk.pop();
            for (int sz = v.size(), i = sz - 1; i >= 0; --i) {
                stk.push(v[i]);
            }
        }
        return false;
    }
private:
    stack<NestedInteger> stk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */