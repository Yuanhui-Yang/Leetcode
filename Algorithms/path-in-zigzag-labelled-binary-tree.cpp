1104. Path In Zigzag Labelled Binary Tree
https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

In an infinite binary tree where every node has two children, the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.



Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.

 

Example 1:

Input: label = 14
Output: [1,3,4,14]
Example 2:

Input: label = 26
Output: [1,2,6,10,26]
 

Constraints:

1 <= label <= 10^6

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        int level = floor(log2(label));
        while (level > 0)
        {
            result.push_back(label);
            if (level % 2)
            {
                label = f1(level) + (f1(level + 1) - 1) - label;
                label /= 2;
                --level;
            }
            else
            {
                label /= 2;
                --level;
                label = f1(level) + (f1(level + 1) - 1) - label;
            }
        }
        result.push_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
private:
    int f1(int level)
    {
        return 1 << level;
    }
};