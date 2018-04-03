808. Soup Servings
https://leetcode.com/problems/soup-servings/

There are two types of soup: type A and type B. Initially we have N ml of each type of soup. There are four kinds of operations:

Serve 100 ml of soup A and 0 ml of soup B
Serve 75 ml of soup A and 25 ml of soup B
Serve 50 ml of soup A and 50 ml of soup B
Serve 25 ml of soup A and 75 ml of soup B
When we serve some soup, we give it to someone and we no longer have it.  Each turn, we will choose from the four operations with equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as we can.  We stop once we no longer have some quantity of both types of soup.

Note that we do not have the operation where all 100 ml's of soup B are used first.  

Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double soupServings(int N) {
        N = (N / 25) + bool(N % 25);
        if (N >= 500) {
            return 1;
        }
        A.resize(N + 1, vector<double>(N + 1, -1));
        return f1(N, N);
    }
private:
    double f1(int x, int y) {
        if (x <= 0 and y <= 0) {
            return 0.5;
        }
        if (x <= 0) {
            return 1;
        }
        if (y <= 0) {
            return 0;
        }
        double & z = A[x][y];
        if (z >= 0) {
            return z;
        }
        double result = 0;
        result += 0.25 * f1(x - 4, y);
        result += 0.25 * f1(x - 3, y - 1);
        result += 0.25 * f1(x - 2, y - 2);
        result += 0.25 * f1(x - 1, y - 3);
        return z = result;
    }
    vector<vector<double>> A;
};

int main(void) {
    Solution solution;
    int N;
    double result;
    
    N = 660295675;
    result = solution.soupServings(N);
    cout << result << '\n';
    
    return 0;
}
