/**
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

Analysis:
Just a little bit changes from the previous problem.
Note that if the start position is obstacle, then return 0.
Pretty easy if you solve the previous one.

**/

class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
    {
      int row = obstacleGrid.size();
      int col = obstacleGrid[0].size();

      vector<vector<int> > arr(row, vector<int>(col, 0));

      if (obstacleGrid[0][0] == 1) {return 0;}
      arr[0][0] = 1;
      for (int i = 1; i < row; i++)
      {
        if (obstacleGrid[i][0] != 1)
        {
          arr[i][0] = arr[i - 1][0];
        }
      }
      for (int i = 1; i < col; i++)
      {
        if (obstacleGrid[0][i] != 1)
        {
          arr[0][i] = arr[0][i - 1];
        }
      }
      for (int i = 1; i < row; i++)
      {
        for (int j = 1; j < col; j++)
        {
          if (obstacleGrid[i][j] != 1)
          {
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
          }
        }
      }
      return arr[row - 1][col - 1];
    }
};