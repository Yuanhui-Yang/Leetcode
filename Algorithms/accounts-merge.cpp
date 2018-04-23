721. Accounts Merge
https://leetcode.com/problems/accounts-merge/

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

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        f1(accounts);
        f2(accounts);
        return f3(accounts);
    }
private:
    unordered_map<string, string> A, B;
    void f1(vector<vector<string>>& accounts) {
        for (auto & account : accounts) {
            string & name = account[0];
            for (int sz = account.size(), i = 1; i < sz; ++i) {
                string & email = account[i];
                A[email] = email;
                B[email] = name;
            }
        }
    }
    void f2(vector<vector<string>>& accounts) {
        for (auto & account : accounts) {
            string & a = account[1];
            for (int sz = account.size(), i = 2; i < sz; ++i) {
                string & b = account[i];
                unoin(b, a);
            }
        }
    }
    vector<vector<string>> f3(vector<vector<string>>& accounts) {
        vector<vector<string>> result;
        unordered_map<string, unordered_set<string>> C;
        for (auto & account : accounts) {
            for (int sz = account.size(), i = 1; i < sz; ++i) {
                string & email = account[i];
                C[find(email)].insert(email);
            }
        }
        for (auto & i : C) {
            vector<string> D;
            D.push_back(B[i.first]);
            for (auto & j : i.second) {
                D.push_back(j);
            }
            sort(D.begin(), D.end());
            result.push_back(D);
        }
        return result;
    }
    string find(string & node) {
        return node == A[node] ? node : A[node] = find(A[node]);
    }
    void unoin(string & a, string & b) {
        string x = find(a), y = find(b);
        if (x == y) {
            return;
        }
        A[x] = y;
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

    return 0;
}
