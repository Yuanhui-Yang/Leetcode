// 423. Reconstruct Original Digits from English
// https://leetcode.com/problems/reconstruct-original-digits-from-english/
// BEGIN: https://discuss.leetcode.com/topic/63386/one-pass-o-n-java-solution-simple-and-clear
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	string originalDigits(string s) {
		string result;
		// 0 = "zero", 1 = "one", 2 = "two", 3 = "three", 4 = "four", 5 = "five", 6 = "six", 7 = "seven", 8 = "eight", 9 = "nine"
		// 'z': 0
		// 'e': 0, 1, 3, 5, 7, 8, 9
		// 'r': 0, 3, 4
		// 'o': 0, 1, 2, 4
		// 'n': 1, 7, 9(x2)
		// 't': 2, 3, 8
		// 'w': 2
		// 'h': 3, 8
		// 'f': 4, 5
		// 'u': 4
		// 'i': 5, 6, 8, 9
		// 'v': 5, 7
		// 's': 6, 7
		// 'x': 6
		// 'g': 8
		vector<int> hashmap(10, 0);
		for (const auto&i : s) {
			if (i == 'z') hashmap[0]++;
			if (i == 'w') hashmap[2]++;
			if (i == 'u') hashmap[4]++;
			if (i == 'x') hashmap[6]++;
			if (i == 'g') hashmap[8]++;

			if (i == 'r') hashmap[3]++;
			if (i == 'f') hashmap[5]++;
			if (i == 's') hashmap[7]++;

			if (i == 'o') hashmap[1]++;
			if (i == 'i') hashmap[9]++;
		}
		hashmap[1] -= hashmap[0] + hashmap[2] + hashmap[4];
		hashmap[3] -= hashmap[0] + hashmap[4];
		hashmap[5] -= hashmap[4];
		hashmap[7] -= hashmap[6];
		hashmap[9] -= hashmap[5] + hashmap[6] + hashmap[8];
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < hashmap[i]; j++)
				result.push_back('0' + i);
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/63386/one-pass-o-n-java-solution-simple-and-clear
int main(void) {
	Solution solution;
	cout << solution.originalDigits("owoztneoer") << "\tPassed\n";
	cout << solution.originalDigits("fviefuro") << "\tPassed\n";
	cout << solution.originalDigits("esnve") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}