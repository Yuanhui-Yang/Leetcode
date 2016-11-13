// 455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		if (g.empty() || s.empty()) return 0;
		const int m = g.size(), n = s.size();
		sort(begin(g), end(g));
		sort(begin(s), end(s));
		int result = 0;
		for (int i = 0, j = 0; i < m && j < n; i++) {
			if (g[i] > s.back()) return result;
			vector<int>::iterator it = lower_bound(begin(s) + j, end(s), g[i]);
			j = distance(begin(s), it) + 1;
			result++;
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> g, s;
	g = {1,2,3};
	s = {1,1};
	cout << solution.findContentChildren(g, s) << "\tPassed\n";
	g = {1,2};
	s = {1,2,3};
	cout << solution.findContentChildren(g, s) << "\tPassed\n";
	g = {1,2,3};
	s = {3};
	cout << solution.findContentChildren(g, s) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}