/**
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

Analysis:

The problem is to search if the "target" value exists in the 2D matrix. And the 2D matrix is of the ordering properties.

Consider the easier version 1D matrix, how to search a value in a sorted matrix? Yes! Divide and conquer!
Every time choose the middle element and compare, then go to the next subset of matrix until find or not find.

Here is the 2D matrix, we can easily compute the location of a specific element of ith order, problem solved!

Note, the divide and conquer(dichotomy search) is very basic and classic algorithm. It's very very useful and important.

**/

class Solution 
{
public:

    bool se(int st, int ed, int row, int col, int target, vector<vector<int> > &matrix)
    {
        if (ed < st) {return false;}
        int mid = st + (ed - st) / 2;

        //返回小于或者等于指定表达式的最大整数
        int r = floor(mid / col);
        int c = mid % col;

        if (target == matrix[r][c]) {return true;}
        if (target > matrix[r][c])
        {
            return se(mid + 1, ed, row, col, target, matrix);
        }
        else
        {
            return se(st, mid - 1, row, col, target, matrix);
        }
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target) 
    {
        int row = matrix.size();
        if (row == 0) {return false;}
        int col = matrix[0].size();
        if (col == 0) {return true;}
        int tol = row * col;
        return se(0, tol - 1, row, col, target, matrix);
    }
};
