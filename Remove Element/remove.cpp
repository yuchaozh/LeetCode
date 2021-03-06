/**

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Analysis:
Idea is to use double pointer (i and j ), i goes from 1st to the last element in the array, think i scan all the array, and j stores the final result. e.g.
A = 1 2 3 4 5 3 6 7;
i j are set to start position.
i goes from 1 to 7, if this element is not the element requested,A[j]=A[i] (no change at start because i and j are same.), then i ++, j++, otherwise, i++, means to skip this element,but j stays, from next element, continue the above step, when set A[j]=A[i], which means A[j] was originally stored the removed element but now stores the next one.
A = 1 2 3 4 5 3 6 7,  elem=3
       i   i  i
       j   j  j

then
A = 1 2 3 4 5 3 6 7
       i  i      i
       j  j  j

and A = 1 2 4 4 5 3 6 7
                          i
                      j
finally, A= 1 2 4 5 6 7
**/

class Solution 
{
public:
    int removeElement(int A[], int n, int elem) 
    {
    	// this is wrong
        //int i = j = 0;
        int i = 0;
        int j = 0;
        while (i < n)
        {
        	if (A[i] != elem)
        	{	
        		A[j] = A[i];
        		j++;
        	}
        	i++;
        }
        return j;
    }
};
