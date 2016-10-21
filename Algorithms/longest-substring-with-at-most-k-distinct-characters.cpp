// 340. Longest Substring with At Most K Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <unordered_map>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/7399/share-my-c-solution
class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		const int n = s.size();
		int result = 0;
		vector<int> hashmap(256, 0);
		for (int i = 0, begin = 0, count = 0; i < n; i++) {
			hashmap[s[i]]++;
			if (hashmap[s[i]] == 1) count++;
			while (count > k) {
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
	cout << solution.lengthOfLongestSubstringKDistinct("eceba", 2) << "\tPasse\n";
	cout << "\nPassed All\n";
	return 0;
}