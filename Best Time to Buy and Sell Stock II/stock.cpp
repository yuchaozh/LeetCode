/**
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Analysis:
Scan the vector, add all the sub set which are non-decreasing order.
e.g. 
1 2 4 2 5 7 2 4 9 0 9
(1 2 4) (2 5 7) ( 2 4 9) (0 9)  
prof = 3 + 5 + 7 + 9  = 24.

if the order goes down, then it - itself == 0. means not buy the stock
**/

// solution 1: find the biggest and smallest number in one asecending order
class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        int result = 0;
        if (prices.size() > 1)
        {
        	int cursor = prices[0];
        	// there are two cursors, begin from 1 here
        	for (int i = 1; i < prices.size(); i++)
        	{
        		if (prices[i] > prices[i - 1])
        			continue;
        		else
        		{
        			result += prices[i - 1] - curosr;
        			cursor = prices[i];
        		}
        	}
        	// deal with the last one
        	result += prices[prices.size() - 1] - cursor;
        }
        return result;
    }
};

// solution 2: add difference of all numbers within an asecending order
class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        int result = 0;
		if (prices.size() < 2)
		{
			return result; 
		}
		else
		{
			for (int i = 1; i < prices.size(); i++)
			{
				if (prices[i] > prices[i - 1])
				{
					result += prices[i] - prices[i - 1];
				}
			}
		}
		return result;
    }
};

