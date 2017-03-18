// 146. LRU Cache
// https://leetcode.com/problems/lru-cache/

// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:

// LRUCache cache = new LRUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

#include <iostream> // std::cout; std::cin
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // memset
#include <algorithm> // max; min; min_element; max_element; minmax_element; next_permutation; prev_permutation; nth_element; sort; swap; lower_bound; upper_bound; reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::string::npos
#include <list>
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility> // pair; make_pair; swap
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) {
		h.clear();
		l.clear();
		this->capacity = capacity;
	}

	int get(int key) {
		if (h.empty() or !h.count(key)) {
			return -1;
		}
		list<pair<int, int>>::iterator it = h.at(key);
		l.splice(end(l), l, it);
		return l.back().second;
	}

	void put(int key, int value) {
		if (h.empty() or !h.count(key)) {
			if (h.size() == capacity) {
				h.erase(l.front().first);
				l.pop_front();
			}
			l.push_back(make_pair(key, value));
			h[key] = prev(end(l));
			return;
		}
		list<pair<int, int>>::iterator it = h.at(key);
		l.splice(end(l), l, it);
		it->second = value;
	}
private:
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator> h;
	size_t capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(void) {
	LRUCache cache( 2 /* capacity */ );
	cache.put(1, 1);
	cache.put(2, 2);
	assert(1 == cache.get(1));	// returns 1
	cache.put(3, 3);	// evicts key 2
	assert(-1 == cache.get(2));	// returns -1 (not found)
	cache.put(4, 4);	// evicts key 1
	assert(-1 == cache.get(1));	// returns -1 (not found)
	assert(3 == cache.get(3));	// returns 3
	assert(4 == cache.get(4));	// returns 4

	cache = LRUCache(2);
	cache.put(2, 1);
	cache.put(1, 1);
	cache.put(2, 3);
	cache.put(4, 1);
	assert(-1 == cache.get(1));	// returns -1
	assert(3 == cache.get(2));	// returns 3

	cout << "\nPassed All\n";
	return 0;
}