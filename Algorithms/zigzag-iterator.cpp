// 281. Zigzag Iterator
// https://leetcode.com/problems/zigzag-iterator/

/*
Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].
*/

class ZigzagIterator {
public:
	ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		i = 0;
		A[0] = begin(v1);
		A[1] = begin(v2);
		A[2] = end(v1);
		A[3] = end(v2);
	}

	int next() {
		if (A[i] == A[i + 2]) {
			i = 1 - i;
		}
		int result = *A[i];
		++A[i];
		if (A[1 - i] != A[3 - i]) {
			i = 1 - i;
		}
		return result;
	}

	bool hasNext() {
		return !(A[0] >= A[2] and A[1] >= A[3]);
	}
private:
	int i;
	array<vector<int>::iterator, 4> A;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */