/**
Author: Yuchao Zhou
Date: 24/02/2014 

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

trick: XOR is a good way, we can use the property that A XOR A = 0, and A XOR B XOR A = B.
**/

#include <iostream>
#include <stdlib.h> //exit(0);

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n)
    {
    	int result = A[0];
    	//array start at 1.
    	for (int i = 1; i < n; i++)
    	{
    		result = result ^ A[i];
    	}
    	return result;
    }
};

int main(int argc, char* argv[])
{
	int input[11];
	cout<<"please input 11 number"<<endl;
	for (int i = 0; i < 11; i++)
	{
		cin>>input[i];
	}
	cout<<endl;	
	Solution sol;
	int result = sol.singleNumber(input, 11);
	cout<<result<<endl;
	return 0;
}
	
