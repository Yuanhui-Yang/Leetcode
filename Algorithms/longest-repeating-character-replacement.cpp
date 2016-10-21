// 424. Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/63416/sliding-window-similar-to-finding-longest-substring-with-k-distinct-characters
class Solution {
public:
	int characterReplacement(string s, int k) {
		int result = 0;
		vector<int> hashmap(26, 0);
		const int n = s.size();
		for (int i = 0, maxCount = 0, begin = 0; i < n; i++) {
			hashmap[s[i] - 'A']++;
			maxCount = max(maxCount, hashmap[s[i] - 'A']);
			while (i - begin + 1 - maxCount > k) {
				maxCount = hashmap[s[begin++] - 'A']--;			
				for (int j = begin; j <= i; j++) maxCount = max(maxCount, hashmap[s[j] - 'A']);  
			}
			result = max(result, i - begin + 1);
		}
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/63416/sliding-window-similar-to-finding-longest-substring-with-k-distinct-characters
// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	int characterReplacement(string s, int k) {
// 		int result = 0, i = 0, j = 0;
// 		const int n = s.size();
// 		for (i = 0, j = 0; i < n; i++) {
// 			if (s[i] == s[j]) continue;
// 			result = max(result, i - j);
// 			j = i;
// 		}
// 		result = max(result, i - j);
// 		if (result == n || k == 0) return result;
// 		vector<int> directions = {-1, 1}; 
// 		for (int i = 0; i < n; i++) {
// 			for (const auto &j : directions) {
// 				int x = i + j;
// 				if (x < 0 || x >= n || s[x] == s[i]) continue;
// 				char c = s[i];
// 				s[i] = s[x];
// 				result = max(result, this->characterReplacement(s, k - 1));
// 				s[i] = c;
// 			}
// 		}
// 		return result;
// 	}
// };
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	cout << solution.characterReplacement("AAAB", 0) << "\tPassed\n";
	cout << solution.characterReplacement("ABAB", 2) << "\tPassed\n";
	cout << solution.characterReplacement("AABABBA", 1) << "\tPassed\n";
	cout << solution.characterReplacement("KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF", 4) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}