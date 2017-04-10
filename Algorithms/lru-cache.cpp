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
#include <fstream> // std::fstream::open; std::fstream::close; 
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // std::memset
#include <algorithm> // std::swap; std::max; std::min; std::min_element; std::max_element; std::minmax_element; std::next_permutation; std::prev_permutation; std::nth_element; std::sort; std::lower_bound; std::upper_bound; std::reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::to_string; std::string::npos; std::stoul; std::stoull; std::stoi; std::stol; std::stoll; std::stof; std::stod; std::stold; 
#include <list> // std::list::merge; std::list::splice; std::list::merge; std::list::unique; std::list::sort
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		this->l.clear();
		this->h.clear();
	}

	int get(int key) {
		if (capacity == 0) {
			return -1;
		}
		if (h.empty() or !h.count(key)) {
			return -1;
		}
		l.splice(end(l), l, h.at(key));
		return l.back().second;
	}

	void put(int key, int value) {
		if (capacity == 0) {
			return;
		}
		if (!h.empty() and h.count(key)) {
			l.splice(end(l), l, h.at(key));
			l.back().second = value;
			return;
		}
		if (h.size() < capacity) {
			l.push_back(make_pair(key, value));
			h[key] = prev(end(l));
			return;
		}
		h.erase(l.front().first);
		l.pop_front();
		l.push_back(make_pair(key, value));
		h[key] = prev(end(l));
	}
private:
    size_t capacity;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> h;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(void) {
	LRUCache cache(2);

	cache.put(1, 1);
	cache.put(2, 2);
	assert(1 == cache.get(1));       // returns 1
	cache.put(3, 3);    // evicts key 2
	assert(-1 == cache.get(2));       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	assert(-1 == cache.get(1));       // returns -1 (not found)
	assert(3 == cache.get(3));       // returns 3
	assert(4 == cache.get(4));       // returns 4

	cout << "\nPassed All\n";
	return 0;
}