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

struct Node {
	int val;
	bool isEnd;
	array<Node *, 256> next;
	Node() {
		val = 0;
		isEnd = false;
		next.fill(NULL);
	}
};

class MapSum {
public:
	/** Initialize your data structure here. */
	MapSum() {
		root = new Node();
	}
	
	void insert(string key, int val) {
		Node * it = root;
		for (const auto & i : key) {
			int id = i;
			if (!it->next[id]) {
				it->next[id] = new Node();
			}
			it = it->next[id];
		}
		it->isEnd = true;
		it->val = val;
	}
	
	int sum(string prefix) {
		Node * it = root;
		for (const auto & i : prefix) {
			int id = i;
			if (!it->next[id]) {
				return 0;
			}
			it = it->next[id];
		}
		return f(it);
	}
private:
	Node * root;
	int f(Node * node) {
		if (!node) {
			return 0;
		}
		int result = node->val;
		for (const auto & i : node->next) {
			result += f(i);
		}
		return result;
	}
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */