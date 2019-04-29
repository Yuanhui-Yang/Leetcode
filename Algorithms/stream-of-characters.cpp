1032. Stream of Characters
https://leetcode.com/problems/stream-of-characters/

Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
 

Note:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.

struct Node
{
    array<Node *, 26> children;
    bool isEnd;
    Node()
    {
        this->children.fill(NULL);
        this->isEnd = false;
    }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        this->root = new Node();
        for (auto & word : words)
        {
            reverse(word.begin(), word.end());
            f1(this->root, word);
        }
        this->str.clear();
    }
    
    bool query(char letter) {
        this->str.push_back(letter);
        return f2(this->root, this->str);
    }
private:
    Node * root;
    string str;
    void f1(Node * root, string & word)
    {
        for (const auto & ch : word)
        {
            int id = ch - 'a';
            if (!root->children[id])
            {
                root->children[id] = new Node();
            }
            root = root->children[id];
        }
        root->isEnd = true;
    }
    bool f2(Node * root, string & word)
    {
        for (int sz = word.size(), i = sz - 1; i >= 0; --i)
        {
            char ch = word[i];
            int id = ch - 'a';
            root = root->children[id];
            if (!root)
            {
                return false;
            }
            if (root->isEnd)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */