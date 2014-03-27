/**
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Analysis:
The idea is very simple: buy the stock at a lower price and sell it at a higher price in the future.
The easiest way is try to sell the stock from the 2nd day to the last day, and get the highest profit. For each sell day, get the lowest price before and compute the profit. The algorithm contains two loop, one from the second day to the last, and one from the first day to the current sell day. The complexity is O(n^2).

A better way. How to reduce the complexity ? Similar idea as above but pre-compute the minimum value for each day, which means for each day, compute and store the minimum price of the previous days. In this step the complexity is O(n). Then scan all the days to get the max profit,  total complexity is still O(n).

**/

// maybe this is correct. but it exceeded the time
/**
class Solution 
{
public:
	int maxProfit(vector<int> &prices) 
    {
    	int result = 0;
    	int final = 0;
    	if (prices.size() < 2)
    		return 0;
    	else
    	{
    		for (int i = 0; i < prices.size(); i++)
    		{
    			for (int j = i + 1; j < prices.size(); j++)
    			{
    				result = prices[i] - prices[j];
    				if (final < result)
    					final = result;
    			}
    		}
    	}
    	return final;
    }
};
**/
#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	int maxProfit(vector<int> prices) 
    {
    	int result = 0;
    	if (prices.size() > 1)
    	{
			vector<int> previous_min;
			int previous = prices[0];
			for (int i = 0; i < prices.size(); i++)
			{
				if (previous >= prices[i])
				{
					previous = prices[i];
				}
				previous_min.push_back(previous);
			}
			for (int i = 0; i < prices.size(); i++)
			{
				int diff = prices[i] - previous_min[i];
				if (result <= diff)
					result = diff;
			} 
		}
    	return result;
    }
};

int main()
{
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	Solution sol;
	int output = 0;
	output = sol.maxProfit(input);
	cout<<output<<endl;
	return 0;
}
    
    
    
    
