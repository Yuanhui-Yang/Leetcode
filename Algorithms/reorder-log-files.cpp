937. Reorder Log Files
https://leetcode.com/problems/reorder-log-files/

You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 

Note:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.

struct Comp
{
    bool operator() (const string & a, const string & b)
    {
        int sz1 = a.size(), sz2 = b.size(), i = 0, j = 0;
        while (i < sz1 and a[i] != ' ')
        {
            ++i;
        }
        ++i;
        while (j < sz2 and b[j] != ' ')
        {
            ++j;
        }
        ++j;
        string key1 = a.substr(i, sz1 - i), key2 = b.substr(j, sz2 - j);
        return key1 < key2;
    }
};

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> result, digits;
        for (const auto & log : logs)
        {
            if (isletter(log))
            {
                result.push_back(log);
            }
            else
            {
                digits.push_back(log);
            }
        }
        sort(result.begin(), result.end(), Comp());
        result.insert(result.end(), digits.begin(), digits.end());
        return result;
    }
private:
    bool isletter(const string & log)
    {
        int sz = log.size(), i = 0;
        while (i < sz and log[i] != ' ')
        {
            ++i;
        }
        ++i;
        return isalpha(log[i]);
    }
};