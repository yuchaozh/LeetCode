/**

 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.
More practice:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Analysis:
Classic DP problem.

We can think this problem as this: if the previous sum are +, which is then useful for the current element, or if it is -, why not start the sub array from current element? We can use an int to store the max sum we have got, just scan the whole array, the result is easily found.

**/

class Solution 
{
public:
    int maxSubArray(int A[], int n) 
    {
    	// initiate m as the min value of int
        int m = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
        	sum = sum >= 0 ? (sum + A[i]) : A[i];
        	m = max (sum, m);
        }
        return m;
    }
};
