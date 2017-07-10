// 170. Two Sum III - Data structure design
// https://leetcode.com/problems/two-sum-iii-data-structure-design/

/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/

class TwoSum {
public:
	/** Initialize your data structure here. */
	TwoSum() {
		dict.clear();
	}
	
	/** Add the number to an internal data structure.. */
	void add(int number) {
		++dict[number];
	}
	
	/** Find if there exists any pair of numbers which sum is equal to the value. */
	bool find(int value) {
		for (const auto & i : dict) {
			int j = value - i.first;
			if (i.first == j and i.second >= 2) {
				return true;
			}
			if (i.first != j and dict.count(j)) {
				return true;
			}
		}
		return false;
	}
private:
	unordered_map<int, int> dict;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */