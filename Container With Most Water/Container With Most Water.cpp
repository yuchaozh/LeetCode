/**
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

Analysis:
An easy but time-consuming way to solve this problem is of O(n^2), compare the area for each pair of points. However, it cannot pass the large test.
There is a greedy way to solve this problem in O(n). Use two pointers, one from the start and one from the end of the height vector. Compute the current area, move the smaller pointer to its direction, until two pointers meet.

**/

// class Solution 
// {
// public:
//     int maxArea(vector<int> &height) 
//     {
//         int maxa = 0;
//         if (height.size() < 2) {return maxa;}
//         for (int i = 1; i < height.size(); i++)
//         {
//             for (int j = 0; j < i; j++)
//             {
//                 int ar = abs(i - j) * min(height[i], height[j]);
//                 if (ar > maxa) {maxa = ar;}
//             }
//         }
//         return maxa;
//     }
// };

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxa = 0;
        if (height.size() < 2) {return maxa;}
        int l = 0;
        int r = height.size() - 1;

        while (l < r)
        {
            int ar = abs(l - r) * min(height[l], height[r]);
            if (ar > maxa) {maxa = ar;}
            if (height[l] <= height[r]) 
            {
                l = l + 1;
            }
            else
            {
                r = r - 1;
            }
        }
        return maxa;
    }
};