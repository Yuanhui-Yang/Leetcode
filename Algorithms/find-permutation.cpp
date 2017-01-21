// 484. Find Permutation
// https://leetcode.com/problems/find-permutation/
#include <iostream>
#include <cassert>
#include <cctype>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cfloat>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> findPermutation(string s) {
		vector<int> result(s.size() + 1, 0);
		findPermutation(1, 0, s.size() + 1, s, result);
		return result;
	}
private:
	void findPermutation(const int minVal, const size_t lowerBound, const size_t upperBound, const string& s, vector<int>& result) {
		if (lowerBound >= upperBound) {
			return;
		}
		size_t i = lowerBound;
		while (i + 1 < upperBound && s[i] == 'D') {
			i++;
		}
		result[i] = minVal;
		findPermutation(minVal + 1, lowerBound, i, s, result);
		findPermutation(minVal + 1 + i - lowerBound, i + 1, upperBound, s, result);
	}
};
int main(void) {
	Solution solution;
	string s;
	vector<int> result;

	s = "I";
	result = solution.findPermutation(s);
	assert(vector<int>({1, 2}) == result);

	s = "DI";
	result = solution.findPermutation(s);
	assert(vector<int>({2, 1, 3}) == result);

	s = "DDIIDI";
	result = solution.findPermutation(s);
	assert(vector<int>({3, 2, 1, 4, 6, 5, 7}) == result);

	s = "DDDDIIIIIIDDDDDDDD";
	result = solution.findPermutation(s);
	assert(vector<int>({5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 19, 18, 17, 16, 15, 14, 13, 12, 11}) == result);

	cout << "\nPassed All\n";
	return 0;
}