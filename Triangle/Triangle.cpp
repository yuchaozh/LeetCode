/**
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Analysis:
This problem is more likely to be a (dynamic programming) DP problem,
where a[n][i] = a[n][i]+min(a[n-1][i], a[n-1][i-1]).
Note that in this problem, "adjacent" of a[i][j] means a[i-1][j] and a[i-1][j-1], if available(not out of bound), while a[i-1][j+1] is not "adjacent" element.

The minimum of the last line after computing is the final result.

**/

// from top to botton
class Solution 
{
public:
  int minimumTotal(vector<vector<int> > &triangle) 
  {
    int n = triangle.size();
    if (n == 0) 
      return 0;
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < triangle[i].size(); j++)
      {
        if (j == 0) // the left edge
          triangle[i][j] += triangle[i - 1][j];
        if (j > 0)
        {
          if (i > j) // middle, i level has j elements, i + 1 level has j + 1 elements
            triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
          else // the right edge
            triangle[i][j] += triangle[i - 1][j - 1];
        }
      }
    }
    sort(triangle[n - 1].begin(), triangle[n - 1].end());
    return triangle[n - 1][0];
  }
};



// from botton to top.
class Solution 
{
public:
  int minimumTotal(vector<vector<int> > &triangle) 
  {
    for (int i = triangle.size() - 2; i >= 0; i--)
    {
      for (int j = 0; j < i + 1; j++)
      {
        triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
      }
    }
    return triangle[0][0];
  }
};