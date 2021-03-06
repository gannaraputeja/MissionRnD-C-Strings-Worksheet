/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

#include<stdio.h>

char removeSpaces(char *str)
{
	if ((str == NULL) || (str == ""))
		return '\0';
	char *temp = str;
	while (*temp)
	{
		if (*temp != ' ')
		{
			*str = *temp;
			str++;
			temp++;
		}
		else
		{
			temp++;
		}
	}
	*str = '\0';
}