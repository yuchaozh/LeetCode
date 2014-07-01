/**
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

The idea of this classic problem is to use backtracking.
We want to get permutations, which is mainly about swap values in the list.
Consider:
a --> a
ab --> ab, ba
abc --> abc, acb, bac, bca, cab, cba.
...
where for the length of n, the permutations can be generated by
(1) Swap the 1st element with all the elements, including itself.
       (2) Then the 1st element is fixed, go to the next element.
       (3) Until the last element is fixed. Output.
It's more clear in the figure above. The key point is to make the big problem into smaller problem, here is how to convert the length n permutation into length n-1 permutation problem.


**/

class Solution 
{
public:
    void perm(vector<int> num, int k, int n, vector<vector<int> > &res)
    {
        if (k == n)
        {
            res.push_back(num);
        }
        else
        {
            for (int i = k; i <= n; i++)
            {
                int tmp = num[k];
                num[k] = num[i];
                num[i] = tmp;

                perm(num, k + 1, n, res);

                tmp = num[k];
                num[k] = num[i];
                num[i] = tmp;
            }
        }
    }

    vector<vector<int> > permute(vector<int> &num) 
    {
        vector<vector<int> > res;
        perm(num, 0, (num.size() - 1), res);
        return res;
    }
};