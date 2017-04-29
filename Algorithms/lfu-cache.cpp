// 460. LFU Cache
// https://leetcode.com/problems/lfu-cache/

// Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

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

class LFUCache {
public:
	LFUCache(int capacity) {
		this->capacity = capacity > 0 ? capacity : 0;
		this->l.clear();
		this->h.clear();
	}

	int get(int key) {
		if (capacity == 0 or h.empty() or !h.count(key)) {
			return -1;
		}
		pair<list<pair<int, list<pair<int, int>>>>::iterator, list<pair<int, int>>::iterator> p = h.at(key);
		list<pair<int, list<pair<int, int>>>>::iterator x = p.first;
		list<pair<int, int>>::iterator y = p.second;
		if (next(x) == end(l) or x->first + 1 < next(x)->first) {
			list<pair<int, int>> nx;
			nx.splice(end(nx), x->second, y);
			l.insert(next(x), make_pair(x->first + 1, nx));
			h.at(key) = make_pair(next(x), prev(end(next(x)->second)));
			if (x->second.empty()) {
				l.erase(x);
			}
			return nx.back().second;
		}
		next(x)->second.splice(end(next(x)->second), x->second, y);
		h.at(key).first = next(x);
		if (x->second.empty()) {
			l.erase(x);
		}
		return y->second;
	}

	void put(int key, int value) {
		if (capacity == 0) {
			return ;
		}
		if (!h.empty() and h.count(key)) {
			pair<list<pair<int, list<pair<int, int>>>>::iterator, list<pair<int, int>>::iterator> p = h.at(key);
			list<pair<int, list<pair<int, int>>>>::iterator x = p.first;
			list<pair<int, int>>::iterator y = p.second;
			y->second = value;
			if (next(x) == end(l) or x->first + 1 < next(x)->first) {
				list<pair<int, int>> nx;
				nx.splice(end(nx), x->second, y);
				l.insert(next(x), make_pair(x->first + 1, nx));
				h.at(key) = make_pair(next(x), prev(end(next(x)->second)));
				if (x->second.empty()) {
					l.erase(x);
				}
				return ;
			}
			next(x)->second.splice(end(next(x)->second), x->second, y);
			h.at(key).first = next(x);
			if (x->second.empty()) {
				l.erase(x);
			}
			return;
		}
		if (h.size() == capacity) {
			h.erase(l.front().second.front().first);
			l.front().second.pop_front();
			if (l.front().second.empty()) {
				l.pop_front();
			}
		}
		if (l.empty() or 1 < begin(l)->first) {
			list<pair<int, int>> nx({make_pair(key, value)});
			l.push_front(make_pair(1, nx));
			h[key] = make_pair(begin(l), prev(end(begin(l)->second)));
			return;
		}
		l.front().second.push_back(make_pair(key, value));
		h[key] = make_pair(begin(l), prev(end(begin(l)->second)));
	}
private:
	size_t capacity;
	list<pair<int, list<pair<int, int>>>> l;
	unordered_map<int, pair<list<pair<int, list<pair<int, int>>>>::iterator, list<pair<int, int>>::iterator>> h;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

 int main(void) {
	LFUCache cache(2);

	assert(-1 == cache.get(2));
	cache.put(2, 6);
	assert(-1 == cache.get(1));
	cache.put(1, 5);
	cache.put(1, 2);
	assert(2 == cache.get(1));
	assert(6 == cache.get(2));

	cache = LFUCache(2);
	cache.put(3, 1);
	cache.put(2, 1);
	cache.put(2, 2);
	cache.put(4, 4);
	assert(2 == cache.get(2));

	cache = LFUCache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	assert(1 == cache.get(1));       // returns 1
	cache.put(3, 3);    // evicts key 2
	assert(-1 == cache.get(2));       // returns -1 (not found)
	assert(3 == cache.get(3));       // returns 3.
	cache.put(4, 4);    // evicts key 1.
	assert(-1 == cache.get(1));       // returns -1 (not found)
	assert(3 == cache.get(3));       // returns 3
	assert(4 == cache.get(4));       // returns 4

	cout << "\nPassed All\n";
	return 0;
}
