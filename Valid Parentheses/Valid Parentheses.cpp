/**
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Analysis:
Idea is not complex.
Use a stack to store the chars, scan from the 1st to the last char in string s.
( [ { are free to push in the stack.
When meets ) if stack top is (, then pop (.
When meets ] if stack top is [, then pop [.
When meets } if stack top is {, then pop {.
Otherwise return false

In the end, if the stack is empty, return true. (to handle "()(" case )

**/

class Solution 
{
public:
    bool isValid(string s) 
    {
      stack<char> st;
      for (int i = 0; i < s.size(); i++)
      {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
          st.push(s[i]);
        else
        {
          //no "(", "{", "[" is impossible, so return false
          if (st.empty()) {return false;} // spcial case: only "]"
          if ((s[i] == ')') && (st.top() != '('))
            return false;
          if ((s[i] == ']') && (st.top() != '['))
            return false;
          if ((s[i] == '}') && (st.top() != '{'))
            return false;
          st.pop();
        }
      }
      return st.empty(); // spcial case: only "()]"
    }
};