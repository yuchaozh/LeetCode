/**
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

Analysis:
Having solved the previous problem. This problem seems easier than the last one.

The key idea is to consider the single step ----- "Which direction to go filling the next number?"
There are only four directions.
Be careful with one thing----- you keep going one direction until meet the end.

**/

class Solution 
{
public:
    vector<vector<int> > generateMatrix(int n) 
    {
        vector<vector<int> > res(n, vector<int>(n, 0));
        if (n == 0) {return res;}
        int i = 1;
        int x = 0; // row
        int y = 0; // col
        res[0][0] = i++;
        while (i <= n * n)
        {
            // if res[?][?] != 0 means it is the last one, needs trun right
            // y + 1 < n: not exceed the right edge
            while (y + 1 < n && res[x][y + 1] == 0) // keep going right
            {
                res[x][++y] = i++;
            }
            // x + 1 < n: not exceed the button edge
            while (x + 1 < n && res[x + 1][y] == 0) // keep going down
            {
                res[++x][y] = i++;
            }
            // y - 1 >= 0: not exceed the left edge
            while (y - 1 >= 0 && res[x][y - 1] == 0) // keep going left
            {
                res[x][--y] = i++;
            }
            // x - 1 >= 0: not exceed the top edge
            // use res[x-1][y] to check the ahead element
            while (x - 1 >= 0 && res[x - 1][y] == 0)
            {
                res[--x][y] = i++;
            }
        }
        return res;
    }
};