/**
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.

**/

class Solution 
{
public:
  int jump(int A[], int n) 
  {
    if (n == 0) {return 0;}
    // when there is only one element. the step is 0.
    if (n == 1) {return 0;}

    int m = 0; // the distance it can reach
    int i = 0;
    int njump = 0; // times of jump
    while (i < n)
    {
      // A[i] + i: steps
      m = max(m, A[i] + i);
      if (m > 0) {njump++;}
      if (m >= n - 1) {return njump;}
      int tmp = 0;
      for (int j = i + 1; j <= m; j++)
      {
        if (j + A[j] > tmp)
        {
          tmp = A[j] + j;
          i = j;
        }
      }
    }
    return njump;
  }
};