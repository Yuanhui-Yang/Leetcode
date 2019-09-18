/*
 * @lc app=leetcode id=339 lang=cpp
 *
 * [339] Nested List Weight Sum
 *
 * https://leetcode.com/problems/nested-list-weight-sum/description/
 *
 * algorithms
 * Easy (69.56%)
 * Likes:    344
 * Dislikes: 75
 * Total Accepted:    64.4K
 * Total Submissions: 92.4K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * Given a nested list of integers, return the sum of all integers in the list
 * weighted by their depth.
 * 
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],2,[1,1]]
 * Output: 10 
 * Explanation: Four 1's at depth 2, one 2 at depth 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,[4,[6]]]
 * Output: 27 
 * Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 +
 * 4*2 + 6*3 = 27.
 * 
 * 
 * 
 */
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
    int depthSum(vector<NestedInteger>& nestedList) {
        typedef tuple<int, vector<NestedInteger>::iterator, vector<NestedInteger>::iterator> Element;
        int result = 0;
        stack<Element> stk;
        stk.push(make_tuple(1, nestedList.begin(), nestedList.end()));
        while (!stk.empty())
        {
            Element top = stk.top();
            int a = get<0>(top);
            vector<NestedInteger>::iterator b = get<1>(top);
            vector<NestedInteger>::iterator c = get<2>(top);
            if (b == c)
            {
                stk.pop();
            }
            else if (b->isInteger())
            {
                ++get<1>(stk.top());
                result += a * b->getInteger();
            }
            else
            {
                ++get<1>(stk.top());
                vector<NestedInteger>& v = b->getList();
                stk.push(make_tuple(a + 1, v.begin(), v.end()));
            }
        }
        return result;
    }
};