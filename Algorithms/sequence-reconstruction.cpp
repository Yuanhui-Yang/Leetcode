// 444. Sequence Reconstruction
// https://leetcode.com/problems/sequence-reconstruction/
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
	bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
		if (org.empty() || seqs.empty()) return false;
		const int n = org.size();
		vector<unordered_set<int>> graph(n);
		vector<int> indegrees(n, 0);
		vector<int> result;
		queue<int> zeros;
		for (const auto &i : org) if (i < 1 || i > n) return false;
		for (const auto &i : seqs) for (const auto &j : i) if (j < 1 || j > n) return false;
		for (const auto &seq : seqs) {
			for (int j = 0; j + 1 < (int)seq.size(); j++) {
				if (!graph[seq[j] - 1].count(seq[j + 1] - 1)) {
					graph[seq[j] - 1].insert(seq[j + 1] - 1);
					indegrees[seq[j + 1] - 1]++;
				}
			}
		}
		for (int i = 0; i < n; i++) if (indegrees[i] == 0) zeros.push(i);
		for (int i = 0; i < n; i++) {
			if (zeros.size() != 1) return false;
			int zero = zeros.front();
			zeros.pop();
			result.push_back(zero + 1);
			for (const auto &j : graph[zero]) if (--indegrees[j] == 0) zeros.push(j);
		}
		return result == org;
	}
};
int main(void) {
	Solution solution;
	vector<int> org;
	vector<vector<int>> seqs;
	cout << boolalpha << solution.sequenceReconstruction(org, seqs) << "\tPassed\n";
	org = {1,2,3};
	seqs = {{1,2},{1,3}};
	cout << boolalpha << solution.sequenceReconstruction(org, seqs) << "\tPassed\n";
	org = {1,2,3};
	seqs = {{1,2}};
	cout << boolalpha << solution.sequenceReconstruction(org, seqs) << "\tPassed\n";
	org = {1,2,3};
	seqs = {{1,2},{1,3},{2,3}};
	cout << boolalpha << solution.sequenceReconstruction(org, seqs) << "\tPassed\n";
	org = {4,1,5,2,6,3};
	seqs = {{5,2,6,3},{4,1,5,2}};
	cout << boolalpha << solution.sequenceReconstruction(org, seqs) << "\tPassed\n";
	org = {1,2};
	seqs = {{1,2},{2,1}};
	cout << boolalpha << solution.sequenceReconstruction(org, seqs) << "\tPassed\n";	
	org = {1,2,3};
	seqs = {{1,2},{2,3},{3,1}};
	cout << boolalpha << solution.sequenceReconstruction(org, seqs) << "\tPassed\n";
	org = {5,3,2,4,1};
	seqs = {{5,3,2,4},{4,1},{1},{3},{2,4},{1,1000000000}};
	cout << boolalpha << solution.sequenceReconstruction(org, seqs) << "\tPassed\n";
	org = {5,3,2,4,1};
	seqs = {{5,3,2,4},{4,1},{1},{3},{2,4},{1000000000}};
	cout << boolalpha << solution.sequenceReconstruction(org, seqs) << "\tPassed\n";		
	cout << "\nPassed All\n";
	return 0;
}