// 677. Map Sum Pairs
// https://leetcode.com/problems/map-sum-pairs/

/*
Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
*/

class MapSum {
	/** Initialize your data structure here. */
	public MapSum() {
		root = new Node();
	}
	
	public void insert(String key, int val) {
		Node it = root;
		for (int i = 0; i < key.length(); ++i) {
			int id = key.charAt(i);
			if (it.next[id] == null) {
				it.next[id] = new Node();
			}
			it = it.next[id];
		}
		it.isEnd = true;
		it.val = val;
	}
	
	public int sum(String prefix) {
		Node it = root;
		for (int i = 0; i < prefix.length(); ++i) {
			int id = prefix.charAt(i);
			if (it.next[id] == null) {
				return 0;
			}
			it = it.next[id];
		}
		return f(it);
	}
	private Node root = null;
	private int f(Node node) {
		if (node == null) {
			return 0;
		}
		int result = node.val;
		for (Node i : node.next) {
			result += f(i);
		}
		return result;
	}
	private class Node {
		public int val = 0;
		public boolean isEnd = false;
		public Node[] next = null;
		public Node() {
			val = 0;
			isEnd = false;
			next = new Node[256];
			Arrays.fill(next, null);
		}
	}
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */