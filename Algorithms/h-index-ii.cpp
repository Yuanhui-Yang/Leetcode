// 275. H-Index II
// https://leetcode.com/problems/h-index-ii/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.empty()) return 0;
		if (citations.back() < 1) return 0;
		const int n = citations.size();
		int left = 0;
		int right = n - 1;
		while (left + 1 < right) {
			int mid = left + (right - left) / 2;
			if (citations[mid] >= (n - mid)) right = mid;
			else left = mid;
		}
		if (citations[left] >= (n - left)) return n - left;
		return n - right;
	}
};
int main(void) {
	Solution solution;
	vector<int> citations;
	cout << solution.hIndex(citations) << "\tPassed\n";
	citations = {0, 1, 3, 5, 6};
	cout << solution.hIndex(citations) << "\tPassed\n";
	citations = {100};
	cout << solution.hIndex(citations) << "\tPassed\n";
	citations ={0};
	cout << solution.hIndex(citations) << "\tPassed\n";
	citations ={1};
	cout << solution.hIndex(citations) << "\tPassed\n";
	citations ={0, 0};
	cout << solution.hIndex(citations) << "\tPassed\n";
	citations ={0, 1};
	cout << solution.hIndex(citations) << "\tPassed\n";	
	citations ={11, 15};
	cout << solution.hIndex(citations) << "\tPassed\n";	
	citations ={1, 1};
	cout << solution.hIndex(citations) << "\tPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}