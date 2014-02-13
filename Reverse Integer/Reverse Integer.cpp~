/**
Author: Yuchao Zhou

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.
Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
**/

#include <string>
#include <iostream>
#include <stdlib.h> //exit(0);
#include <cstdlib>

using namespace std;

class Solution {
public:
    int reverse(int x) 
    {
    	int reversed = 0;
        while ((x/10) != 0)
        {
        	//x % 10: combine with the negtive. -123 % 10 = -3
        	reversed = reversed + (x % 10);
        	reversed = 10 * reversed;
        	x = x / 10;
        }
        reversed = reversed + x;
        return reversed;
    }
};

int main(int argc, char* argv[])
{
	if (argc != 2)
	{	
		cout<<"Please input one numbers."<<endl;
		exit(0);
	}
	//turn string into int. the format of argv is string.
	int number = atoi(argv[1]);
	int outcome = 0;
	Solution sol;
	outcome = sol.reverse(number);
	cout<<outcome<<endl;
	return 0;
}
	
