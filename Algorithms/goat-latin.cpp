824. Goat Latin
https://leetcode.com/problems/goat-latin/

A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> A = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string result;
        int sz = S.size(), i = 0, j = 0, k = 2;
        while (j < sz) {
            i = j;
            while (j < sz and S[j] != ' ') {
                ++j;
            }
            string t = S.substr(i, j - i);
            if (!A.count(t.front())) {
                t.push_back(t.front());
                t.erase(t.begin());
            }
            t.push_back('m');
            t.append(string(k, 'a'));
            if (result.empty()) {
                result.append(t);
            }
            else {
                result.push_back(' ');
                result.append(t);
            }
            ++j;
            ++k;
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string S, result;

    S = "I speak Goat Latin";
    result = solution.toGoatLatin(S);
    cout << result << '\n';

    S = "The quick brown fox jumped over the lazy dog";
    result = solution.toGoatLatin(S);
    cout << result << '\n';

    return 0;
}
