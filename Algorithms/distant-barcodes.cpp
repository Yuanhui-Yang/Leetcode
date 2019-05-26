1054. Distant Barcodes
https://leetcode.com/problems/distant-barcodes/

In a warehouse, there is a row of barcodes, where the i-th barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal.  You may return any answer, and it is guaranteed an answer exists.

 

Example 1:

Input: [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,2,1,2,1]
 

Note:

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> A;
        for (auto & i : barcodes)
        {
            ++A[i];
        }
        priority_queue<array<int, 2>> max_heap;
        for (auto & i : A)
        {
            max_heap.push({i.second, i.first});
        }
        vector<int> result;
        while (!max_heap.empty())
        {
            queue<array<int, 2>> q;
            while (!max_heap.empty() and !result.empty() and max_heap.top()[1] == result.back())
            {
                array<int, 2> top = max_heap.top();
                max_heap.pop();
                q.push(top);
            }
            if (!max_heap.empty())
            {
                array<int, 2> top = max_heap.top();
                max_heap.pop();
                result.push_back(top[1]);
                --top[0];
                if (top[0] > 0)
                {
                    q.push(top);
                }
            }
            while (!q.empty())
            {
                max_heap.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};