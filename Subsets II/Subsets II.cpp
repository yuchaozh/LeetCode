/**
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

Analysis:
Be careful with the question, for [1,2,2], [2,2] is needed.
Here we use another way different from the previous problem to solve this problem.

First, consider there is no duplicates, how to generate the subsets?
Say n is the # of the elements,
when n=1, subsets :  {}, {"1"},  "i" means the ith element.
when n=2, subsets:   {}, {"1"}, {"2"}, {"1", "2"}
when n=3, subsets:   {}, {"1"}, {"2"}, {"1", "2"}, {"3"}, {"1","3"}, {"2","3"}, {"1", "2","3"}
So, the way of generating subsets is:
From 2 to n, COPY the previous subsets, add the current element, push back to the subsets list.

Then we take the duplicates into account, the same example:
when n=1, subsets :  {}, {"1"},  "i" means the ith element.
when n=2, subsets:   {}, {"1"}, {"2"}, {"1", "2"}
when n=3, but "2"=="3" subsets: 
   {}, {"1"}, {"2"}, {"1", "2"}, {"3"}, {"1","3"}, {"2","3"}, {"1", "2","3"}
since "2"=="3", which truly is:
   {}, {"1"}, {"2"}, {"1", "2"}, {"2"}, {"1","2"}, {"2","2"}, {"1", "2","2"}
where the bold ones are not needed.
So, how these two subsets are generated? They are from the subsets of n=1.

In sum up, when meet the same element as previous one, then generate new subsets ONLY from the subsets generated from previous iteration, other than the whole subsets list.

**/

class Solution 
{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) 
    {
        sort(S.begin(), S.end());
        vector<vector<int> > res;
        vector<int> r;
        res.push_back(r); // empty subset;
        r.push_back(S[0]); 
        res.push_back(r); // the first one
        int pre = S[0];
        int count = 1;
        for (int i = 1; i < S.size(); i++)
        {
            int st = 0; 
            int sz = res.size(); // generate new subset based on previous subsets
            if (S[i] == pre) {st = sz - count;} // generate from previous iteration
            count = 0;
            for (int j = st; j < sz; j++)
            {
                r = res[j]; // get all previous subsets
                r.push_back(S[i]); // add current element
                res.push_back(r); // add new subsets
                count++;
            }
            pre = S[i];
        }
        return res;
    }
};