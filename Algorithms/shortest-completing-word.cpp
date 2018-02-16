748. Shortest Completing Word
https://leetcode.com/problems/shortest-completing-word/

Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. Such a word is said to complete the given string licensePlate

Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.

Example 1:
Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
Example 2:
Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
Output: "pest"
Explanation: There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.
Note:
licensePlate will be a string with length in range [1, 7].
licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
words will have a length in the range [10, 1000].
Every words[i] will consist of lowercase letters, and have length in range [1, 15].

#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        array<int, 26> a = f1(licensePlate);
        string result;
        for (const auto & word : words) {
            array<int, 26> b = f1(word);
            if (f2(a, b)) {
                if (result.empty() or word.size() < result.size()) {
                    result = word;
                }
            }
        }
        return result;
    }
private:
    array<int, 26> f1(const string & word) {
        array<int, 26> result;
        result.fill(0);
        for (const auto & i : word) {
            if (isalpha(i)) {
                int id = tolower(i) - 'a';
                ++result[id];   
            }
        }
        return result;
    }
    bool f2(array<int, 26> & A, array<int, 26> & B) {
        for (int i = 0; i < 26; ++i) {
            if (A[i] > B[i]) {
                return false;
            }
        }
        return true;
    }
};

int main(void) {
    Solution solution;
    string licensePlate, result;
    vector<string> words;
    
    licensePlate = "1s3 PSt";
    words = {"step", "steps", "stripe", "stepple"};
    result = solution.shortestCompletingWord(licensePlate, words);
    cout << result << '\n';

    licensePlate = "1s3 456";
    words = {"looks", "pest", "stew", "show"};
    result = solution.shortestCompletingWord(licensePlate, words);
    cout << result << '\n';
    
    return 0;
}