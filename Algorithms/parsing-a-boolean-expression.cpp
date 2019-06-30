1106. Parsing A Boolean Expression
https://leetcode.com/problems/parsing-a-boolean-expression/

Return the result of evaluating a given boolean expression, represented as a string.

An expression can either be:

"t", evaluating to True;
"f", evaluating to False;
"!(expr)", evaluating to the logical NOT of the inner expression expr;
"&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner expressions expr1, expr2, ...;
"|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner expressions expr1, expr2, ...
 

Example 1:

Input: expression = "!(f)"
Output: true
Example 2:

Input: expression = "|(f,t)"
Output: true
Example 3:

Input: expression = "&(t,f)"
Output: false
Example 4:

Input: expression = "|(&(t,f,t),!(t))"
Output: false
 

Constraints:

1 <= expression.length <= 20000
expression[i] consists of characters in {'(', ')', '&', '|', '!', 't', 'f', ','}.
expression is a valid expression representing a boolean, as given in the description.

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> A;
        string B;
        int sz = expression.size(), i = 0;
        while (i < sz)
        {
            char ch = expression[i];
            if (ch == ' ')
            {
                ++i;
            }
            else if (ch == ',')
            {
                ++i;
            }
            else if (ch == '(')
            {
                ++i;
                B.push_back('(');
            }
            else if (ch == ')')
            {
                ++i;
                char op = A.top();
                A.pop();
                if (op == '!')
                {
                    char top = B.back();
                    B.pop_back();
                    B.pop_back();
                    top = top == 't' ? 'f' : 't';
                    B.push_back(top);
                }
                else
                {
                    while (B.size() >= 3 and B[B.size() - 2] != '(')
                    {
                        char y = B.back();
                        B.pop_back();
                        char x = B.back();
                        B.pop_back();
                        char z = op == '&' ? ((x == 't' and y == 't') ? 't' : 'f') : ((x == 't' or y == 't') ? 't' : 'f');
                        B.push_back(z);
                    }
                    char top = B.back();
                    B.pop_back();
                    B.pop_back();
                    B.push_back(top);
                }
            }
            else if (isalpha(ch))
            {
                ++i;
                B.push_back(ch);
            }
            else
            {
                ++i;
                A.push(ch);
            }
        }
        return B.back() == 't';
    }
};