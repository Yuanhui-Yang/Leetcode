// 604. Design Compressed String Iterator
// https://leetcode.com/problems/design-compressed-string-iterator/

/*
Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.

Example:

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '
*/

#include <bits/stdc++.h>
using namespace std;

class StringIterator {
public:
	StringIterator(string compressedString) {
		i = 0;
		v.clear();
		size_t n = compressedString.size(), j = 0;
		while (j < n) {
			char ch = compressedString[j++];
			size_t k = 0;
			while (j < n and isdigit(compressedString[j])) {
				k = 10 * k + (compressedString[j++] - '0');
			}
			v.push_back({k, ch});
		}
	}

	char next() {
		if (i >= v.size()) {
			return ' ';
		}
		pair<size_t, char> &p = v[i];
		if (--p.first == 0) {
			++i;
		}
		return p.second;
	}

	bool hasNext() {
		return i < v.size();
	}
private:
	size_t i;
	vector<pair<size_t, char>> v;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

int main(void) {
	StringIterator iterator("L1e2t1C1o1d1e1");
	char a, b;
	bool c, d;

	a = 'L';
	b = iterator.next();
	assert(a == b);

	a = 'e';
	b = iterator.next();
	assert(a == b);

	a = 'e';
	b = iterator.next();
	assert(a == b);

	a = 't';
	b = iterator.next();
	assert(a == b);

	a = 'C';
	b = iterator.next();
	assert(a == b);

	a = 'o';
	b = iterator.next();
	assert(a == b);

	a = 'd';
	b = iterator.next();
	assert(a == b);

	c = true;
	d = iterator.hasNext();
	assert(c == d);

	a = 'e';
	b = iterator.next();
	assert(a == b);

	c = false;
	d = iterator.hasNext();
	assert(c == d);

	a = ' ';
	b = iterator.next();
	assert(a == b);

	cout << "\nPassed All\n";
	return 0;
}