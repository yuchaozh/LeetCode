/**
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

Analysis:
Just like the idea of previous problem (see Remove Duplicates from Sorted Array)
But add another flag store the number of duplicated elements.
Details can be seen in code.

**/

class Solution 
{
public:
    int removeDuplicates(int A[], int n) 
    {
        if (n == 0) {return 0;}
        if (n == 1) {return A[0];}
        int pre = A[0];
        int pos = 0;
        int m = n;
        int i = 1;
        int count = 0;
        while (i < m)
        {
            if (A[i] == pre)
            {
                count++;
                if (count < 2)
                {
                    i++;
                }
                else
                {
                    m = m - 1;
                    // the array will be changed, so use j < m, not j < n
                    for (int j = pos + 1; j < m; j++)
                    {
                        A[j] = A[j + 1];
                    }
                }
            }
            else
            {
                count = 0;
                pre = A[i];
                pos = i;
                i++;
            }
        }
        return m;
    }
};