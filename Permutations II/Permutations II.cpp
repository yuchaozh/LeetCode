/**
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

Analysis:
Facing this kind of problem, just consider this is a similar one to the previous(see here), but need some modifications. In this problem, what we need it to cut some of the subtrees.  e.g. 122
                     122
         /             |           \
     122          212         X  (here because 2=2, we don't need to swap again)
    /     \          /    \
 122   X     212 221 

So, if there exist same element after current swap, there there is no need to swap again.
Details see code.

**/

class Solution 
{
public:
    bool noswap(int k, int i, const vector<int> num)
    {
        for (int j = k; j < i; j++)
        {
            if (num[j] == num[i])
                return true;
        }
        return false;
    }

    void perm(vector<int> num, int k, int n, vector<vector<int> > &res)
    {
        if (k == n)
            res.push_back(num);
        else
        {
            for (int i = k; i <= n; i++)
            {
                if (noswap(k, i, num))
                    continue;
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

    vector<vector<int> > permuteUnique(vector<int> &num) 
    {
        vector<vector<int> > res;
        perm(num, 0, (num.size() - 1), res);
        return res;
    }
};