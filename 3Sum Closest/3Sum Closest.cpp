/**
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

The code is slight different from the 3 sum problem, just change the if condition, the key point is to use the abs() function to get the distances between the target and the output value. 

**/

class Solution 
{
public:
    int threeSumClosest(vector<int> &num, int target) 
    {
        int res;
        vector<int>::iterator it1, it2, it3, iend;
        sort(num.begin(), num.end());

        if (num.size() >= 3)
        {
        	res = num[0] + num[1] + num[2];
        	iend = num.end();
        	it1 = num.begin();
        	bool f1 = false;
        	for ( ; it1 != iend - 2; it1++)
        	{
        		if (f1 && *it1 == *(it1 - 1)) {continue;}
        		f1 = true;
        		bool f2 = false;
        		bool f3 = false;
        		it2 = it1 + 1;
        		it3 = iend - 1;
        		while (it2 != it3)
        		{
        			if (f3 && *it3 == *(it3 + 1)) {it3--; continue;}
        			if (f2 && *it2 == *(it2 - 1)) {it2++; continue;}
        			if (*it1 + *it2 + *it3 == target)
        			{
        				return target;
        			}
        			if (*it1 + *it2 + *it3 > target)
        			{
        				// calculate the abs as the distance
        				if (abs(target - (*it1 + *it2 + *it3)) < abs(target - res))
        				{
        					res = *it1 + *it2 + *it3;
        				}
        				it3--;
        				f3 = true;
        			}
        			else
        			{
        				if (abs(target - (*it1 + *it2 + *it3)) < abs(target - res))
        				{
        					res = *it1 + *it2 + *it3;
        				}
        				it2++;
        				f2 = true;
        			}

        		}
        	}
        }
        return res;
    }
};