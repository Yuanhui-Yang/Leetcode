// 354. Russian Doll Envelopes
// https://leetcode.com/problems/russian-doll-envelopes/

/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		sort(begin(envelopes), end(envelopes), Comp());
		vector<int> v;
		for (const auto &i : envelopes) {
			vector<int>::iterator it = lower_bound(begin(v), end(v), i.second);
			if (it == end(v)) {
				v.push_back(i.second);
			}
			else {
				*it = i.second;
			}
		}
		return v.size();
	}
private:
	struct Comp {
		bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
			return a.first == b.first ? a.second > b.second : a.first < b.first;
		}
	};
};

int main(void) {
	Solution solution;
	vector<pair<int, int>> envelopes;
	int answer, result;

	envelopes = {{4, 5}, {4, 6}, {6, 7}, {2, 3}, {1, 1}};
	answer = 4;
	result = solution.maxEnvelopes(envelopes);
	assert(answer == result);

	envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
	answer = 3;
	result = solution.maxEnvelopes(envelopes);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}