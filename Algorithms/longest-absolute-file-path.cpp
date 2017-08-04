// 388. Longest Absolute File Path
// https://leetcode.com/problems/longest-absolute-file-path/

/*
Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
	subdir1
	subdir2
		file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
	subdir1
		file1.ext
		subsubdir1
	subdir2
		subsubdir2
			file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
*/

class Solution {
public:
	int lengthLongestPath(string input) {
		int M = input.size(), N = f(input), result = 0;
		vector<int> A(N + 1);
		for (int i = 0; i < M; ++i) {
			int index = 0;
			while (i < M and input[i] == '\t') {
				++i;
				++index;
			}
			int j = i;
			bool flag = false;
			while (i < M and input[i] != '\n') {
				if (input[i] == '.') {
					flag = true;
				}
				++i;
			}
			if (index == 0) {
				A[0] = i - j;
			}
			else {
				A[index] = A[index - 1] + i - j;
			}
			if (flag) {
				result = max(result, index + A[index]);
			}
		}
		return result;
	}
private:
	int f(const string & s) {
		int result = 0;
		for (int sz = s.size(), i = 0; i < sz; ++i) {
			if (s[i] != '\t') {
				int t = 1;
				while (i + 1 < sz and s[i + 1] == '\t') {
					++t;
					++i;
				}
				result = max(result, t);
			}
		}
		return result;
	}
};

class Solution {
public:
	int lengthLongestPath(string input) {
		int M = input.size(), N = f(input), result = 0;
		vector<int> A(N + 1);
		for (int i = 0; i < M; ++i) {
			int index = 0;
			while (i < M and input[i] == '\t') {
				++i;
				++index;
			}
			int j = i;
			bool flag = false;
			while (i < M and input[i] != '\n') {
				if (input[i] == '.') {
					flag = true;
				}
				++i;
			}
			A[index] = i - j;
			if (flag) {
				int t = index;
				for (int k = 0; k <= index; ++k) {
				   t += A[k]; 
				}
				result = max(result, t);
			}
		}
		return result;
	}
private:
	int f(const string & s) {
		int result = 0;
		for (int sz = s.size(), i = 0; i < sz; ++i) {
			if (s[i] != '\t') {
				int t = 1;
				while (i + 1 < sz and s[i + 1] == '\t') {
					++t;
					++i;
				}
				result = max(result, t);
			}
		}
		return result;
	}
};

class Solution {
public:
	int lengthLongestPath(string input) {
		int result = 0, M = input.size(), N = f(input);
		vector<stack<string>> A(N + 1);
		for (int i = 0; i < M; ++i) {
			int index = 0;
			while (i < M and input[i] == '\t') {
				++index;
				++i;
			}
			int j = i;
			bool flag = false;
			while (i < M and input[i] != '\n') {
				if (input[i] == '.') {
					flag = true;
				}
				++i;
			}
			string s = input.substr(j, i - j);
			A[index].push(s);
			if (flag) {
				int t = index;
				for (int k = 0; k <= index; ++k) {
					t += A[k].top().size();
				}
				result = max(result, t);
			}
		}
		return result;
	}
private:
	int f(const string & s) {
		int result = 0;
		for (int sz = s.size(), i = 0; i < sz; ++i) {
			if (s[i] != '\t') {
				continue;
			}
			int t = 0;
			while (i < sz and s[i] == '\t') {
				++i;
				++t;
			}
			if (result < t) {
				result = t;
			}
		}
		return result;
	}
};