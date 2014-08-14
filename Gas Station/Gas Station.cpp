/**
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

Analysis:
The key to this problem is "Don't make it too complex!"

Yes, after trying loop(which works but with high complexity), recursion, and DP, I failed at first. After reading the problem carefully, I forget the condition "unlimited gas tank"! Actually given this condition, this problem can be solved in one loop.

The idea is: consider the case that, if started at station i, and when goes to the station j, there is not enough gas to go the j+1 station. What happened now? For the brutal force method, we go back to the sataion i+1 and do the same thing. But, actually, if the accumutive gas cannot make it from j to j+1, then the stations from i to j are all not the start station. That is because, (1)the tank is unlimited, every time arrive to the station, the tank will fuel the max gas here, and comsume the cost to go to the next. (2)There can not be negative tank when arriving a station, at least the tank is empty. So, if i to j cannot go to j+1, then i+1 to j still cannot go to j+1... In this way, the next starting station we will try is not i+1, but the j+1. And after a single loop from i to j, we can find the result!

**/

class Solution 
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
    {
        int n = gas.size();
        if (n == 0)
            return -1;
        int i = 0; 
        int j = 0;
        int tank = 0;
        while (true)
        {
            if (j >= n)
                return i;
            int net;
            if (i + j >= n) // it is circle
                net = gas[i + j - n] - cost[i + j - n];
            else
                net = gas[i + j] - cost[i + j];
            if (tank + net < 0)
            {
                j++;
                i = i + j;
                if (i >= n)
                    return -1;
                tank = 0;
                j = 0;
            }
            else
            {
                tank+=net;
                j++;
            }
        }
    }
};