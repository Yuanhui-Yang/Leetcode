#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int sz = chars.size(), i, j = 0, k, l, m, result = 0;
        while (j < sz) {
            i = j;
            while (j < sz and chars[i] == chars[j]) {
                ++j;
            }
            chars[result] = chars[i];
            ++result;
            k = j - i;
            if (k > 1) {
                l = f1(k);
                m = l;
                while (l > 0) {
                    --l;
                    chars[result + l] = k % 10 + '0';
                    k /= 10;
                }
                result += m;
            }
        }
        return result;
    }
private:
    int f1(int k) {
        int l = 0;
        while (k > 0) {
            ++l;
            k /= 10;
        }
        return l;
    }
};

int main(void) {
    Solution solution;
    vector<char> chars;
    int result, i;
    
    chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    result = solution.compress(chars);
    for (i = 0; i < result; ++i) {
        cout << chars[i] << '\t';
    }
    cout << '\n';

    chars = {'a'};
    result = solution.compress(chars);
    for (i = 0; i < result; ++i) {
        cout << chars[i] << '\t';
    }
    cout << '\n';

    chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    result = solution.compress(chars);
    for (i = 0; i < result; ++i) {
        cout << chars[i] << '\t';
    }
    cout << '\n';
        
    return 0;
}
