// 434. Number of Segments in a String
// https://leetcode.com/problems/number-of-segments-in-a-string/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
class Solution {
public:
	int countSegments(string s) {
		int result = 0;
		const int n = s.size();
		for (int i = 0; i < n; i++) {
			if (s[i] == ' ') continue;
			result++;
			while (i < n && s[i] != ' ') i++;
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	assert(5 == solution.countSegments("Hello, my name is John"));
	cout << "\nPassed All\n";
	return 0;
}