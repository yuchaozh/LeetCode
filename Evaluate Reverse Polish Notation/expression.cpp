/**
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  
Analysis:

This is a classical algorithm question. The polish notation is the similar to the postorder traversal of the binary tree, and can be efficiently solved using the data structure-----stack.

The concept is:
When meeting the number, push into the stack.
When meeting the operator, pop the top 2 number and compute the value, then push the result back into the stack.
Until the end of the expression.
Output the top (last) value in the stack.

Details can be seen in the code below, there is some points need to be careful with, e.g. the order the the two numbers for the operator.

**/

#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>  

using namespace std;

// if I just use if instead else if, I need to use continue
// else is used for the last if. so we will enter into the else
// if I use else if, then there is no error
class Solution 
{
public:
    int evalRPN(vector<string> &tokens) 
    {
        stack<int> expression;
        if (tokens.size() < 1) 
        {	
        	return 0;
        }
        for (int i = 0; i < tokens.size(); i++)
        {
        	string current = tokens[i];
        	if (current == "+")
        	{
        		int a = expression.top();
        		expression.pop();
        		int b = expression.top();
        		expression.pop();
        		expression.push(b + a);
        		//continue;
        	}
        	else if (current == "-")
        	{
        		int a = expression.top();
        		expression.pop();
        		int b = expression.top();
        		expression.pop();
        		expression.push(b - a);
        		//continue;
        	}
        	else if (current == "*")
        	{
        		int a = expression.top();
        		expression.pop();
        		int b = expression.top();
        		expression.pop();
        		expression.push(b * a);
        		//continue;
        	}
        	else if (current == "/")
        	{
        		int a = expression.top();
        		expression.pop();
        		int b = expression.top();
        		expression.pop();
        		expression.push(b / a);
        		//continue;
        	}
        	else
        	{
        		// expression is int class, so we need to use atoi to change string into int
        		// c_str() 
        		expression.push(atoi(current.c_str()));
        	}
        }
        return expression.top();
    }
};

int main()
{
	Solution sol;
	vector<string> exp;
	exp.push_back("10");
	exp.push_back("6");
	exp.push_back("9");
	exp.push_back("3");
	exp.push_back("+");
	exp.push_back("-11");
	exp.push_back("*");
	exp.push_back("/");
	exp.push_back("*");
	exp.push_back("17");
	exp.push_back("+");
	exp.push_back("5");
	exp.push_back("*");
	int result = sol.evalRPN(exp);
	cout<<result<<endl;
	return 0;
}
