/**
Author: Yuchao Zhou

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
n=3: (2,0) + (1,1) + (0,2)
n=4: (3,0) + (2,1) + (1,2) + (0,3)
n=5: (4,0) + (3,1) + (2,2) + (1,3) + (0, 4) 

**/

// recursive
class Solution 
{
public:
    int numTrees(int n) 
    {
    	// when n == 0, result = 1
        if (n==0){return 1;}
        if (n==1){return 1;}
        int sum=0;
        for (int i=1;i<=n;i++){
            sum += numTrees(i-1)*numTrees(n-i);
        }
        return sum;
    }
};



















