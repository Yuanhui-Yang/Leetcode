class Solution {
public:
    int calculate(string s) {
        stack<char> A;
        stack<int> B;
        int sz = s.size(), i = 0;
        array<int, 512> C;
        C.fill(0);
        C['+'] = 1;
        C['-'] = 1;
        C['*'] = 2;
        C['/'] = 2;
        C['^'] = 3;
        while (i < sz) {
            char ch = s[i];
            if (ch == ' ') {
                ++i;
            }
            else if (ch == '(') {
                A.push(ch);
                ++i;
            }
            else if (ch == ')') {
                while (!A.empty() and A.top() != '(') {
                    int b = B.top();
                    B.pop();
                    int a = B.top();
                    B.pop();
                    char op = A.top();
                    A.pop();
                    int c = op == '*' ? a * b : op == '/' ? a / b : op == '+' ? a + b : a - b;
                    B.push(c);
                }
                A.pop();
                ++i;
            }
            else if (isdigit(ch)) {
                int value = 0;
                while (i < sz and isdigit(s[i])) {
                    int offset = s[i] - '0';
                    value = 10 * value + offset;
                    ++i;
                }
                B.push(value);
            }
            else {
                while (!A.empty() and A.top() != '(' and C[A.top()] >= C[ch]) {
                    int b = B.top();
                    B.pop();
                    int a = B.top();
                    B.pop();
                    char op = A.top();
                    A.pop();
                    int c = op == '*' ? a * b : op == '/' ? a / b : op == '+' ? a + b : a - b;
                    B.push(c);
                }
                A.push(ch);
                ++i;
            }
        }
        while (!A.empty()) {
            int b = B.top();
            B.pop();
            int a = B.top();
            B.pop();
            char op = A.top();
            A.pop();
            int c = op == '*' ? a * b : op == '/' ? a / b : op == '+' ? a + b : a - b;
            B.push(c);   
        }
        return B.top();
    }
};
