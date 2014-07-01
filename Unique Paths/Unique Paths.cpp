/**
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Analysis:
This is an easy problem. From the description we know that, the robot can only move down or right, which means, if the robot is now in position (x,y), then the position before this step must be  either (x-1,y) or (x, y-1). Since current position is only from these two previous positions, the number of possible paths that the robot can reach this current position (x,y) is the sum of paths from (x-1, y) and (x, y-1).

We want to get the number of paths on position (m,n), we need to know (m-1,n) and (m, n-1). For (m-1,n), we must know (m-2,n) and (m-1,n-1) ...  until we back to the start position (1,1) ([0][0] in  C++). Note that the boundary of the map, we can easily know that the top row and the first column of the map are all 1s. Use loop can solve the problem then.

start 1 1  1  1  1  1 
  1   2 3  4  5  6  7
  1   3 6 10 15 21 28

**/

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        int **arr = new int* [m];
        for (int i = 0; i < m; i++)
        {
            arr[i] =  new int[n];
        }

        //arr[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            arr[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            arr[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
            }
        }
        return arr[m-1][n-1];
    }
};