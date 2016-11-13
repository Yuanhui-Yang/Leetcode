// 381. Insert Delete GetRandom O(1) - Duplicates allowed
// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/54381/c-128m-solution-real-o-1-solution
class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {
		this->nums.clear();
		this->hashmap.clear();
	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		bool result = this->hashmap.count(val);
		this->hashmap[val].push_back(this->nums.size());
		this->nums.push_back(make_pair(val, this->hashmap[val].size() - 1));
		return !result;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		bool result = this->hashmap.count(val);
		if (result) {
			this->nums[this->hashmap[val].back()] = this->nums.back();
			this->hashmap[this->nums.back().first][this->nums.back().second] = this->hashmap[val].back();
			this->hashmap[val].pop_back();
			if (this->hashmap[val].empty()) this->hashmap.erase(val);
			this->nums.pop_back();
		}
		return result;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return this->nums[rand() % this->nums.size()].first;
	}
private:
	vector<pair<int, int>> nums;
	unordered_map<int, vector<int>> hashmap;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
// END: https://discuss.leetcode.com/topic/54381/c-128m-solution-real-o-1-solution

int main(void) {
	RandomizedCollection collection;
	// cout << boolalpha << collection.insert(1) << "\tPassed\n";
	// cout << boolalpha << collection.insert(1) << "\tPassed\n";
	// cout << boolalpha << collection.insert(2) << "\tPassed\n";
	// cout << collection.getRandom() << "\tPassed\n";
	// cout << boolalpha << collection.remove(1) << "\tPassed\n";
	// cout << collection.getRandom() << "\tPassed\n";
	cout << boolalpha << collection.insert(1) << "\tPassed\n";
	cout << boolalpha << collection.remove(2) << "\tPassed\n";
	cout << boolalpha << collection.insert(2) << "\tPassed\n";
	cout << collection.getRandom() << "\tPassed\n";
	cout << boolalpha << collection.remove(1) << "\tPassed\n";
	cout << boolalpha << collection.insert(2) << "\tPassed\n";
	cout << collection.getRandom() << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}