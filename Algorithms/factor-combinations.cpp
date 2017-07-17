// 254. Factor Combinations
// https://leetcode.com/problems/factor-combinations/

/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples: 
input: 1
output: 
[]
input: 37
output: 
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

class Solution {
public:
	vector<vector<int>> getFactors(int n) {
		if (n <= 1) {
			return {};
		}
		return f(2, n);
	}
private:
	vector<vector<int>> f(int low, int n) {
		vector<vector<int>> result;
		for (int m = sqrt(n), i = low; i <= m; ++i) {
			if (n % i == 0) {
				result.push_back({i, n / i});
				vector<vector<int>> A = f(i, n / i);
				for (auto & j : A) {
					j.insert(begin(j), i);
					result.push_back(j);
				}
			}
		}
		return result;
	}
};