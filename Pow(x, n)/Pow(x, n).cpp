/**
Implement pow(x, n).

Analysis:
If we just use the normal way of calculation, when face 1 to the power of 10000, the computation complexity is too high.

Consider this way:
If we want to get 2^10,

2^10  = 2^4 * 2^4 *2^2
2^4 = 2^2*2^2
2^2 = 2*2

Let's see this in a bottom-up way, totally it needs to loop n/2 > 0 times, first we have 2^1=2, then we can have 2^2 = 2*2=4, and again we have 2^4 = 4*4, (key point:) and if n%2==1, we need one more previous value, which is 2^2 here, so we have 2^4*2^4*2^2 = 2^10.

**/

// Time limit exceeded
class Solution 
{
public:
    double pow(double x, int n) 
    {
        int sign = n > 0? 1 : -1;
        double y = 1;
        for (int i = 0; i < abs(n); i++)
            y = y * x;
        if (sign == -1)
            return 1 / y;
        else
            return y;
    }
};

class Solution 
{
public:
    double pow(double x, int n) 
    {
        if (x == 0)
        {
            if (n == 0)
                return 1;
            else
                return 0;
        }
        if (n == 0)
            return 1;
        
        bool pos = true;
        if (n < 0)
        {
            pos = false;
            n = abs(n);
        }
        double np = x;
        double res = 1;
        while (n > 0)
        {
            if (n % 2 == 1)
                res = res * np;
            np = np * np;
            n = n / 2;
        }
        return pos ? res: 1 / res;
    }
};