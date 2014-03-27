/**
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

Analysis:
The clarification is very important, during the interview, one should think of these points without hint, and then implement the algorithm.

By checking the clarifications, the programming is straightforward, here provides a simple version which uses buffer strings:
(1)Loop from start to the end of the string:
          (a) if current char is space and word string is empty, continue.
          (b) if current char is space but word string is NOT empty, which means we meet the end of word, then output the word, reset the word, continue.
          (c) if current char is non-space char, add this char to the word string, continue
(2)Handle the last word:
      (a) if the last word is empty, which means the input is empty, or the input has only spaces, or the last char/chars are spaces.  Then just remove the last space in the output string and return.
      (b) if the last word is not empty, add the last word to the front of the output string, then remove the last space in the output string and return.
**/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// split the string using space and store substring into a vector. assgin the s with reversing the vector.
/**
class Solution 
{
public:
    void reverseWords(string &s) 
    {
    	string result = "";
    	vector<string> words;
    	// use istringstream to split the space
        istringstream iss(s);
         do
    	 {
        	string sub;
        	iss >> sub;
        	words.push_back(sub);
    	 } while (iss);
    	 s = "";
		for (int i = words.size() - 2; i >= 1; i--)
    	{	
    		result = s.append(words[i] + " ");
    	}
    	result = s.append(words[0]);
    }
};
**/


class Solution 
{
public:
    void reverseWords(string &s) 
    {
    	string word;
    	string result;
    	int i = 0;
    	while (i < s.size())
    	{
    		// not space, store the char into the word
    		if (char(s[i]) != ' ')
    		{
    			word = word + char(s[i]);
    			i++;
    			continue;
    		}
    		// multiple space
    		if (char(s[i]) == ' ' && word.empty())
    		{
    			i++;
    			continue;
    		}
    		// meet space, store in the front of the result, ans reset word
    		if (char(s[i]) == ' ' && !word.empty())
    		{
    			result = word + " " + result;
    			word = "";
    			i++;
    			continue;
    		}
    	}
    	
    	// the last word
    	// the last word has no space after it, so it cannot be dealed in the while loop
    	if (!word.empty())
    	{
    		result = word + " " + result;
    	}
    	// delete the space in the last
    	s = result.substr(0, result.size() - 1);
    	//cout<<s<<"."<<endl;
    }
};
    
int main()
{
    string s = "the sky is blue";
	Solution sol;
	sol.reverseWords(s);
	return 0;
}



















