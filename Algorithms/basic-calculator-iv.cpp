770. Basic Calculator IV
https://leetcode.com/problems/basic-calculator-iv/

Given an expression such as expression = "e + 8 - a + 5" and an evaluation map such as {"e": 1} (given in terms of evalvars = ["e"] and evalints = [1]), return a list of tokens representing the simplified expression, such as ["-1*a","14"]

An expression alternates chunks and symbols, with a space separating each chunk and symbol.
A chunk is either an expression in parentheses, a variable, or a non-negative integer.
A variable is a string of lowercase letters (not including digits.) Note that variables can be multiple letters, and note that variables never have a leading coefficient or unary operator like "2x" or "-x".
Expressions are evaluated in the usual order: brackets first, then multiplication, then addition and subtraction. For example, expression = "1 + 2 * 3" has an answer of ["7"].

The format of the output is as follows:

For each term of free variables with non-zero coefficient, we write the free variables within a term in sorted order lexicographically. For example, we would never write a term like "b*a*c", only "a*b*c".
Terms have degree equal to the number of free variables being multiplied, counting multiplicity. (For example, "a*a*b*c" has degree 4.) We write the largest degree terms of our answer first, breaking ties by lexicographic order ignoring the leading coefficient of the term.
The leading coefficient of the term is placed directly to the left with an asterisk separating it from the variables (if they exist.)  A leading coefficient of 1 is still printed.
An example of a well formatted answer is ["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"] 
Terms (including constant terms) with coefficient 0 are not included.  For example, an expression of "0" has an output of [].
Examples:

Input: expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
Output: ["-1*a","14"]

Input: expression = "e - 8 + temperature - pressure",
evalvars = ["e", "temperature"], evalints = [1, 12]
Output: ["-1*pressure","5"]

Input: expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
Output: ["1*e*e","-64"]

Input: expression = "7 - 7", evalvars = [], evalints = []
Output: []

Input: expression = "a * b * c + b * a * c * 4", evalvars = [], evalints = []
Output: ["5*a*b*c"]

Input: expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))",
evalvars = [], evalints = []
Output: ["-1*a*a*b*b","2*a*a*b*c","-1*a*a*c*c","1*a*b*b*b","-1*a*b*b*c","-1*a*b*c*c","1*a*c*c*c","-1*b*b*b*c","2*b*b*c*c","-1*b*c*c*c","2*a*a*b","-2*a*a*c","-2*a*b*b","2*a*c*c","1*b*b*b","-1*b*b*c","1*b*c*c","-1*c*c*c","-1*a*a","1*a*b","1*a*c","-1*b*c"]
Note:

expression will have length in range [1, 250].
evalvars, evalints will have equal lengths in range [0, 100].

class Term
{
public:
	int coefficient;
	vector<string> variables;
	Term()
	{
		this->coefficient = 0;
		this->variables.clear();
	}
	Term(int other)
	{
		this->coefficient = other;
		this->variables.clear();
	}
	Term(const Term & other)
	{
		this->coefficient = other.coefficient;
		this->variables = other.variables;
		if (!is_sorted(this->variables.begin(), this->variables.end()))
		{
			sort(this->variables.begin(), this->variables.end());
		}
	}
	Term& operator = (const Term& other)
	{
		this->coefficient = other.coefficient;
		if (this->coefficient)
		{
			this->variables = other.variables;
			if (!is_sorted(this->variables.begin(), this->variables.end()))
			{
				sort(this->variables.begin(), this->variables.end());
			}
		}
		return *this;
	}
	Term operator + (Term other)
	{
		Term result;
		if (this->variables == other.variables)
		{
			result.coefficient = this->coefficient + other.coefficient;
			result.variables = this->variables;
		}
		return result;
	}
	Term operator * (Term other)
	{
		Term result;
		result.coefficient = this->coefficient * other.coefficient;
		if (result.coefficient)
		{
			result.variables.insert(result.variables.end(), this->variables.begin(), this->variables.end());
			result.variables.insert(result.variables.end(), other.variables.begin(), other.variables.end());
			sort(result.variables.begin(), result.variables.end());
		}
		return result;
	}
	bool operator < (const Term& other) const
	{
		if (this->variables.size() == other.variables.size())
		{
			return this->variables < other.variables;
		}
		else
		{
			return this->variables.size() > other.variables.size();
		}
	}
	//bool operator == (const Term& other)
	//{
	//	return this->variables == other.variables;
	//}
	string toString()
	{
		string result;
		if (this->coefficient)
		{
			result.append(to_string(this->coefficient));
			for (auto& i : this->variables)
			{
				result.push_back('*');
				result.append(i);
			}
		}
		return result;
	}
};

