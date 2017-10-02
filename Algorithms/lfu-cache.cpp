// 460. LFU Cache
// https://leetcode.com/problems/lfu-cache/

/*
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LFUCache cache = new LFUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>

using namespace std;

class LFUCache {
public:
	LFUCache(int capacity) {
		A.clear();
		B.clear();
		this->capacity = capacity;
	}
	
	int get(int key) {
		if (capacity <= 0 or !B.count(key)) {
			return -1;
		}
		pair<list<pair<int, list<pair<int, int>>>>::iterator, list<pair<int, int>>::iterator> p = B[key];
		list<pair<int, list<pair<int, int>>>>::iterator x = p.first, nx = next(x);
		list<pair<int, int>>::iterator y = p.second;
		int result = y->second;
		if (nx == end(A) or x->first + 1 != nx->first) {
			A.insert(nx, {x->first + 1, {}});
			nx = next(x);
		}
		nx->second.splice(end(nx->second), x->second, y);
		B[key] = {nx, prev(end(nx->second))};
		if (x->second.empty()) {
			A.erase(x);
		}
		return result;
	}
	
	void put(int key, int value) {
		if (capacity <= 0) {
			return;
		}
		if (B.count(key)) {
			get(key);
			pair<list<pair<int, list<pair<int, int>>>>::iterator, list<pair<int, int>>::iterator> p = B[key];
			p.second->second = value;
			return;
		}
		if (B.size() == capacity) {
			B.erase(A.front().second.front().first);
			A.front().second.pop_front();
			if (A.front().second.empty()) {
				A.pop_front();
			}
		}
		if (A.empty() or A.front().first != 1) {
			A.push_front({1, {{key, value}}});
		}
		else {
			A.front().second.push_back({key, value});
		}
		B[key] = {begin(A), prev(end(A.front().second))};
	}
private:
	list<pair<int, list<pair<int, int>>>> A;
	unordered_map<int, pair<list<pair<int, list<pair<int, int>>>>::iterator, list<pair<int, int>>::iterator>> B;
	int capacity = 0;
};

int main(void) {
	LFUCache cache( 2 /* capacity */ );

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << '\n';       // returns 1
	cache.put(3, 3);                    // evicts key 2
	cout << cache.get(2) << '\n';       // returns -1 (not found)
	cout << cache.get(3) << '\n';       // returns 3.
	cache.put(4, 4);                    // evicts key 1.
	cout << cache.get(1) << '\n';       // returns -1 (not found)
	cout << cache.get(3) << '\n';       // returns 3
	cout << cache.get(4) << '\n';       // returns 4

	return 0;
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */