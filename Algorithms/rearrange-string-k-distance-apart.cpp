// 358. Rearrange String k Distance Apart
// https://leetcode.com/problems/rearrange-string-k-distance-apart/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <map>
using namespace std;
// BEGIN: http://www.cnblogs.com/grandyang/p/5586009.html
class Solution {
public:
	string rearrangeString(string str, int k) {
		if (!k) {
			return str;
		}
		vector<size_t> hashMap(26);
		for (const auto &c : str) {
			hashMap[c - 'a']++;
		}
		map<size_t, list<char>> treeMap;
		for (int i = 0; i < 26; i++) {
			if (hashMap[i]) {
				treeMap[hashMap[i]].push_back('a' + i);
			}
		}
		string result;
		size_t strLen = str.size();
		while (!treeMap.empty()) {
			const size_t upperBound = min(size_t(k), strLen);
			vector<pair<size_t, char>> tmp4TreeMap;
			for (size_t i = 0; i < upperBound; i++, strLen--) {
				if (treeMap.empty()) {
					return "";
				}
				map<size_t, list<char>>::iterator treeMapMaxElement = prev(end(treeMap));
				result.push_back(treeMapMaxElement->second.front());
				if (treeMapMaxElement->first > 1) {
					tmp4TreeMap.push_back(make_pair(treeMapMaxElement->first - 1, treeMapMaxElement->second.front()));
				}
				treeMapMaxElement->second.pop_front();
				if (treeMapMaxElement->second.empty()) {
					treeMap.erase(treeMapMaxElement);
				}
			}
			for (const auto &j : tmp4TreeMap) {
				treeMap[j.first].push_back(j.second);
			}
		}
		return result;
	}
public:
	bool validate(string str, int k) {
		vector<vector<size_t>> hashMap(26);
		for (size_t i = 0; i < str.size(); i++) {
			hashMap[str[i] - 'a'].push_back(i);
		}
		for (int i = 0; i < 26; i++) {
			if (hashMap[i].size() > 1) {
				sort(begin(hashMap[i]), end(hashMap[i]));
				for (size_t j = 1; j < hashMap[i].size(); j++) {
					if (hashMap[i][j] - hashMap[i][j - 1] < size_t(k)) {
						return false;
					}
				}
			}
		}
		return true;
	}
};
// END: http://www.cnblogs.com/grandyang/p/5586009.html
int main(void) {
	Solution solution;
	string result;

	result = solution.rearrangeString("a", 0);
	assert(solution.validate(result, 0));

	result = solution.rearrangeString("aabbcc", 3);
	assert(solution.validate(result, 3));

	result = solution.rearrangeString("aaabc", 3);
	assert(solution.validate(result, 3));

	result = solution.rearrangeString("aaadbbcc", 2);
	assert(solution.validate(result, 2));

	cout << "\nPassed All\n";
	return 0;
}