// 575. Distribute Candies
// https://leetcode.com/problems/distribute-candies/

/*
Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.

Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 
Example 2:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. 
Note:

The length of the given array is in range [2, 10,000], and will be even.
The number in given array is in range [-100,000, 100,000].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		int n = candies.size(), k = 0;
		sort(begin(candies), end(candies));
		for (int i = 0; i < n; ++i) {
			if (i > 0 and candies[i] == candies[i - 1]) {
				continue;
			}
			++k;
		}
		return min(n / 2, k);
	}
};

int main(void) {
	Solution solution;
	vector<int> candies;
	int answer, result;

	candies = {1, 1, 2, 2, 3, 3};
	answer = 3;
	result = solution.distributeCandies(candies);
	assert(answer == result);

	candies = {1, 1, 2, 3};
	answer = 2;
	result = solution.distributeCandies(candies);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}