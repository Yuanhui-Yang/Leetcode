887. Super Egg Drop
https://leetcode.com/problems/super-egg-drop/

You are given K eggs, and you have access to a building with N floors from 1 to N. 

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 

Your goal is to know with certainty what the value of F is.

What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

 

Example 1:

Input: K = 1, N = 2
Output: 2
Explanation: 
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.
Example 2:

Input: K = 2, N = 6
Output: 3
Example 3:

Input: K = 3, N = 14
Output: 4
 

Note:

1 <= K <= 100
1 <= N <= 10000

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int sz = pre.size();
        if (sz == 0) {
            return NULL;
        }
        reverse(post.begin(), post.end());
        return f1(pre, 0, sz, post, 0, sz);
    }
private:
    TreeNode * f1(vector<int>& pre, int a1, int b1, vector<int>& post, int a2, int b2) {
        if (a1 >= b1) {
            return NULL;
        }
        TreeNode * root = new TreeNode(pre[a1]);
        ++a1;
        ++a2;
        if (a1 >= b1) {
            return root;
        }
        int left = pre[a1];
        int right = post[a2];
        if (left == right) {
            root->left = f1(pre, a1, b1, post, a2, b2);
            return root;
        }
        int c1 = a1;
        int c2 = a2;
        while (c1 < b1 and pre[c1] != right) {
            ++c1;
        }
        while (c2 < b2 and post[c2] != left) {
            ++c2;
        }
        root->left = f1(pre, a1, c1, post, c2, b2);
        root->right = f1(pre, c1, b1, post, a2, c2);
        return root;
    }
};

int main(void) {
    Solution solution;

    return 0;
}