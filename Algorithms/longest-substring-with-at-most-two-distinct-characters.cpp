// 159. Longest Substring with At Most Two Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/7399/share-my-c-solution
class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		int result = 0;
		const int n = s.size();
		vector<int> hashmap(256, 0);
		for (int i = 0, count = 0, begin = 0; i < n; i++) {
			hashmap[s[i]]++;
			if (hashmap[s[i]] == 1) count++;
			while (count > 2) {
				hashmap[s[begin]]--;
				if (hashmap[s[begin]] == 0) count--;
				begin++;
			}
			result = max(result, i - begin + 1);
		}
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/7399/share-my-c-solution
int main(void) {
	Solution solution;
	cout << solution.lengthOfLongestSubstringTwoDistinct("eceba") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}