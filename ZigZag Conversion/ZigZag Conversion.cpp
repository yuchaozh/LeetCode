/**
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

Analysis:
The idea is straightforward. Use a 2-D vector storing the zigzag sequence, for every element in the string, put it into proper position. Then output.
There are two major steps to put element into its position:
    (1).  Write # of nRows chars into the same column. like " | "
    (2).  Write # of nRows-2 chars into different column and rows in reverse diagonal order.   like " / ".

e.g.
Input: PAYPALISHIRING

2D vector:
0  1  2 3 4  5 6  7
-------------------
0 | P         I         N
1 | A     L S     I  G
2 | Y  A   H  R
3 | P         I


**/

class Solution 
{
public:
  string convert(string s, int nRows) 
  {
    vector<string> zz(nRows, "");
    // if row is 1, then just return
    if (nRows == 1) {return s;}

    int i = 0; // for string
    int r = 0; // for zz vector
    bool zig = false; // if s[i] is in "|" direction : false
                      // if in "/" direction: true

    while (i < s.size())
    {
      if (r < nRows && !zig)
      {
        zz[r]+=s[i];
        r++;
        i++;
      }
      else // at the boundary 
      {
        if (!zig)
        {
          zig = true;
          r--;
        }
        else
        {
          r--;
          zz[r] = zz[r] + s[i];
          if (r == 0)
          {
            zig = false;
            r++;
          }
          i++;
        }
      }
    }
    string res;
    for (int i = 0; i < zz.size(); i++)
    {
      for (int j = 0; j < zz[i].size(); j++)
      {
        res = res + zz[i][j];
      }
    }
    return res;
  }
};