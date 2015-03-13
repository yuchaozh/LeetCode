/**
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

Analysis:
This is an easy and fundamental problem about string and char.

Set two pointers from the start and the end of the string to test Palindrome, skip the chars that are not alphanumeric and compare the lower case of each pair of chars.

Here are some tricks:
(1) upper lower cases:  #include <cctype>, there is a function called "tolower()"
(2) alphanumeric: also in <cctype>(or <ctype.h>), a function called "isalnum()"

**/

class Solution 
{
public:
  bool isPalindrome(string s) 
  {
    if (s.size() == 0)
      return true;
    int st = 0;
    int ed = s.size() - 1;

    while (st < ed)
    {
      // alphanumeric
      if (isalnum(s[st]) == false)
      {
        st++;
        continue;
      }
      if (isalnum(s[ed]) == false)
      {
        ed--;
        continue;
      }


      if (tolower(s[st]) != tolower(s[ed]))
      {
        return false;
      }
      else
      {
        st++;
        ed--;
      }
    }
    return true;
  }
};