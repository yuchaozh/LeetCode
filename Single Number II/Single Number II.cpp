/**
Author: Yuchao Zhou
Date: 24/02/2014 

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

**/

/**
The most stupid way is using map to count the number of numbers
**/
#include <iostream>
#include <map>

using namespace std;
/**
class Solution 
{
public:
    int singleNumber(int A[], int n) 
    {
        map<int, int> mapping;
        for (int i = 0; i < n; i++)
        	mapping[A[i]]++;
        map<int, int>::iterator iter;
        for (iter = mapping.begin(); iter != mapping.end(); iter++)
        {
        	if(iter->second == 1)
        		return iter->first;
        }
    }
};
**/

/**
class Solution 
{
public:
    int singleNumber(int A[], int n) 
    {
    	for (int k = 0; k < 16; k++)
    	{
    		cout<<A[k]<<"   ";
    	}
    	cout<<endl;
    	int bit_cursor, bit, i, result;
		for (bit_cursor = 0; bit_cursor < 32; bit_cursor++)
		{
			for (i = bit = 0; i < n; i++)
			{
				bit = (bit + ((A[i] >> bit_cursor) & 1)) % 3;
			}
			result |= (bit << bit_cursor);
		}
		return result;
    }
};
**/

class Solution {  
public:  
    int singleNumber(int A[], int n) {     
        int numBins[32]={0};  
        int res=0;  
        for(int i=0;i<32;i++)  
        {  
        	cout<<endl;
        	cout<<i<<":  "<<endl;
            for(int j=0;j<n;j++)  
            {  
            	// extract the ith bit and & with 1
                if(((A[j]>>i)&1)==1)  
                    numBins[i]++;  
            }  
            res|=(numBins[i]%3)<<i;  
        }  
        return res;  
    }  
}; 


int main()
{
	int a[16] = {1,2,3,4,5,6,6,5,5,6,4,3,4,3,1,1};
	Solution sol;
	int result;
	result = sol.singleNumber(a, 16);
	cout<<result<<endl;
	return 0;
}

