class Experssion
{
public:
	vector<Term> terms;
	Experssion()
	{
		this->terms.clear();
	}
	Experssion(const Experssion & other)
	{
		this->terms = other.terms;
		sort(this->terms.begin(), this->terms.end());
	}
	Experssion(int value)
	{
		Term term;
		term.coefficient = value;
		term.variables.clear();
		this->terms.push_back(term);
	}
	Experssion(string value)
	{
		Term term;
		if (isdigit(value[0]))
		{
			term.coefficient = stoi(value);
			term.variables.clear();
		}
		else
		{
			term.coefficient = 1;
			term.variables.push_back(value);
		}
		this->terms.push_back(term);
	}
	Experssion(const Term & term)
	{
		this->terms.clear();
		this->terms.push_back(term);
	}
	Experssion & operator += (Experssion other)
	{
		return *this = *this + other;
	}
	Experssion operator + (Experssion other)
	{
		sort(this->terms.begin(), this->terms.end());
		sort(other.terms.begin(), other.terms.end());
		Experssion result;
		int sz1 = this->terms.size(), sz2 = other.terms.size(), i = 0, j = 0;
		while (i < sz1 or j < sz2)
		{
			if (i >= sz1)
			{
				if (other.terms[j].coefficient)
				{
					result.terms.push_back(other.terms[j]);
				}
				++j;
			}
			else if (j >= sz2)
			{
				if (this->terms[i].coefficient)
				{
					result.terms.push_back(this->terms[i]);
				}
				++i;
			}
			else if (this->terms[i].variables == other.terms[j].variables)
			{
				Term tmp;
				tmp.coefficient = this->terms[i].coefficient + other.terms[j].coefficient;
				tmp.variables = this->terms[i].variables;
				if (tmp.coefficient)
				{
					result.terms.push_back(tmp);
				}
				++i;
				++j;
			}
			else if (this->terms[i] < other.terms[j])
			{
				if (this->terms[i].coefficient)
				{
					result.terms.push_back(this->terms[i]);
				}
				++i;
			}
			else
			{
				if (other.terms[j].coefficient)
				{
					result.terms.push_back(other.terms[j]);
				}
				++j;
			}
		}
		return result;
	}
	Experssion operator - (Experssion other)
	{
		for (auto & i : other.terms)
		{
			i.coefficient = -i.coefficient;
		}
		return *this + other;
	}
	Experssion& operator -= (Experssion other)
	{
		return *this = *this - other;
	}
	Experssion operator * (Experssion other)
	{
		sort(this->terms.begin(), this->terms.end());
		sort(other.terms.begin(), other.terms.end());
		Experssion result;
		for (auto & i : this->terms)
		{
			for (auto & j : other.terms)
			{
				Term k = i * j;
				Experssion e(k);
				result += e;
			}
		}
		return result;
	}
	vector<string> toString()
	{
		vector<string> result;
		for (auto & i : this->terms)
		{
			string s = i.toString();
			if (!s.empty())
			{
				result.push_back(i.toString());
			}
		}
		return result;
	}
};

class Solution {
public:
	vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
		unordered_map<string, int> evalvar2evalint = f1(evalvars, evalints);
		unordered_map<char, int> operatorpriority;
		operatorpriority['+'] = 1;
		operatorpriority['-'] = 1;
		operatorpriority['*'] = 2;
		operatorpriority['/'] = 2;
		stack<char> A;
		stack<Experssion> B;
		int sz = expression.size(), i = 0;
		while (i < sz)
		{
			char ch = expression[i];
			if (ch == ' ')
			{
				++i;
			}
			else if (operatorpriority.count(ch))
			{
				while (!A.empty() and operatorpriority.count(A.top()) and operatorpriority[A.top()] >= operatorpriority[ch])
				{
					char op = A.top();
					A.pop();
					Experssion y = B.top();
					B.pop();
					Experssion x = B.top();
					B.pop();
					Experssion z = op == '+' ? x + y : op == '-' ? x - y : x * y;
					B.push(z);
				}
				A.push(ch);
				++i;
			}
			else if (ch == '(')
			{
				A.push('(');
				++i;
			}
			else if (ch == ')')
			{
				while (!A.empty() and operatorpriority.count(A.top()))
				{
					char op = A.top();
					A.pop();
					Experssion y = B.top();
					B.pop();
					Experssion x = B.top();
					B.pop();
					Experssion z = op == '+' ? x + y : op == '-' ? x - y : x * y;
					B.push(z);
				}
				A.pop();
				++i;
			}
			else
			{
				string s;
				while (i < sz and isalnum(expression[i]))
				{
					s.push_back(expression[i]);
					++i;
				}
				if (evalvar2evalint.count(s))
				{
					B.push(Experssion(evalvar2evalint[s]));
				}
				else
				{
					B.push(Experssion(s));
				}
			}
		}
		while (!A.empty())
		{
			char op = A.top();
			A.pop();
			Experssion y = B.top();
			B.pop();
			Experssion x = B.top();
			B.pop();
			Experssion z = op == '+' ? x + y : op == '-' ? x - y : x * y;
			B.push(z);
		}
		return B.top().toString();
	}
private:
	unordered_map<string, int> f1(vector<string>& evalvars, vector<int>& evalints)
	{
		unordered_map<string, int> result;
		for (int sz = evalvars.size(), i = 0; i < sz; ++i)
		{
			result[evalvars[i]] = evalints[i];
		}
		return result;
	}
};