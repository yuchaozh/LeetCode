/**
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

Analysis:
The question requires no extra space, so we cannot convert the number to string and check the end and front. But the idea is still check the top and last digit. The last digit is easily achieved by x%10(x mod 10).
To get the next last digit, x=x/10; x%10;  On the other hand, how to get first digit? Similarly, keep x = x/10,  until x<10.  So, if we can get the first digit and the last digit, then we compare, if not equal return false, if equal we search the next two digits. Recursion seems a good idea to solve the problem. 2 same number as the parameter is set to get the first and last digit respectively. So we first recursively get the first digit, then compare to the last digit, if ok, what we is only deal with the 2nd number in order to get the next last digit (by x=x/10). Because the recursion property, when this level is over, return to the earlier level, the last digit of the  1st number is the next highest digit, so we only need to get mod when comparing.

e.g.

121 121
12   121
1     121
0     121
meet 0 return
1     121  (check if 1==121%10)
1     12    (121/10,return to earlier level)
12   12    (check if 12%10 == 12%10)
12   1     (12/10)
121  1    (check 121%10 == 1%10)
OK!

**/

class Solution 
{
public:
    bool check(int x, int &y)
    {
        if (x == 0) {return true;}
        if (check(x / 10, y))
        {
            if (x % 10 == y % 10)
            {
                y = y / 10;
                return true;
            }
        }
        return false;
    }
    bool isPalindrome(int x) 
    {
        if (x < 0) {return false;}
        return check(x, x);
    }
};