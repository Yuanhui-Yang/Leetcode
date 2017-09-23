// 676. Implement Magic Dictionary
// https://leetcode.com/problems/implement-magic-dictionary/

/*
Implement a magic directory with buildDict, and search methods.

For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
Note:
You may assume that all the inputs are consist of lowercase letters a-z.
For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.
*/

class MagicDictionary {

	/** Initialize your data structure here. */
	public MagicDictionary() {
		root = new Node();
	}
	
	/** Build a dictionary through a list of words */
	public void buildDict(String[] dict) {
		for (String i : dict) {
			f1(i);
		}
	}
	
	/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
	public boolean search(String word) {
		return f2(word, 0, root);
	}
	private void f1(String s) {
		int len = s.length(), i = 0;
		Node it = root;
		for (i = 0; i < len; ++i) {
			int id = s.charAt(i) - 'a';
			if (it.next[id] == null) {
				it.next[id] = new Node();
			}
			it = it.next[id];
		}
		it.isEnd = true;
	}
	private boolean f2(String s, int start, Node node) {
		if (node == null) {
			return false;
		}
		int len = s.length(), i = 0;
		if (start == len) {
			return node.isEnd;
		}
		int id = s.charAt(start) - 'a';
		if (start + 1 == len) {
			for (i = 0; i < 26; ++i) {
				if (i != id && f2(s, start + 1, node.next[i])) {
					return true;
				} 
			}
			return false;
		}
		if (node.next[id] != null && f2(s, start + 1, node.next[id])) {
			return true;
		}
		for (i = 0; i < 26; ++i) {
			if (i != id && f3(s, start + 1, node.next[i])) {
				return true;
			}
		}
		return false;
	}
	private boolean f3(String s, int start, Node node) {
		if (node == null) {
			return false;
		}
		int len = s.length();
		if (start == len) {
			return node.isEnd;
		}
		int id = s.charAt(start) - 'a';
		return f3(s, start + 1, node.next[id]);
	}
	private class Node {
		public boolean isEnd = false;
		public Node[] next = null;
		public Node() {
			isEnd = false;
			next = new Node[26];
			Arrays.fill(next, null);
		}
	}
	private Node root = null;
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * boolean param_2 = obj.search(word);
 */