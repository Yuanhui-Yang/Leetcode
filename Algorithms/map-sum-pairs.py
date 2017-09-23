# 677. Map Sum Pairs
# https://leetcode.com/problems/map-sum-pairs/

# Implement a MapSum class with insert, and sum methods.

# For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

# For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

# Example 1:
# Input: insert("apple", 3), Output: Null
# Input: sum("ap"), Output: 3
# Input: insert("app", 2), Output: Null
# Input: sum("ap"), Output: 5

class Node(object):
	def __init__(self):
		self.next = {}
		self.val = 0

class MapSum(object):

	def __init__(self):
		"""
		Initialize your data structure here.
		"""
		self.root = Node()

	def insert(self, key, val):
		"""
		:type key: str
		:type val: int
		:rtype: void
		"""
		it = self.root
		for ch in key:
			if ch not in it.next:
				it.next[ch] = Node()
			it = it.next[ch]
		it.val = val

	def sum(self, prefix):
		"""
		:type prefix: str
		:rtype: int
		"""
		def f(node):
			if not node:
				return 0
			result = node.val
			for i, j in node.next.items():
				result += f(j)
			return result
		
		it = self.root
		sum = 0
		for ch in prefix:
			if ch not in it.next:
				return 0
			it = it.next[ch]
		return f(it)


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)