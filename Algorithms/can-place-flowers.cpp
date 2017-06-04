// 605. Can Place Flowers
// https://leetcode.com/problems/can-place-flowers/

/*
Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		for (int i = 0, m = flowerbed.size(); n > 0 and i < m; ++i) {
			if (flowerbed[i] == 1) {
				continue;
			}
			if (i - 1 < 0 and i + 1 >= m and flowerbed[i] == 0) {
				flowerbed[i] = 1;
				--n;
				continue;
			}
			if (i - 1 < 0 and i + 1 < m and flowerbed[i + 1] == 0) {
				flowerbed[i] = 1;
				--n;
				continue;
			}
			if (i - 1 >= 0 and i + 1 >= m and flowerbed[i - 1] == 0) {
				flowerbed[i] = 1;
				--n;
				continue;
			}
			if (i - 1 >= 0 and i + 1 < m and flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0) {
				flowerbed[i] = 1;
				--n;
				continue;
			}
		}
		return n <= 0;
	}
};

int main(void) {
	Solution solution;
	vector<int> flowerbed;
	int n;
	bool answer, result;

	flowerbed = {1, 0, 0, 0, 1};
	n = 1;
	answer = true;
	result = solution.canPlaceFlowers(flowerbed, n);
	assert(answer == result);

	flowerbed = {1, 0, 0, 0, 1};
	n = 2;
	answer = false;
	result = solution.canPlaceFlowers(flowerbed, n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}