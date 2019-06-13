1078. Occurrences After Bigram
https://leetcode.com/problems/occurrences-after-bigram/

Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

For each such occurrence, add "third" to the answer, and return the answer.

 

Example 1:

Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]
Example 2:

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]
 

Note:

1 <= text.length <= 1000
text consists of space separated words, where each word consists of lowercase English letters.
1 <= first.length, second.length <= 10
first and second consist of lowercase English letters.

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string target = first;
        target.push_back(' ');
        target.append(second);

        vector<string> result;
        size_t sz = text.size(), i = 0;
        while (i < sz)
        {
            i = text.find(target, i);
            if (i == string::npos)
            {
                break;
            }
            else
            {
                i += target.size();
                if (i >= sz or text[i] != ' ')
                {
                    break;
                }
                else
                {
                    size_t j = i;
                    while (j < sz and text[j] == ' ')
                    {
                        ++j;
                    }
                    string tmp;
                    while (j < sz and text[j] != ' ')
                    {
                        tmp.push_back(text[j]);
                        ++j;
                    }
                    if (!tmp.empty())
                    {
                        result.push_back(tmp);
                    }
                }
            }
        }
        return result;
    }
};