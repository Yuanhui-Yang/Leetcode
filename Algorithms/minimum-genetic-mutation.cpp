// 433. Minimum Genetic Mutation
// https://leetcode.com/problems/minimum-genetic-mutation/

/*
A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

Note:

Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.
Example 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1
Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2
Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3
*/

class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		if (start == end) {
			return 0;
		}
		if (bank.empty()) {
			return -1;
		}
		unordered_map<string, unordered_set<string>> A;
		for (int sz = bank.size(), i = 0; i + 1 < sz; ++i) {
			for (int j = i + 1; j < sz; ++j) {
				if (f(bank[i], bank[j])) {
					A[bank[i]].insert(bank[j]);
					A[bank[j]].insert(bank[i]);
				}
			}
		}
		for (int sz = bank.size(), i = 0; i < sz; ++i) {
			if (f(start, bank[i])) {
				A[start].insert(bank[i]);
				A[bank[i]].insert(start);
			}
		}
		unordered_set<string> B;
		int result = -1;
		B.insert(start);
		list<string> curr;
		curr.push_back(start);
		while(!curr.empty()) {
			list<string> next;
			++result;
			for (const auto & i : curr) {
				if (i == end) {
					return result;
				}
				if (A.count(i)) {
					for (const auto & j : A[i]) {
						if (!B.count(j)) {
							B.insert(j);
							next.push_back(j);
						}
					}
				}
			}
			curr = next;
		}
		return -1;
	}
private:
	bool f(const string & s, const string & t) {
		if (s.size() != t.size()) {
			return false;
		}
		int sz = s.size(), result = 0;
		for (int i = 0; i < sz; ++i) {
			if (s[i] != t[i]) {
				++result;
			}
		}
		return result == 1;
	}
};