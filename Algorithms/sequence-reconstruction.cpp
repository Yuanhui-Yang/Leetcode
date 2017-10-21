// 444. Sequence Reconstruction
// https://leetcode.com/problems/sequence-reconstruction/

/*
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example 1:

Input:
org: [1,2,3], seqs: [[1,2],[1,3]]

Output:
false

Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
Example 2:

Input:
org: [1,2,3], seqs: [[1,2]]

Output:
false

Explanation:
The reconstructed sequence can only be [1,2].
Example 3:

Input:
org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]

Output:
true

Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
Example 4:

Input:
org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]

Output:
true
UPDATE (2017/1/8):
The seqs parameter had been changed to a list of list of strings (instead of a 2d array of strings). Please reload the code definition to get the latest changes.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
		int n = 0, i = 0, sz;
		if (org.empty() or seqs.empty()) {
			return false;
		}
		for (const auto & i : seqs) {
			for (const auto & j : i) {
				if (j <= 0) {
					return false;
				}
				n = max(n, j);
			}
		}
		if (org.size() != n) {
			return false;
		}
		vector<int> A(n, 0);
		vector<unordered_set<int>> B(n);
		for (const auto & seq : seqs) {
			for (sz = seq.size(), i = 0; i + 1 < sz; ++i) {
				if (!B[seq[i] - 1].count(seq[i + 1] - 1)) {
					++A[seq[i + 1] - 1];
					B[seq[i] - 1].insert(seq[i + 1] - 1);
				}
			}
		}
		vector<int> C, D, result;
		for (i = 0; i < n; ++i) {
			if (A[i] == 0) {
				C.push_back(i);
				result.push_back(i + 1);
				A[i] = -1;
			}
		}
		if (C.size() != 1) {
			return false;
		}
		while (!C.empty()) {
			if (C.size() != 1) {
				return false;
			}
			D.clear();
			for (const auto & i : B[C[0]]) {
				--A[i];
				if (A[i] == 0) {
					D.push_back(i);
					result.push_back(i + 1);
				}
			}
			C = D;
		}
		return result == org;
	}
};

int main(void) {
	Solution solution;
	vector<int> org;
	vector<vector<int>> seqs;
	bool result;
	
	org = {1, 2, 3};
	seqs = {{1, 2}, {1, 3}};
	result = solution.sequenceReconstruction(org, seqs);
	cout << boolalpha << result << '\n';

	org = {1, 2, 3};
	seqs = {{1, 2}};
	result = solution.sequenceReconstruction(org, seqs);
	cout << boolalpha << result << '\n';

	org = {1, 2, 3};
	seqs = {{1, 2}, {1, 3}, {2, 3}};
	result = solution.sequenceReconstruction(org, seqs);
	cout << boolalpha << result << '\n';

	org = {4, 1, 5, 2, 6, 3};
	seqs = {{5, 2, 6, 3}, {4, 1, 5, 2}};
	result = solution.sequenceReconstruction(org, seqs);
	cout << boolalpha << result << '\n';

	org = {1};
	seqs = {{1, -9}, {-9, -8}, {-8, -9}};
	result = solution.sequenceReconstruction(org, seqs);
	cout << boolalpha << result << '\n';

	return 0;
}