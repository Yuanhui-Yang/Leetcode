// 379. Design Phone Directory
// https://leetcode.com/problems/design-phone-directory/
#include <iostream>
#include <cassert>
#include <queue>
#include <functional>
#include <unordered_set>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/53101/c-solution-using-two-arrays-to-simulate-queue-and-hashset
class PhoneDirectory {
public:
	/** Initialize your data structure here
	@param maxNumbers - The maximum numbers that can be stored in the phone directory. */
	PhoneDirectory(int maxNumbers) {
		for (int i = 0; i < maxNumbers; i++) this->qe.push(i);
		this->used.resize(maxNumbers, 0);
		this->maxNumbers = maxNumbers;
	}

	/** Provide a number which is not assigned to anyone.
	@return - Return an available number. Return -1 if none is available. */
	int get() {
		if (this->qe.empty()) return -1;
		int result = this->qe.front();
		this->qe.pop();
		this->used[result] = 1;
		return result;
	}

	/** Check if a number is available or not. */
	bool check(int number) {
		if (number < 0 || number >= this->maxNumbers) return false;
		return !this->used[number];
	}

	/** Recycle or release a number. */
	void release(int number) {
		if (!this->used[number]) return;
		this->used[number] = 0;
		this->qe.push(number);
	}
private:
	queue<int> qe;
	vector<int> used;
	int maxNumbers;
};
// END: https://discuss.leetcode.com/topic/53101/c-solution-using-two-arrays-to-simulate-queue-and-hashset

// BEGIN: Time Limit Exceeded
// class PhoneDirectory {
// public:
// 	/** Initialize your data structure here
// 	@param maxNumbers - The maximum numbers that can be stored in the phone directory. */
// 	PhoneDirectory(int maxNumbers) {
// 		for (int i = 0; i < maxNumbers; i++) this->qe.push(i);
// 		this->used.clear();
// 		this->maxNumbers = maxNumbers;
// 	}

// 	/** Provide a number which is not assigned to anyone.
// 	@return - Return an available number. Return -1 if none is available. */
// 	int get() {
// 		if (this->qe.empty()) return -1;
// 		int result = this->qe.front();
// 		this->qe.pop();
// 		this->used.insert(result);
// 		return result;
// 	}

// 	/** Check if a number is available or not. */
// 	bool check(int number) {
// 		if (number < 0 || number >= this->maxNumbers) return false;
// 		return !this->used.count(number);
// 	}

// 	/** Recycle or release a number. */
// 	void release(int number) {
// 		if (!this->used.count(number)) return;
// 		this->used.erase(number);
// 		this->qe.push(number);
// 	}
// private:
// 	queue<int> qe;
// 	unordered_set<int> used;
// 	int maxNumbers;
// };
// END: Time Limit Exceeded

// BEGIN: Time Limit Exceeded
// class PhoneDirectory {
// public:
// 	/** Initialize your data structure here
// 	@param maxNumbers - The maximum numbers that can be stored in the phone directory. */
// 	PhoneDirectory(int maxNumbers) {
// 		for (int i = 0; i < maxNumbers; i++) this->pq.push(i);
// 		this->used.clear();
// 	}

// 	/** Provide a number which is not assigned to anyone.
// 	@return - Return an available number. Return -1 if none is available. */
// 	int get() {
// 		if (this->pq.empty()) return -1;
// 		int result = this->pq.top();
// 		this->pq.pop();
// 		this->used.insert(result);
// 		return result;
// 	}

// 	/** Check if a number is available or not. */
// 	bool check(int number) {
// 		return !this->used.count(number);
// 	}

// 	/** Recycle or release a number. */
// 	void release(int number) {
// 		if (!this->used.count(number)) return;
// 		this->used.erase(number);
// 		this->pq.push(number);
// 	}
// private:
// 	priority_queue<int, vector<int>, greater<int>> pq;
// 	unordered_set<int> used;
// };
// END: Time Limit Exceeded

// BEGIN: Time Limit Exceeded
// class PhoneDirectory {
// public:
// 	/** Initialize your data structure here
// 	@param maxNumbers - The maximum numbers that can be stored in the phone directory. */
// 	PhoneDirectory(int maxNumbers) {
// 		this->used.clear();
// 		this->maxNumbers = maxNumbers;
// 	}

// 	/** Provide a number which is not assigned to anyone.
// 	@return - Return an available number. Return -1 if none is available. */
// 	int get() {
// 		for (int i = 0; i < maxNumbers; i++) {
// 			if (!used.count(i)) {
// 				used.insert(i);
// 				return i;
// 			}
// 		}
// 		return -1;
// 	}

// 	/** Check if a number is available or not. */
// 	bool check(int number) {
// 		return !used.count(number);
// 	}

// 	/** Recycle or release a number. */
// 	void release(int number) {
// 		if (used.count(number)) used.erase(number);
// 	}
// private:
// 	unordered_set<int> used;
// 	int maxNumbers;
// };
// END: Time Limit Exceeded
/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

int main(void) {
	PhoneDirectory directory(3);
	assert(0 == directory.get());
	assert(1 == directory.get());
	assert(true == directory.check(2));
	assert(2 == directory.get());
	directory.release(2);
	assert(true == directory.check(2));
	cout << "\nPassed All\n";
	return 0;
}