/**
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

Analysis:
One way to solve the problem (can only pass the small test) is to generate from the 1st permutation to the required one (similar to the problem Next permutation.). However, when n=9, the last permutation is the 362880th one, which is too time consuming.

A better way is to fully use the properties of permutation: the total number of permutation with length n is n!.
First, let's take a look at how permutation works:

Major steps are swap and fix:
Here in order to grow the tree,  every time start the first unfixed element in each node, generate child nodes by swapping the first element with every other element.The leave nodes are those do not have element to swap. 

So, when we have the idea of how to generate the permutation, next step is to generate it faster. Think the tree in this way:

                         ABC
         /                   |                    \
     ABC             BAC              CBA
    /       \             /      \               /    \
ABC  ACB     BAC BCA    CBA CAB

Every leave node is a permutation. Take a look at the second level, each subtree (second level nodes as the root), there are (n-1)! permutations in it.  Totally there are n nodes in 2nd level, thus the total number of permutations are n*(n-1)!=n!.

So, what we want to do is to locate one permutation among the leave nodes. The simple method is to generate and search each leave node until we find the one. Now, what we can do here we want to skip some trees to reduce the complexity. e.g. in the above tree, if we know the required leave node is in the third sub tree (under CBA), we can skip the first two and search from the "CBA".

Say we have the required permutation is the kth one, first we can locate which subtree it belongs to in the 2nd level, by computing s = k / ((n-1)!). Then we get the sth subtree, and set k=k%((n-1)!) , now search the sub tree until we get the leave node. How to get the sth subtree root node? Just like the idea of how permutation works (the first figure): Just put the sth elment after fixed letter.  e.g. ABCD,  we want the 3rd subtree root node in 2nd level, just put C in the 1st place, which is CABD;   For ABCDE, we want the 3rd subtree root node in the 3rd level, it is ADBCE.

**/

class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
        int nf[9] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string res;

        // initialization, if n = 4, return 1234
        for (int i = 1; i <= n; i++)
        {
            res += char(i + '0');
        }
        k--;
        for (int i = 0; i < n; i++)
        {
            
        }

    }
};