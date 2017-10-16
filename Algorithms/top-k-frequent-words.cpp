// 692. Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words/

/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
	Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
	with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
Can you solve it in O(n) time with only O(k) extra space?
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Pair {
	int freq;
	string str;
	Pair(int freq, string str) {
		this->freq = freq;
		this->str = str;
	}
	bool operator< (const Pair & other) const {
		if (this->freq == other.freq) {
			return this->str < other.str;
		}
		return this->freq > other.freq;
	}
};

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> A;
		for (const auto & i : words) {
			++A[i];
		}
		priority_queue<Pair> B;
		for (const auto & i : A) {
			B.push({i.second, i.first});
			if (B.size() > k) {
				B.pop();
			}
		}
		int sz = B.size();
		vector<string> result(sz);
		while (!B.empty()) {
			result[--sz] = B.top().str;
			B.pop();
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<string> words, result;
	int k;
	
	words = {"i", "love", "leetcode", "i", "love", "coding"};
	k = 2;
	result = solution.topKFrequent(words, k);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
	k = 4;
	result = solution.topKFrequent(words, k);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	return 0;
}