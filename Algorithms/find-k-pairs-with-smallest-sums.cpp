// 373. Find K Pairs with Smallest Sums
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct Comp {
	bool operator() (const pair<int, int> & a, const pair<int, int> & b) {
		return a.first + a.second < b.first + b.second;
	}
};

class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		int sz1 = nums1.size(), sz2 = nums2.size(), sz3;
		if (sz1 == 0 or sz2 == 0 or k <= 0) {
			return {};
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> A;
		for (const auto & i : nums1) {
			for (const auto & j : nums2) {
				if (A.size() == k) {
					if (i + j >= A.top().first + A.top().second) {
						break;
					}
					else {
						A.pop();
						A.push({i, j});
					}
				}
				else {
					A.push({i, j});
				}
			}
		}
		sz3 = A.size();
		vector<pair<int, int>> result(sz3);
		while (!A.empty()) {
			result[--sz3] = A.top();
			A.pop();
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums1, nums2;
	int k;
	vector<pair<int, int>> result;
	
	nums1 = {1, 7, 11};
	nums2 = {2, 4, 6};
	k = 3;
	result = solution.kSmallestPairs(nums1, nums2, k);
	for (const auto & i : result) {
		cout << i.first << ',' << i.second << '\t';
	}
	cout << '\n';

	nums1 = {1, 1, 2};
	nums2 = {1, 2, 3};
	k = 2;
	result = solution.kSmallestPairs(nums1, nums2, k);
	for (const auto & i : result) {
		cout << i.first << ',' << i.second << '\t';
	}
	cout << '\n';

	nums1 = {1, 2};
	nums2 = {3};
	k = 3;
	result = solution.kSmallestPairs(nums1, nums2, k);
	for (const auto & i : result) {
		cout << i.first << ',' << i.second << '\t';
	}
	cout << '\n';

	nums1 = {-10, -4, 0, 0, 6};
	nums2 = {3, 5, 6, 7, 8, 100};
	k = 10;
	result = solution.kSmallestPairs(nums1, nums2, k);
	for (const auto & i : result) {
		cout << i.first << ',' << i.second << '\t';
	}
	cout << '\n';

	return 0;
}