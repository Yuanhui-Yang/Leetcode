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

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Node{
	bool isFile = false;
	string fileName, content;
	unordered_map<string, Node*> next;
	Node() {
		isFile = false;
		next.clear();
	}
};

class FileSystem {
public:
	FileSystem() {
		root = new Node();
	}
	
	vector<string> ls(string path) {
		vector<string> A = f(path), result;
		Node * node = root;
		for (const auto & i : A) {
			node = node->next[i];
		}
		if (node->isFile) {
			result.push_back(node->fileName);
		}
		else {
			for (const auto & i : node->next) {
				result.push_back(i.first);
			}
			sort(begin(result), end(result));   
		}
		return result;
	}
	
	void mkdir(string path) {
		vector<string> A = f(path);
		Node * node = root;
		for (const auto & i : A) {
			if (!node->next[i]) {
				node->next[i] = new Node();
			}
			node = node->next[i];
		}
		node->isFile = false;
	}
	
	void addContentToFile(string filePath, string content) {
		vector<string> A = f(filePath);
		Node * node = root;
		for (const auto & i : A) {
			if (!node->next[i]) {
				node->next[i] = new Node();
			}
			node = node->next[i];
		}
		node->isFile = true;
		node->fileName = A.back();
		node->content.append(content);
	}
	
	string readContentFromFile(string filePath) {
		vector<string> A = f(filePath);
		Node * node = root;
		for (const auto & i : A) {
			node = node->next[i];
		}
		return node->content;
	}
private:
	Node * root = NULL;
	vector<string> f(const string & path) {
		int sz = path.size(), i = 0, j = 1;
		vector<string> result;
		while (j < sz) {
			i = j;
			while (j < sz and path[j] != '/') {
				++j;
			}
			result.push_back(path.substr(i, j - i));
			++j;
		}
		return result;
	}
};


int main(void) {
	FileSystem obj;
	vector<string> result;
	
	result = obj.ls("/");
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	obj.mkdir("/a/b/c");
	obj.addContentToFile("/a/b/c/d", "hello");
	result = obj.ls("/");
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	cout << obj.readContentFromFile("/a/b/c/d") << '\n';
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */