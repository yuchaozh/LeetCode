/**
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Analysis:
This can be solved in according to the formula to generate the kth element in nth row of Pascal's Triangle:

r(k) = r(k-1) * (n+1-k)/k,

where r(k) is the kth element of nth row. The formula just use the previous element to get the new one. The start point is 1.

Once get the formula, it is easy to generate the nth row.

But be careful !!!

If you have an int*int when the value of int*int  is out of the bound of int data type (while is signed: -2147483648 to 2147483647, unsigned: 0 to 4294967295 ), there will be an ERROR result!!!

And also NOTE that: 
If you define   "int a;  double d = a*a;", it still meets wrong value! because the * is called the operator function: "int::operator *(const &int )".

So the better way is to do type casting before the manipulation.
double d = double(a)*double(a);

**/

class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> res;
        res.push_back(1);
        int n = (rowIndex) / 2;
        for (int i = 1; i <= n; i++)
        {
            double r = double(res[i - 1]) * (double(rowIndex) + 1 - double(i)) / double(i);
            res.push_back(r);
        }
        if (rowIndex % 2 == 1)
        {
            int sz = res.size();
            for (int i = sz - 1; i >= 0; i--)
            {
                res.push_back(res[i]);
            }
        }
        else
        {
            int sz = res.size();
            for (int i = sz - 2; i >=0; i--)
            {
                res.push_back(res[i]);
            }
        }
        return res;
    }
};