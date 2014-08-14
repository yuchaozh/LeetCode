/**

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

Analysis:
Well, this is more like a math problem, and I don't know how to solve it.
From the wikipedia, one classic algorithm to generate next permutation is:
Step 1: Find the largest index k, such that A[k]<A[k+1]. If not exist, this is the last permutation. (in this    problem just sort the vector and return.)
Step 2: Find the largest index l, such that A[l]>A[k].
Step 3: Swap A[k] and A[l].
Step 4: Reverse A[k+1] to the end.

OK! Having the algorithm then coding becomes an easy thing!

**/

class Solution 
{
public:
    void nextPermutation(vector<int> &num) 
    {
        int sz = num.size();
        int largestIndex = -1;
        int l= -1;

        for (int i = 0; i < sz - 1; i++)
        {
            if (num[i] < num[i + 1])
                largestIndex = i;
        }
        if (largestIndex == -1)
        {
            sort(num.begin(), num.end());
            return;
        }

        for (int i = 0; i < sz; i++)
        {
            if (num[i] > num[largestIndex])
            {
                l = i;
            }
        }
        int tmp = num[l];
        num[l] = num[largestIndex];
        num[largestIndex] = tmp;

        reverse(num.begin() + largestIndex + 1, num.end());

    }
};