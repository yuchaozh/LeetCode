/**
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

**/

class Solution 
{
public:
    void rotate(vector<vector<int> > &matrix) 
    {
        int n = matrix.size();
        // the condition layer < (n / 2) is important
        for (int layer = 0; layer < (n / 2); layer++)
        {
          int first = layer;
          int last = n - 1 - layer;
          for (int i = first; i < last; i++)
          {
            // i: traverse one layer
            int offset = i - first;
            int top = matrix[first][i];
            //left->top
            matrix[first][i] = matrix[last - offset][first];
            //bottom->left
            matrix[last - offset][first] = matrix[last][last - offset];
            //right->bottom
            matrix[last][last - offset] = matrix[i][last];
            //top->right
            matrix[i][last] = top;
          }
        }
    }
};