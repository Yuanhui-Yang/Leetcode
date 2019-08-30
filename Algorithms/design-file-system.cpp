1166. Design File System
https://leetcode.com/problems/design-file-system/

You are asked to design a file system which provides two functions:

createPath(path, value): Creates a new path and associates a value to it if possible and returns True. Returns False if the path already exists or its parent path doesn't exist.
get(path): Returns the value associated with a path or returns -1 if the path doesn't exist.
The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. For example, /leetcode and /leetcode/problems are valid paths while an empty string and / are not.

Implement the two functions.

Please refer to the examples for clarifications.

 

Example 1:

Input: 
["FileSystem","createPath","get"]
[[],["/a",1],["/a"]]
Output: 
[null,true,1]
Explanation: 
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/a", 1); // return true
fileSystem.get("/a"); // return 1
Example 2:

Input: 
["FileSystem","createPath","createPath","get","createPath","get"]
[[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
Output: 
[null,true,true,2,false,-1]
Explanation: 
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/leet", 1); // return true
fileSystem.createPath("/leet/code", 2); // return true
fileSystem.get("/leet/code"); // return 2
fileSystem.createPath("/c/d", 1); // return false because the parent path "/c" doesn't exist.
fileSystem.get("/c"); // return -1 because this path doesn't exist.
 

Constraints:

The number of calls to the two functions is less than or equal to 10^4 in total.
2 <= path.length <= 100
1 <= value <= 10^9
NOTE: create method has been changed on August 29, 2019 to createPath. Please reset to default code definition to get new method signature.

struct Node
{
	int val;
	string name;
	unordered_map<string, Node*> links;
	Node()
	{
		this->val = 0;
		this->name.clear();
		this->links.clear();
	}
};

class FileSystem {
public:
	FileSystem() {
		this->root = new Node();
	}

	bool createPath(string path, int value) {
		vector<string> A = f1(path);
		Node* node = this->root;
        int sz = A.size();
		for (int i = 0; i < sz; ++i)
		{
            const string & s = A[i];
			if (node->links.count(s))
			{
                if (i + 1 == sz)
                {
                    return false;
                }
			}
            else
            {
                if (i + 1 < sz)
                {
                    return false;
                }
                else
                {
                    node->links[s] = new Node();
                    node->links[s]->name = s;
                    node->links[s]->val = value;
                }
            }
			node = node->links[s];
		}
		return true;
	}

	int get(string path) {
		vector<string> A = f1(path);
		Node* node = this->root;
		for (const auto& i : A)
		{
			if (node->links.count(i))
			{
				node = node->links[i];
			}
			else
			{
				return -1;
			}
		}
		return node->val;
	}
private:
	Node* root;
	vector<string> f1(string path)
	{
		vector<string> result;
		int sz = path.size(), i = 0;
		while (i < sz and path[i] == '/')
		{
			++i;
		}
		while (i < sz)
		{
			string s;
			while (i < sz and path[i] != '/')
			{
				s.push_back(path[i]);
				++i;
			}
			result.push_back(s);
			++i;
		}
		return result;
	}
};