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
        int x = 0;
        int y = 0;
    }
};