1231. Divide Chocolate
https://leetcode.com/problems/divide-chocolate/

You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.

You want to share the chocolate with your K friends so you start cutting the chocolate bar into K+1 pieces using K cuts, each piece consists of some consecutive chunks.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

 

Example 1:

Input: sweetness = [1,2,3,4,5,6,7,8,9], K = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]
Example 2:

Input: sweetness = [5,6,7,8,9,1,2,3,4], K = 8
Output: 1
Explanation: There is only one way to cut the bar into 9 pieces.
Example 3:

Input: sweetness = [1,2,2,1,2,2,1,2,2], K = 2
Output: 5
Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]
 

Constraints:

0 <= K < sweetness.length <= 10^4
1 <= sweetness[i] <= 10^5

// BEGIN: Time Limit Exceeded
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int sz = sweetness.size();
        vector<vector<int>> A(K + 1, vector<int>(sz + 1, 0));
        vector<int> B(sz + 1);
        A[0][0] = 0;
        B[0] = 0;
        for (int j = 1; j <= sz; ++j)
        {
            int val = sweetness[j - 1];
            A[0][j] = A[0][j - 1] + val;
            B[j] = B[j - 1] + val;
        }
        for (int i = 1; i <= K; ++i)
        {
            A[i][i + 1] = min(A[i - 1][i], sweetness[i]);
        }
        for (int i = 1; i <= K; ++i)
        {
            for (int j = i + 2; j <= sz; ++j)
            {
                int& val = A[i][j];
                for (int k = i; k < j; ++k)
                {
                    int tmp = min(A[i - 1][k], B[j] - B[k]);
                    val = max(val, tmp);
                }
            }
        }
        return A[K][sz];
    }
};
// END: Time Limit Exceeded

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int i = 0;
        int j = accumulate(sweetness.begin(), sweetness.end(), 0);
        ++j;
        while (i < j)
        {
            int k = (i + j) >> 1;
            if (f1(sweetness, K, k))
            {
                i = k + 1;
            }
            else
            {
                j = k;
            }
        }
        return --i;
    }
private:
    bool f1(vector<int>& sweetness, int K, int windowSum)
    {
        ++K;
        int sz = sweetness.size(), i = 0;
        while (i < sz and K > 0)
        {
            int sum = 0;
            while (i < sz and sum < windowSum)
            {
                sum += sweetness[i];
                ++i;
            }
            if (sum >= windowSum)
            {
                --K;
            }
        }
        return K == 0;
    }
};