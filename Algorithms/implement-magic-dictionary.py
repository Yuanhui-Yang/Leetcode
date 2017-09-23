# 676. Implement Magic Dictionary
# https://leetcode.com/problems/implement-magic-dictionary/

# Implement a magic directory with buildDict, and search methods.

# For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

# For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

# Example 1:
# Input: buildDict(["hello", "leetcode"]), Output: Null
# Input: search("hello"), Output: False
# Input: search("hhllo"), Output: True
# Input: search("hell"), Output: False
# Input: search("leetcoded"), Output: False
# Note:
# You may assume that all the inputs are consist of lowercase letters a-z.
# For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
# Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.

class Node(object):
	def __init__(self):
		self.isEnd = False
		self.next = {}

class MagicDictionary(object):

	def __init__(self):
		"""
		Initialize your data structure here.
		"""
		self.root = Node()

	def buildDict(self, dict):
		"""
		Build a dictionary through a list of words
		:type dict: List[str]
		:rtype: void
		"""
		def f1(s):
			it = self.root
			for ch in s:
				if ch not in it.next:
					it.next[ch] = Node()
				it = it.next[ch]
			it.isEnd = True
		for s in dict:
			f1(s)

	def search(self, word):
		"""
		Returns if there is any word in the trie that equals to the given word after modifying exactly one character
		:type word: str
		:rtype: bool
		"""
		def f2(word, start, node):
			if not node:
				return False
			sz = len(word)
			if start == sz:
				return node.isEnd
			if start + 1 == sz:
				for ch in node.next:
					if ch != word[start] and f2(word, start + 1, node.next[ch]):
						return True
				return False
			if word[start] in node.next and f2(word, start + 1, node.next[word[start]]):
				return True
			for ch in node.next:
				if ch != word[start] and f3(word, start + 1, node.next[ch]):
					return True
			return False
		def f3(word, start, node):
			if not node:
				return False
			sz = len(word)
			if start == sz:
				return node.isEnd
			return word[start] in node.next and f3(word, start + 1, node.next[word[start]])
		return f2(word, 0, self.root)
					
		


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)