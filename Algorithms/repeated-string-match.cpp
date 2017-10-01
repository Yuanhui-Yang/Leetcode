// 686. Repeated String Match
// https://leetcode.com/problems/repeated-string-match/

/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		int result = -1, i = 0, j = 0, sz1 = A.size(), sz2 = B.size();
		for (i = 0; i < sz1; ++i) {
			j = (sz2 + i) % sz1 == 0 ? (sz2 + i) / sz1 : (sz2 + i) / sz1 + 1;
			if (f(A, B, i) and (result < 0 or j < result)) {
				result = j;
			}
		}
		return result;
	}
private:
	bool f(const string & A, const string & B, const int start) {
		int sz1 = A.size(), sz2 = B.size(), i = 0;
		for (i = 0; i < sz2; ++i) {
			if (A[(start + i) % sz1] != B[i]) {
				return false;
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution;
	string A, B;
	int result;
	
	A = "abcd";
	B = "cdabcdab";
	result = solution.repeatedStringMatch(A, B);
	cout << result << '\n';
	
	return 0;
}