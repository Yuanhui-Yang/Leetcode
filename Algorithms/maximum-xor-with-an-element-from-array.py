1707. Maximum XOR With an Element From Array
https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

 

Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
Example 2:

Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]
 

Constraints:

1 <= nums.length, queries.length <= 105
queries[i].length == 2
0 <= nums[j], xi, mi <= 109

class Node:
    def __init__(self):
        self.isEnd = False
        self.value = -1
        self.children = [None] * 2

class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        nums.sort()
        sz = len(queries)
        for i in range(sz):
            query = queries[i]
            query.append(i)
        queries.sort(key = lambda query: query[1])
        result = [-1] * sz
        root = Node()
        i = 0
        for query in queries:
            while i < len(nums) and nums[i] <= query[1]:
                self.f1(root, nums[i])
                i += 1
            result[query[2]] = self.f2(root, query[0])
        return result
    def f1(self, node, num):
        for i in range(31, -1, -1):
            j = num >> i
            j &= 1
            if node.children[j] is None:
                node.children[j] = Node()
            node = node.children[j]
        node.isEnd = True
        node.value = num
    def f2(self, node, x):
        for i in range(31, -1, -1):
            j = x >> i
            j &= 1
            if node.children[j ^ 1] is not None:
                node = node.children[j ^ 1]
            elif node.children[j] is not None:
                node = node.children[j]
            else:
                return -1
        return node.value ^ x