// 380. Insert Delete GetRandom O(1)
// https://leetcode.com/problems/insert-delete-getrandom-o1/
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;
class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		this->hashmap.clear();
		this->array.clear();
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (this->hashmap.count(val)) return false;
		this->hashmap[val] = this->array.size();
		this->array.push_back(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (!this->hashmap.count(val)) return false;
		this->array[this->hashmap[val]] = this->array.back();
		this->hashmap[this->array.back()] = this->hashmap[val];
		this->array.pop_back();
		this->hashmap.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return this->array[rand() % this->array.size()];
	}
private:
	unordered_map<int, int> hashmap;
	vector<int> array;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(void) {
	RandomizedSet randomSet;
	cout << boolalpha << randomSet.insert(1) <<  "\tPassed\n";
	cout << boolalpha << randomSet.remove(2) <<  "\tPassed\n";
	cout << boolalpha << randomSet.insert(2) <<  "\tPassed\n";
	cout << boolalpha << randomSet.getRandom() <<  "\tPassed\n";
	cout << boolalpha << randomSet.remove(1) <<  "\tPassed\n";
	cout << boolalpha << randomSet.insert(2) <<  "\tPassed\n";
	cout << boolalpha << randomSet.getRandom() <<  "\tPassed\n";
	cout <<  "\nPassed All\n";
	return 0;
}