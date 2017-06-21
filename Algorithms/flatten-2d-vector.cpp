// 251. Flatten 2D Vector
// https://leetcode.com/problems/flatten-2d-vector/

/*
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/

#include <bits/stdc++.h>
using namespace std;

class Vector2D {
public:
	Vector2D(vector<vector<int>>& vec2d) {
		if (vec2d.empty()) {
			return;
		}
		x = begin(vec2d);
		z = end(vec2d);
		while (x != z and x->empty()) {
			++x;
		}
		if (x != z) {
			y = begin(*x);   
		}
	}

	int next() {
		int result = *y;
		if (++y == end(*x)) {
			++x;
			while (x != z and x->empty()) {
				++x;
			}
			if (x != z) {
				y = begin(*x);
			}
		}
		return result;
	}

	bool hasNext() {
		return x != z;
	}
private:
vector<vector<int>>::iterator x, z;
vector<int>::iterator y;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

int main(void) {
	vector<vector<int>> vec2d;
	Vector2D i(vec2d);
	vector<int> answer, result;

	vec2d = {};
	i = Vector2D(vec2d);
	answer = {};
	result.clear();
	while (i.hasNext()) {
		result.push_back(i.next());
	}
	assert(answer == result);

	vec2d = {{}};
	i = Vector2D(vec2d);
	answer = {};
	result.clear();
	while (i.hasNext()) {
		result.push_back(i.next());
	}
	assert(answer == result);

	vec2d = {{1}, {}};
	i = Vector2D(vec2d);
	answer = {1};
	result.clear();
	while (i.hasNext()) {
		result.push_back(i.next());
	}
	assert(answer == result);

	vec2d = {{1, 2}, {3}, {4, 5, 6}};
	i = Vector2D(vec2d);
	answer = {1, 2, 3, 4, 5, 6};
	result.clear();
	while (i.hasNext()) {
		result.push_back(i.next());
	}
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}