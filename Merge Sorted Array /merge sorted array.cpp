/**
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

Analysis:
The classic problem. (can be found in the book "Cracking the Code Interview").
Part of the merge sort, merge the arrays from the back by comparing the elements.

**/

class Solution 
{
public:
    void merge(int A[], int m, int B[], int n) 
    {
    	int a = m - 1;
    	int b = n - 1;
    	int total = m + n - 1;
    	while (a >= 0 && b >= 0)
    	{
    		A[total--] = A[a]>B[b]? A[a--]:B[b--];
    	}
    	// b has left
    	while (b >= 0)
    	{
    		A[total--] = B[b--];
    	}
    }
};
