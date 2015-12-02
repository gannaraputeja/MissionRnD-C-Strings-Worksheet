/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>


void revstr(char *str)
{
	int l, c;
	char *end, temp;

	l = strlen(str);
	end = str + l - 1;

	for (c = 0; c < l / 2; c++)
	{
		temp = *str;
		*str = *end;
		*end = temp;
		str++;
		end--;
	}
}

void strwordsinrev(char *input)
{
	char b[100], *temp, *str;
	int count = 0;
	temp = input;
	while (*temp)
	{
		while (*temp != ' ' && *temp != '\0')
		{
			b[count] = *temp;
			temp++;
			count++;
		}
		b[count] = '\0';
		count = 0;
		revstr(b);
		str = b;
		while (*str)
		{
			*input = *str;
			str++;
			input++;
		}
		while (*input == ' ')
		{
			input++;
		}
		temp = input;
	}
}

void str_words_in_rev(char *input, int len)
{
	strwordsinrev(input);
	revstr(input);
}

