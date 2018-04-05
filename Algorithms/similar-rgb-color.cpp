800. Similar RGB Color
https://leetcode.com/problems/similar-rgb-color/

In the following, every capital letter represents some hexadecimal digit from 0 to f.

The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.  For example, "#15c" is shorthand for the color "#1155cc".

Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.

Given the color "#ABCDEF", return a 7 character color that is most similar to #ABCDEF, and has a shorthand (that is, it can be represented as some "#XYZ"

Example 1:
Input: color = "#09f166"
Output: "#11ee66"
Explanation:  
The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.
Note:

color is a string of length 7.
color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from 0 to f
Any answer which has the same (highest) similarity as the best answer will be accepted.
All inputs and outputs should use lowercase letters, and the output is 7 characters.

#include <iostream>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    string similarRGB(string color) {
        string result;
        int similarity = INT_MIN;
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
                for (int k = 0; k < 16; ++k) {
                    int value = f1(i, j, k, color);
                    if (similarity < value) {
                        similarity = value;
                        result = f2(i, j, k);
                    }
                }
            }
        }
        return result;
    }
private:
    string s = "0123456789abcdef";
    int f1(int i, int j, int k, string & color) {
        i *= 17;
        j *= 17;
        k *= 17;
        int a = f3(color[1]) * 16 + f3(color[2]);
        int b = f3(color[3]) * 16 + f3(color[4]);
        int c = f3(color[5]) * 16 + f3(color[6]);
        int result = pow(i - a, 2) + pow(j - b, 2) + pow(k - c, 2);
        return -result;
    }
    string f2(int i, int j, int k) {
        string result;
        result.push_back('#');
        result.push_back(s[i]);
        result.push_back(s[i]);
        result.push_back(s[j]);
        result.push_back(s[j]);
        result.push_back(s[k]);
        result.push_back(s[k]);
        return result;
    }
    int f3(char ch) {
        return ch <= '9' ? ch - '0' : (ch - 'a') + 10;
    }
};

int main(void) {
    Solution solution;
    string color, result;
    
    color = "#09f166";
    result = solution.similarRGB(color);
    cout << result << '\n';
    
    return 0;
}
