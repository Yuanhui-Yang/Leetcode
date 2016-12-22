// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <iterator>
#include <queue>
#include <set>
#include <unordered_set>
#include <functional>
using namespace std;
class Solution {
public:
	string frequencySort(string s) {
		sort(begin(s), end(s));
		const int s_size = s.size();
		priority_queue<pair<int, char>> max_heap;
		for (int i = 0; i < s_size; i++) {
			if ((i + 1) < s_size && s[i] == s[i + 1]) {
				int j = i;
				while ((i + 1) < s_size && s[i] == s[i + 1]) i++;
				max_heap.push(make_pair(i - j, s[j]));
				i--;
				continue;
			}
			if (i < s_size) {
				max_heap.push(make_pair(1, s[i]));
				continue;
			}
		}
		string result;
		while (!max_heap.empty()) {
			pair<int, char> max_heap_top = max_heap.top();
			max_heap.pop();
			result += string(max_heap_top.first, max_heap_top.second);
		}
		return result;
	}
};
// class Solution {
// public:
// 	string frequencySort(string s) {
// 		sort(begin(s), end(s));
// 		const int s_size = s.size();
// 		set<pair<int, char>, greater<pair<int, char>>> BST;
// 		for (int i = 0; i < s_size; i++) {
// 			if (i + 1 < s_size && s[i] == s[i + 1]) {
// 				int j = i;
// 				while (i + 1 < s_size && s[i] == s[i + 1]) i++;
// 				BST.insert(make_pair(i - j + 1, s[j]));
// 				continue;
// 			}
// 			if (i < s_size) {
// 				BST.insert(make_pair(1, s[i]));
// 				continue;
// 			}
// 		}
// 		string result;
// 		for (const auto &i : BST) {
// 			result += string(i.first, i.second);
// 		}
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	string result;
	result = solution.frequencySort("tree");
	assert(unordered_set<string>({"eert", "eetr"}).count(result));
	result = solution.frequencySort("cccaaa");
	assert(unordered_set<string>({"cccaaa", "aaaccc"}).count(result));
	result = solution.frequencySort("Aabb");
	assert(unordered_set<string>({"bbAa", "bbaA"}).count(result));
	cout << "\nPassed All\n";
	return 0;
}