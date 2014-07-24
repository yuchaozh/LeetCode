/**
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Analysis:

The easiest idea is using the binary numbers.
e.g.
set [a,b,c], write the binary numbers of length 3.
000    []
001    [a]
010    [b]
011    [ab]
100    [c]
101    [ac]
110    [bc]
111    [abc]

Then the problem is pretty easy, just have to implement the int binary to string part.
Details see code.


Another approach is to use DFS, I'll post it out later.

**/

class Solution 
{
public:
    /*
    number: 0 binary: 00
    number: 1 binary: 10
    number: 2 binary: 010
    number: 3 binary: 110
    number: 4 binary: 001
    number: 5 binary: 101
    number: 6 binary: 011
    number: 7 binary: 111
    */
    string getBinary(int a, int len)
    {
      string str = "";
      while (a > 0)
      {
        str = str + char((a % 2) + '0');
        a = a / 2;
      }
      for (int i = 0; i < len - str.size(); i++)
      {
        str = str + '0';
      }
      return str;
    }

    vector<vector<int> > subsets(vector<int> &S) 
    {
        sort(S.begin(), S.end());
        vector<vector<int> > res;
        int n = S.size();
        for (int i = 0; i < pow(2, n); i++)
        {
          string str = getBinary(i, n);
          vector<int> ss;
          for (int j = 0; j < n; j++)
          {
            if (str[j] == '1')
            {
              ss.push_back(S[j]);
            }
          }
          res.push_back(ss);
        }
        return res;
    }
};