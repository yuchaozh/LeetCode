/**
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

In other word, this question ask how many time T has occurred in S, where some char can be added in between T, but the order of T cannot change.
An easy but time-consuming idea is recursion. Details can be found in the source code. However, this algorithm cannot pass the large test.
A better way is
(Updated 201308)
The idea is using dynamic programming (DP).
First we redefine the problem to another form.
e.g.  S= "aabb" T="aab" , we need to find the occurrence of T in S, so,
(1) We store the positions of each letter of T in S, in a table:
     a [0, 1]
     a [0, 1]
     b [2, 3]
(2) The problem then can be viewed as "find how many paths from top to the bottom with an ascending order".  In other words, from the table above, for "a" we have only one choice 0,  the other "a" we have only one choice 1, and for b we can choose 2 or 3, thus the result is 2.

How to get the path number? you can use dfs, but it might be time consuming.
Here, we use DP, define res[i][j] the number of path can have for table[i][j]
res[i][j] = sum(res[i-1][k]), where table[i-1][k]<table[i][j].
The final result is the sum(res[last row]).

**/

// only pass small test
class Solution 
{
public:
    int cond(string S, string T)
    {
        // S = "";
        if (S.size() == 0)
            return 0;
        // T = "";
        if (S.size() == 0)
            return 1;
        if (S.size() == 1 && T.size() == 1)
        {
            // S == T
            if (S[0] == T[0])
                return 1;
            else
                return 0;
        }
        if (S[0] == T[0])
            return cond(S.substr(1), T.substr(1)) + cond(S.substr(1), T);
        else
            return cond(S.substr(1), T);

    }

    int numDistinct(string S, string T) 
    {
        if (S.empty() || T.empty())
            return 0;
        return cond(S, T);
    }
};

//
class Solution
{
public:
    void cond(vector<vector<int> > &table, int &res)
    {
        int row = table.size();
        vector<vector<int> > r(row);
        for (int i = 0; i < table[0].size(); i++)
        {
            r[0].push_back(1);
        }
        for (int i = 1; i < table.size(); i++)
        {
            int tmp = 0;
            int bf = 0;
            for (int j = 0; j < table[i].size(); j++)
            {
                for (int k = bf; k < table[i - 1].size(); k++)
                {
                    if (table[i][j] > table[i - 1][k])
                    {
                        tmp = tmp + r[i - 1][k];
                        bf = k + 1;
                    }
                    else
                    {
                        break;
                    }
                    r[i].push_back(tmp);
                }
            }
        }
        for (int i = 0; i < table[row - 1].size(); i++)
        {
            res = res + r[row - 1][i];
        }
    }

    int numDistinct(string S, string T)
    {
        if (S.empty() || T.empty())
            return 0;
        int res = 0;
        vector<vector<int> > table(T.size());
        map<char, vector<int> > mp;
        vector<int> r;

        // store the positions of each letter of T in S
        // initiate the map with empty vector for each element
        for (int i = 0; i < T.size(); i++)
        {
            mp[T[i]] = r;
        }
        // fill the map with S
        for (int i = 0; i < S.size(); i++)
        {
            mp[S[i]].push_back(i);
        }
        // filter, only store T's position in S
        for (int i = 0; i < T.size(); i++)
        {
            table[i] = mp[T[i]];
        }
        cond(table, res);
        return res;
    };
}