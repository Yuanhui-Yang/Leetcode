// 460. LFU Cache
// https://leetcode.com/problems/lfu-cache/

// Design and implement a data structure for Least Frequently Used (LFU) cache [https://en.wikipedia.org/wiki/Least_frequently_used]. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:

// LFUCache cache = new LFUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.get(3);       // returns 3.
// cache.put(4, 4);    // evicts key 1.
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
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class LFUCache {
public:
	LFUCache(int capacity) {
		this->h1.clear();
		this->h2.clear();
		this->m.clear();
		this->capacity = capacity;
	}

	int get(int key) {
		if (!capacity or h3.empty() or !h3.count(key)) {
			return -1;
		}
		list<list<pair<int, int>>>::iterator x = h1.at(key);
		list<pair<int, int>>::iterator y = h2.at(key);
		int freq = ++h3.at(key), value = y->second;
		if (next(x) == end(m) or freq < h3.at(begin(*next(x))->first)) {
			m.insert(next(x), list<pair<int, int>>({*y}));
		}
		else {
			next(x)->push_back(*y);
		}
		h1.at(key) = next(x);
		h2.at(key) = prev(end(*next(x)));
		x->erase(y);
		if (x->empty()) {
			m.erase(x);
		}
		return value;
	}	

	void put(int key, int value) {
		if (!capacity) {
			return;
		}
		if (!h3.empty() and h3.count(key)) {
			list<list<pair<int, int>>>::iterator x = h1.at(key);
			list<pair<int, int>>::iterator y = h2.at(key);
			int freq = ++h3.at(key);
			if (next(x) == end(m) or freq < h3.at(begin(*next(x))->first)) {
				m.insert(next(x), list<pair<int, int>>({make_pair(key, value)}));
			}
			else {
				next(x)->push_back({make_pair(key, value)});
			}
			h1.at(key) = next(x);
			h2.at(key) = prev(end(*next(x)));
			x->erase(y);
			if (x->empty()) {
				m.erase(x);
			}
			return;
		}
		if (h3.size() == capacity) {
			h1.erase(begin(m)->front().first);
			h2.erase(begin(m)->front().first);
			h3.erase(begin(m)->front().first);
			begin(m)->pop_front();
			if (begin(m)->empty()) {
				m.pop_front();
			}
		}
		if (h3.empty() or h3.at(begin(m)->front().first) > 1) {
			m.insert(begin(m), list<pair<int, int>>({make_pair(key, value)}));
		}
		else {
			begin(m)->push_back(make_pair(key, value));
		}
		h1[key] = begin(m);
		h2[key] = prev(end(*begin(m)));
		h3[key] = 1;
	}
private:
	unordered_map<int, list<list<pair<int, int>>>::iterator> h1;
	unordered_map<int, list<pair<int, int>>::iterator> h2;
	list<list<pair<int, int>>> m;
	unordered_map<int, int> h3;
	size_t capacity;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(void) {
	LFUCache cache(2 /* capacity */ );
	cache.put(1, 1);
	cache.put(2, 2);
	assert(1 == cache.get(1));	// returns 1
	cache.put(3, 3);	// evicts key 2
	assert(-1 == cache.get(2));	// returns -1 (not found)
	assert(3 == cache.get(3));	// returns 3.
	cache.put(4, 4);	// evicts key 1.
	assert(-1 == cache.get(1));	// returns -1 (not found)
	assert(3 == cache.get(3));	// returns 3
	assert(4 == cache.get(4));	// returns 4

	cache = LFUCache(3);
	cache.put(2, 2);
	cache.put(1, 1);
	assert(2 == cache.get(2));	// returns 2
	assert(1 == cache.get(1));	// returns 1
	assert(2 == cache.get(2));	// returns 2
	cache.put(3, 3);
	cache.put(4, 4);
	assert(-1 == cache.get(3));	// returns -1
	assert(2 == cache.get(2));	// returns 2
	assert(1 == cache.get(1));	// returns 1
	assert(4 == cache.get(4));	// returns 4

	cache = LFUCache(0);
	cache.put(0, 0);
	assert(-1 == cache.get(0));	// returns -1

	cache = LFUCache(2);
	cache.put(2, 1);
	cache.put(2, 2);
	assert(2 == cache.get(2));	// returns 2
	cache.put(1, 1);
	cache.put(4, 1);
	assert(2 == cache.get(2));	// returns 2

	cout << "\nPassed All\n";
	return 0;
}