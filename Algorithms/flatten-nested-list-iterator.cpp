// 341. Flatten Nested List Iterator
// https://leetcode.com/problems/flatten-nested-list-iterator/
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
// BEGIN: https://discuss.leetcode.com/topic/41870/real-iterator-in-python-java-c
class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		this->begins.push(begin(nestedList));
		this->ends.push(end(nestedList));
	}

	int next() {
		return (this->begins.top()++)->getInteger();
	}

	bool hasNext() {
		while (!begins.empty()) {
			if (begins.top() == ends.top()) {
				begins.pop();
				ends.pop();
				continue;
			}
			if (begins.top()->isInteger()) return true;
			vector<NestedInteger> &current = begins.top()->getList();
			begins.top()++;
			begins.push(begin(current));
			ends.push(end(current));
		}
		return false;
	}
private:
	stack<vector<NestedInteger>::iterator> begins, ends;
};
// END: https://discuss.leetcode.com/topic/41870/real-iterator-in-python-java-c

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */