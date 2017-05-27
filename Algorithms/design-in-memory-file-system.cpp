// 588. Design In-Memory File System
// https://leetcode.com/problems/design-in-memory-file-system/

/*
Design an in-memory file system to simulate the following functions:

ls: Given a path in string format. If it is a file path, return a list that only contains this file's name. If it is a directory path, return the list of file and directory names in this directory. Your output (file and directory names together) should in lexicographic order.

mkdir: Given a directory path that does not exist, you should make a new directory according to the path. If the middle directories in the path don't exist either, you should create them as well. This function has void return type.

addContentToFile: Given a file path and file content in string format. If the file doesn't exist, you need to create that file containing given content. If the file already exists, you need to append given content to original content. This function has void return type.

readContentFromFile: Given a file path, return its content in string format.

Example:
Input: 
["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
[[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
Output:
[null,[],null,null,["a"],"hello"]
Explanation:
filesystem
Note:
You can assume all file or directory paths are absolute paths which begin with / and do not end with / except that the path is just "/".
You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory or file that does not exist.
You can assume that all directory names and file names only contain lower-case letters, and same names won't exist in the same directory.
*/

#include <bits/stdc++.h>
using namespace std;

class FileSystem {
public:
	FileSystem() {
		root = new FsNode("/");
	}

	vector<string> ls(string path) {
		vector<string> dirs = parse(path);
		FsNode *it = root;
		for (const auto &i : dirs) {
			if (it->children.empty() or !it->children.count(i)) {
				return {};
			}
			it = it->children[i];
		}
		if (!it->isDir) {
			return {it->name};
		}
		vector<string> result;
		for (const auto &i : it->children) {
			result.push_back(i.first);
		}
		sort(begin(result), end(result));
		return result;
	}

	void mkdir(string path) {
		vector<string> dirs = parse(path);
		FsNode *it = root;
		for (const auto &i : dirs) {
			if (it->children.empty() or !it->children.count(i)) {
				it->children[i] = new FsNode(i);
			}
			it = it->children[i];
		}
	}

	void addContentToFile(string filePath, string content) {
		vector<string> dirs = parse(filePath);
		FsNode *it = root;
		for (size_t i = 0, n = dirs.size(); i < n; i++) {
			string dir = dirs[i];
			if (it->children.empty() or !it->children.count(dir)) {
				if (i + 1 < n) {
					return;
				}
				it->children[dir] = new FsNode(dir);
				it = it->children[dir];
				continue;
			}
			if (i + 1 < n and !it->children[dir]->isDir) {
				return ;
			}
			it = it->children[dir];
		}
		it->content.append(content);
		it->isDir = false;
	}

	string readContentFromFile(string filePath) {
		vector<string> dirs = parse(filePath);
		FsNode *it = root;
		for (size_t i = 0, n = dirs.size(); i < n; i++) {
			string dir = dirs[i];
			if (it->children.empty() or !it->children.count(dir)) {
				return "";
			}
			if (i + 1 < n and !it->children[dir]->isDir) {
				return "";
			}
			it = it->children[dir];
		}
		if (it->isDir) {
			return "";
		}
		return it->content;
	}
private:
	struct FsNode {
		string name;
		bool isDir;
		string content;
		unordered_map<string, FsNode*> children;
		FsNode(string str): name(str), isDir(true) {}
	};

	FsNode *root;

	vector<string> parse(string path) {
		vector<string> result;
		for (size_t i = 0, n = path.size(); i < n; i++) {
			if (!isalnum(path[i])) {
				continue;
			}
			size_t j = i;
			while (i < n and path[i] != '/') {
				i++;
			}
			result.push_back(path.substr(j, i - j));
		}
		return result;
	}
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */

 int main(void) {
	vector<string> v, w;
	string s, t;

	FileSystem fs;
	fs.mkdir("/goowmfn");
	v = fs.ls("/goowmfn");
	assert(v.empty());
	v = fs.ls("/");
	w = {"goowmfn"};
	assert(w == v);
	fs.mkdir("/z");
	v = fs.ls("/");
	w = {"goowmfn", "z"};
	assert(w == v);
	v = fs.ls("/");
	w = {"goowmfn", "z"};
	assert(w == v);
	fs.addContentToFile("/goowmfn/c", "shetopcy");
	v = fs.ls("/z");
	assert(v.empty());
	v = fs.ls("/goowmfn/c");
	w = {"c"};
	assert(w == v);
	v = fs.ls("/goowmfn");
	w = {"c"};
	assert(w == v);

	fs = FileSystem();
	v = fs.ls("/");
	assert(v.empty());
	fs.mkdir("/a/b/c");
	fs.addContentToFile("/a/b/c/d", "hello");
	v = fs.ls("/");
	w = {"a"};
	assert(w == v);
	s = fs.readContentFromFile("/a/b/c/d");
	t = "hello";
	assert(t == s);

 	cout << "\nPassed All\n";
 	return 0;
 }
