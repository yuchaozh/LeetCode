/**

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

Analysis:

The trick is given array is already sorted, which means the duplicated elements are all together. e.g.(1,1,2,2,3,4,5,5,5,6,7,7,8,9)

From the 1st element, store current element value(from A[0]), if the current element == stored value, put all the elements one step back. e.g. A[i]=A[i+1]; then change the length of the array.

**/

class Solution 
{
public:
    int removeDuplicates(int A[], int n) 
    {
        if (n < 2) {return n;}
        
        // exceed limit time (forward scan)
        /**
        int pre = A[0];
        int i = 1;
        int length = n;
        while (i < n)
        {
        	if (pre == A[i])
        	{
        		// eliminate the duplicated one and move other ahead
        		for (int j = i; j < n; j++)
        		{
        			A[j] = A[j + 1];
        		}
        		length--;
        	}
        	else
        	{
        		pre = A[i];
        		i++;
        	}
        }
        return length;
    }
    **/
    
    //backward scan
    int i = n - 2;
    int pre = A[n - 1];
    int length = n;
    while (i >= 0)
    {
    	if (pre == A[i])
    	{
    		for (int j = i; j < length; j++)
    		{
    			A[j] = A[j + 1];
    		}
    		length--;
    		i--;
    	}
    	else
    	{
    		pre = A[i];
    		i--;
    	}
    }
    return length;
    
};
