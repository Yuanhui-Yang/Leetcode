// 609. Find Duplicate File in System
// https://leetcode.com/problems/find-duplicate-file-in-system/

/*
Given a list of directory info including directory path, and all the files with contents in this directory, you need to find out all the groups of duplicate files in the file system in terms of their paths.

A group of duplicate files consists of at least two files that have exactly the same content.

A single directory info string in the input list has the following format:

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively) in directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of group of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

"directory_path/file_name.txt"

Example 1:
Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
Output:  
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
Note:
No order is required for the final output.
You may assume the directory name, file name and file content only has letters and digits, and the length of file content is in the range of [1,50].
The number of files given is in the range of [1,20000].
You may assume no files or directories share the same name in a same directory.
You may assume each given directory info represents a unique directory. Directory path and file infos are separated by a single blank space.
Follow up beyond contest:
Imagine you are given a real file system, how will you search files? DFS or BFS ?
If the file content is very large (GB level), how will you modify your solution?
If you can only read the file by 1kb each time, how will you modify your solution?
What is the time complexity of your modified solution? What is the most time consuming part and memory consuming part of it? How to optimize?
How to make sure the duplicated files you find are not false positive?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		unordered_map<string, vector<string>> h;
		for (const auto &path : paths) {
			string dir;
			for (int i = 0, n = path.size(); i < n; ++i) {
				int j = i;
				while (i < n and path[i] != ' ') {
					++i;
				}
				string s = path.substr(j, i - j);
				if (dir.empty()) {
					dir = s;
				}
				else {
					int k = 0, l = s.size();
					while (k < l and s[k] != '(') {
						++k;
					}
					string key = s.substr(k + 1, l - 2 - k);
					string value = dir + "/" + s.substr(0, k);
					h[key].push_back(value);
				}
			}
		}
		vector<vector<string>> result;
		for (const auto &i : h) {
			if (i.second.size() >= 2) {
				result.push_back(i.second);
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<string> paths;
	vector<vector<string>> answer, result;

	paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
	answer = {{"root/a/2.txt", "root/c/d/4.txt", "root/4.txt"}, {"root/a/1.txt", "root/c/3.txt"}};
	sort(begin(answer), end(answer));
	result = solution.findDuplicate(paths);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}