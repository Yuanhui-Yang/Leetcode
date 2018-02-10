14. Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return f1(strs, 0, strs.size());
    }
private:
    string f1(vector<string>& strs, int begin, int end) {
        if (begin == end) {
            return "";
        }
        if (begin + 1 == end) {
            return strs[begin];
        }
        int mid = begin + (end - begin) / 2;
        string a = f1(strs, begin, mid), b = f1(strs, mid, end);
        string result;
        int sz = min(a.size(), b.size()), i = 0;
        while (i < sz and a[i] == b[i]) {
            result.push_back(a[i]);
            ++i;
        }
        return result;
    }
};