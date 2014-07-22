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
	bool se(int st, int ed, int target, int A[])
	{
		if (st > ed) {return false;}
		else
		{
			int mid = st + (ed - st) / 2;
			if (A[mid] == target) {return true;}
			if (A[mid] > A[st])
			{
				if (target <= A[mid] && target >= A[st])
				{
					return se(st, mid - 1, target, A);
				}
				else
				{
					return se(mid + 1, ed, target, A);
				}
			}
			if (A[mid] < A[st])
			{
				if (target <= A[mid] || target >= A[st])
				{
					return se(st, mid - 1, target, A);
				}
				else
				{
					return se(mid + 1, ed, target, A);
				}
			}
			if (A[mid] == A[st])
			{
				return se(st + 1, ed, target, A);
			}
			return false;
		}
	}
    bool search(int A[], int n, int target) 
    {
        if (n == 0) {return false;}
        return se(0, n - 1, target, A);
    }
};