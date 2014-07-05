/**
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Analysis:
Similar to the previous question (see here).
Just when A[mid]==A[st], we cannot say the previous part is ordered, then we just go to the next element and check again.

**/

class Solution 
{
public:
    bool search(int A[], int n, int target) 
    {
        
    }
};