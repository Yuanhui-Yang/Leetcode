// 358. Rearrange String k Distance Apart
// https://leetcode.com/problems/rearrange-string-k-distance-apart/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
	string rearrangeString(string str, int k) {

	}
};
int main(void) {
	Solution solution;
	string result;

	result = solution.rearrangeString("aabbcc", 3);
	assert(unordered_set<string>({"abcabc"}).count(result));

	result = solution.rearrangeString("aaabc", 3);
	assert(unordered_set<string>({""}).count(result));

	result = solution.rearrangeString("aaadbbcc", 2);
	assert(unordered_set<string>({"abacabcd", "abcabcda"}).count(result));

	cout << "\nPassed All\n";
	return 0;
}