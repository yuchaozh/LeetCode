/**
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Analysis:
This problem is pretty easy.
Just consider two special cases:
(1) last digit is 9: need a carry
(2) All the digits are 9 just return 100000... number of 0s is the length of the vector.

**/

class Solution 
{
public:
    vector<int> plusOne(vector<int> &digits) 
    {
        // if the last number is not 9
        if (digits[digits.size() - 1] != 9)
        {
            digits[digits.size() - 1]++;
            return digits;
        }
        else 
        {
            digits[digits.size() - 1] = 0;
            for (int i = digits.size() - 2; i >= 0; i--)
            {
                if (digits[i] != 9) // 1239
                {
                    digits[i]++;
                    return digits;
                }
                else // 9999
                {
                    digits[i] = 0;
                }
            }
            vector<int> res(digits.size() + 1, 0);
            res[0] = 1;
            return res;
        }
    }
};