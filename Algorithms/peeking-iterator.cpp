// 284. Peeking Iterator
// https://leetcode.com/problems/peeking-iterator/
// BEGIN: https://discuss.leetcode.com/topic/24909/simple-c-solution-1-line-per-method-without-extra-member-variables
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.

	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return Iterator(*this).next();
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		return this->Iterator::next();
	}

	bool hasNext() const {
		return this->Iterator::hasNext();
	}
};
// END: https://discuss.leetcode.com/topic/24909/simple-c-solution-1-line-per-method-without-extra-member-variables