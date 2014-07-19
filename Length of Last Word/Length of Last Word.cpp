/**
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

**/

class Solution 
{
public:
    int lengthOfLastWord(const char *s) 
    {
        int size = strlen(s);
        if (size == 0) {return 0;}
        int result = 0;
        // from back to front
        for (int i = size - 1; i >= 0; i--)
        {
          if (s[i] != ' ')
            result++;
          else // encounter space
          {
            if (result > 0) // ensure ignore the space in the last, like "a "
              return result;
          }
        }
        return result;
    }
};