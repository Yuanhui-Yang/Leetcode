// 385. Mini Parser
// https://leetcode.com/problems/mini-parser/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
	NestedInteger deserialize(string s) {
		return this->deserialize(s, 0, (int)s.size());
	}
private:
	NestedInteger deserialize(const string& s, int x, int y) {
		NestedInteger result;
		if (s.empty()) return result;
		if (s[x] != '[') {
			result.setInteger(stoi(s.substr(x, y - x)));
			return result;
		}
		if (x + 2 == y) return result;
		for (int i = x + 1, j = x + 1; i < y; ) {
			if (s[i] == '[') {
				int k = 1;
				i++;
				while (i < y && k) {
					if (s[i] == '[') k++;
					if (s[i] == ']') k--;
					i++;
				}
				result.add(this->deserialize(s, j, i));
				j = ++i;
				continue;
			}
			if (s[i] == ',') {
				result.add(this->deserialize(s, j, i));
				j = ++i;
				continue;
			}
			if (i + 1 == y) {
				result.add(this->deserialize(s, j, y));
				++i;
				continue;	
			}
			++i;
		}
		return result;
	}
};