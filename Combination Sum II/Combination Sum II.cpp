/**
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 

Analysis:
The only difference between this problem and the previous one is each element can be used at most once.
We can change the recursive step to handle this.

**/

class Solution 
{
public:
    void dfs(vector<int> & num, int target, vector<vector<int> > &res, vector<int> &r, int st)
    {
        if (target < 0)
            return;
        else
        {
            if (target == 0)
            {
                res.push_back(r);
            }
            else
            {
                // use pre to check use only once
                int pre = -1;
                for (int i = st; i < num.size(); i++)
                {
                    if (num[i] != pre)
                    {
                        r.push_back(num[i]);
                        dfs(num, target - num[i], res, r, i + 1);
                        pre = num[i];
                        r.pop_back();
                    }
                }
            }
        }

    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        vector<vector<int> > res;
        // if candidate is empty, return
        if (num.size() == 0) {return res;}
        sort(num.begin(), num.end());
        vector<int> r;
        dfs(num, target, res, r, 0);
        return res;
    }
};