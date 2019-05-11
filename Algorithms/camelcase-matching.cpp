1023. Camelcase Matching
https://leetcode.com/problems/camelcase-matching/

A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.

 

Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
Example 2:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: 
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
Example 3:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: 
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
 

Note:

1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
All strings consists only of lower and upper case English letters.

struct Node
{
    int index;
    array<Node *, 256> next;
    Node()
    {
        this->index = -1;
        this->next.fill(NULL);
    }
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Node * root = new Node();
        f1(root, queries);
        vector<bool> result(queries.size(), false);
        f3(root, 0, pattern, result);
        return result;
    }
private:
    void f1(Node * root, vector<string>& queries)
    {
        int sz = queries.size();
        for (int i = 0; i < sz; ++i)
        {
            f2(root, i, queries);
        }
    }
    void f2(Node * root, int index, vector<string>& queries)
    {
        string & word = queries[index];
        for (auto & ch : word)
        {
            int id = ch;
            if (!root->next[id])
            {
                root->next[id] = new Node();
            }
            root = root->next[id];
        }
        root->index = index;
    }
    void f3(Node * root, size_t index, string & pattern, vector<bool> & result)
    {
        if (!root)
        {
            return;
        }
        if (index < pattern.size())
        {
            for (int i = 0; i < 256; ++i)
            {
                if (root->next[i])
                {
                    char ch = i;
                    if (ch == pattern[index])
                    {
                        f3(root->next[i], index + 1, pattern, result);
                    }
                    else if (islower(ch))
                    {
                        f3(root->next[i], index, pattern, result);
                    }
                }
            }
        }
        else
        {
            if (root->index >= 0)
            {
                result[root->index] = true;
            }
            for (int i = 0; i < 256; ++i)
            {
                if (root->next[i])
                {
                    char ch = i;
                    if (islower(ch))
                    {
                        f3(root->next[i], index + 1, pattern, result);
                    }
                }
            }
        }
    }
};