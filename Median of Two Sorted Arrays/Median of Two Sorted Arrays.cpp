/**
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

**/

class Solution 
{
public:
    double fms(int A[], int m, int B[], int n, int k)
    {
        if (m > n) 
        {
            return fms(B, n, A, m, k);
        }
        if (m == 0)
        {
            return B[k - 1];
        }
        if (k == 1)
        {
            return min(A[0], B[0]);
        }

        int pa = min(k / 2, m);
        int pb = k - pa;

        // cut the smaller array
        if (A[pa - 1] <= B[pb - 1])
        {
            return fms(A + pa, m - pa, B, n, k - pa);
        }
        return fms(A, m, B + pb, n - pb, k - pb);
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {
        int total = m + n;
        // m + n is odd
        if (total % 2 == 1)
        {
            return fms(A, m, B, n, total / 2 + 1);
        }
        else // m + n is even
        {
            return (fms(A, m, B, n, total / 2) + fms(A, m, B, n, total / 2 + 1)) / 2;
        }
    }
};