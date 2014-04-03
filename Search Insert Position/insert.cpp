/**

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0 

**/

/**
*	O(n) search
**/
class Solution 
{
public:
    int searchInsert(int A[], int n, int target) 
    {
    	// only has one element in the array
    	if (n == 1)
        {
        	if (target <= A[0])
        		return 0;
        	else
        		return 1;
        }
        else
        {
        	for (int i = 0; i < n; i++)
        	{
        		if (A[i] >= target)
        		{
        			if ( i == 0)
        				return 0;
        			else
        				return i;
        		}
        		else
        		{
        			if (i == (n - 1))
        				return n;
        		}
        	}
        }
    }
};

/**
*	O(log n) search
**/
class Solution 
{
public:
		
	

    int searchInsert(int A[], int n, int target) 
    {
    	
    }
};
	
