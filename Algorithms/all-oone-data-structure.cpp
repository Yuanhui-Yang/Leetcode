// 432. All O`one Data Structure
// https://leetcode.com/problems/all-oone-data-structure/
#include <iostream>
#include <cassert>
#include <cctype>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>
using namespace std;
class AllOne {
public:
	/** Initialize your data structure here. */
	AllOne() {
		hash_map.clear();
		tree_map.clear();
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		if (hash_map.empty() || !hash_map.count(key)) {
			hash_map[key] = 1;
			tree_map[1].insert(key);
			return;
		}
		const size_t previous_value = hash_map[key];
		tree_map[previous_value].erase(key);
		if (tree_map[previous_value].empty()) {
			tree_map.erase(previous_value);
		}
		hash_map[key] = previous_value + 1;
		tree_map[previous_value + 1].insert(key);
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		if (hash_map.empty() || !hash_map.count(key)) {
			return;
		}
		const size_t previous_value = hash_map[key];
		if (previous_value == 1) {
			hash_map.erase(key);
			tree_map[previous_value].erase(key);
			if (tree_map[previous_value].empty()) {
				tree_map.erase(previous_value);
			}
			return;
		}
		hash_map[key]--;
		tree_map[previous_value].erase(key);
		if (tree_map[previous_value].empty()) {
			tree_map.erase(previous_value);
		}
		tree_map[previous_value - 1].insert(key);	
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (hash_map.empty()) {
			return "";
		}
		return *begin(prev(end(tree_map))->second);
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (hash_map.empty()) {
			return "";
		}
		return *begin(begin(tree_map)->second);
	}
private:
	unordered_map<string, size_t> hash_map;
	map<size_t, unordered_set<string>> tree_map;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */

int main(void) {
	AllOne obj;
	obj.inc("hello");
	obj.inc("hello");
	assert("hello" == obj.getMaxKey());
	assert("hello" == obj.getMinKey());
	obj.inc("leet");
	assert("hello" == obj.getMaxKey());
	assert("leet" == obj.getMinKey());

	obj = AllOne();
	obj.inc("a");
	obj.inc("b");
	obj.inc("b");
	obj.inc("b");
	obj.inc("b");
	obj.dec("b");
	obj.dec("b");
	assert("b" == obj.getMaxKey());
	assert("a" == obj.getMinKey());

	obj = AllOne();
	obj.inc("a");
	obj.inc("b");
	obj.inc("b");
	obj.inc("c");
	obj.inc("c");
	obj.inc("c");
	obj.dec("b");
	obj.dec("b");
	assert("a" == obj.getMinKey());
	obj.dec("a");
	assert("c" == obj.getMaxKey());
	assert("c" == obj.getMinKey());

	cout << "\nPassed All\n";
	return 0;
}
