/**
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

Analysis:
This is a relative easy problem.
The goal is to rearrange the array, where 0s are in the 1st part of the array, 1s in the middle, and 2s are in the    last. So, we can just scan the whole array, when meet 0, put it in the front, when meet 2, put it in the last, and leave 1 alone thus in the middle. 0 and 2's positions are stored and modified each time a swap is performed.
Details see the code.

**/

class Solution 
{
public:
    void swap(int A[], int a, int b)
    {
        int tmp = A[a];
        A[a] = A[b];
        A[b] = tmp;
    }

    void sortColors(int A[], int n) 
    {
        int red = 0;
        int blue = n - 1;

        while (A[red] == 0) {red++;}
        while (A[blue] == 2) {blue--;}

        int i = red;
        while (i <= blue)
        {
            if (A[i] == 0 && i > red)
            {
                swap(A, i, red);
                red++;
                continue;
            }
            if (A[i] == 2)
            {
                swap(A, i, blue);
                blue--;
                continue;
            }
            i++;
        }
    }
};
