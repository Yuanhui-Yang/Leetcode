// 599. Minimum Index Sum of Two Lists
// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

/*
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, int> h;
		for (int n = list2.size(), i = 0; i < n; ++i) {
			h[list2[i]] = i;
		}
		vector<string> result;
		for (int n = list1.size(), sum = list1.size() + list2.size(), i = 0; i < n; ++i) {
			const string& s = list1[i];
			if (h.count(s)) {
				if (h[s] + i < sum) {
					result.clear();
					result.push_back(s);
					sum = h[s] + i;
					continue;
				}
				if (h[s] + i == sum) {
					result.push_back(s);
					continue;
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<string> list1, list2, answer, result;

	list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
	answer = {"Shogun"};
	sort(begin(answer), end(answer));
	result = solution.findRestaurant(list1, list2);
	sort(begin(result), end(result));
	assert(answer == result);

	list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	list2 = {"KFC", "Shogun", "Burger King"};
	answer = {"Shogun"};
	sort(begin(answer), end(answer));
	result = solution.findRestaurant(list1, list2);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}