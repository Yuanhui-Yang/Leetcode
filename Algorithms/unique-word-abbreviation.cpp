288. Unique Word Abbreviation
https://leetcode.com/problems/unique-word-abbreviation/

An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        A.clear();
        for (const auto & i : dictionary) {
            string abbr = f1(i);
            if (A.count(abbr)) {
                if (A[abbr] != i) {
                    A[abbr].clear();
                }
            }
            else {
                A[abbr] = i;
            }
        }
    }
    
    bool isUnique(string word) {
        string abbr = f1(word);
        return !A.count(abbr) or A[abbr] == word;
    }
private:
    unordered_map<string, string> A;
    string f1(const string & word) {
        int sz = word.size();
        if (sz <= 2) {
            return word;
        }
        return word.front() + to_string(sz - 2) + word.back();
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */

 int main(void) {
    vector<string> dictionary({"deer", "door", "cake", "card"});
    ValidWordAbbr obj(dictionary);
    bool result;
    result = obj.isUnique("dear");
    cout << boolalpha << result << '\n';
    result = obj.isUnique("cart");
    cout << boolalpha << result << '\n';
    result = obj.isUnique("cane");
    cout << boolalpha << result << '\n';
    result = obj.isUnique("make");
    cout << boolalpha << result << '\n';
    return 0;
 }