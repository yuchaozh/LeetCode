/**
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

**/

// O(m*n)
int index_BF(char S[], char T[], int pos)
{
	int i = pos;
	int j = 0;
	while (S[i + j] != '/0' && T[j] != '/0')
	{
		if (S[i + j] == T[i])
		{
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	if (T[j]  = '/0')
		return i;
	else
		return -1;
}




class Solution 
{
public:
    char *strStr(char *haystack, char *needle) 
    {
        
    }
};