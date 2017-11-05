// 721. Accounts Merge
// https://leetcode.com/problems/accounts-merge/

/*
Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Note:

The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].
*/

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		int sz = accounts.size(), sz1, n = 0, i, j, root1, root2;
		unordered_map<string, int> A;
		vector<int> B;
		vector<string> C, D;
		for (i = 0; i < sz; ++i) {
			sz1 = accounts[i].size();
			for (j = 1; j < sz1; ++j) {
				if (!A.count(accounts[i][j])) {
					A[accounts[i][j]] = n;
					B.push_back(n);
					C.push_back(accounts[i][0]);
					++n;
				}
			}
		}
		vector<set<string>> E(n);
		vector<vector<string>> result;
		for (i = 0; i < sz; ++i) {
			sz1 = accounts[i].size();
			root1 = f1(A[accounts[i][1]], B);
			for (j = 2; j < sz1; ++j) {
				root2 = f1(A[accounts[i][j]], B);
				if (root1 != root2) {
					B[root2] = root1;
				}
			}
		}
		for (i = 0; i < sz; ++i) {
			sz1 = accounts[i].size();
			for (j = 1; j < sz1; ++j) {
				root1 = f1(A[accounts[i][j]], B);
				E[root1].insert(accounts[i][j]);
			}
		}
		for (i = 0; i < n; ++i) {
			if (!E[i].empty()) {
				D.clear();
				D.push_back(C[i]);
				D.insert(end(D), begin(E[i]), end(E[i]));
				result.push_back(D);
			}
		}
		return result;
	}
private:
	int f1(int node, vector<int> & B) {
		return node == B[node] ? node : B[node] = f1(B[node], B);
	}
};

int main(void) {
	Solution solution;
	vector<vector<string>> accounts, result;
	
	accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
	result = solution.accountsMerge(accounts);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}

	accounts = {{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"}, {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"}, {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"}, {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"}, {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}};
	result = solution.accountsMerge(accounts);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	
	return 0;
}