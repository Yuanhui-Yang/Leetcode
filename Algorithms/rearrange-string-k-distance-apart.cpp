// 358. Rearrange String k Distance Apart
// https://leetcode.com/problems/rearrange-string-k-distance-apart/

/*
Given a non-empty string s and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
s = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
Example 2:
s = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.
Example 3:
s = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.
*/

class Solution {
public:
	string rearrangeString(string s, int k) {
		if (k <= 0) {
			return s;
		}
		array<int, 26> A;
		A.fill(0);
		for (const auto & i : s) {
			int id = i - 'a';
			++A[id];
		}
		priority_queue<array<int, 2>> pq;
		for (int i = 0; i < 26; ++i) {
			if (A[i] > 0) {
				pq.push({A[i], i});
			}
		}
		string result;
		while (!pq.empty() and pq.top()[0] > 1) {
			queue<array<int, 2>> next;
			int i = 0;
			while (i < k and !pq.empty()) {
				array<int, 2> top = pq.top();
				pq.pop();
				result.push_back(top[1] + 'a');
				--top[0];
				if (top[0] > 0) {
					next.push(top);
				}
				++i;
			}
			if (i < k) {
				return "";
			}
			while (!next.empty()) {
				array<int, 2> front = next.front();
				next.pop();
				if (front[0] > 0) {
					pq.push(front);
				}
			}
		}
		while (!pq.empty()) {
			array<int, 2> top = pq.top();
			result.push_back(top[1] + 'a');
			pq.pop();
		}
		return result;
	}
};