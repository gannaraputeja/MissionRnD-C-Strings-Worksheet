/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char * intnum(int num, char s[10], int i)
{
	int temp;
	if (num<0)
	{
		s[i++] = '-';
		num = -num;
	}
	temp = num;
	while (temp>0)
	{
		temp /= 10;
		i++;
	}
	s[i--] = '\0';
	while (num>0)
	{
		s[i--] = num % 10 + 48;
		num /= 10;
	}
	return s;
}

char * floatnum(float number, char *s, int afterdecimal)
{
	int i = 0;
	s = intnum((int)number, s, 0);
	i = strlen(s);
	s[i++] = '.';
	float f = number - (int)number;
	while (afterdecimal > 0)
	{
		f *= 10;
		afterdecimal--;
	}
	if (f < 0)
	{
		f = -f;
	}
	printf("f:%f", f);
	s = intnum((int)f, s, i);
	s[strlen(s)] = '\0';
	printf("\ns:%s", s);
	return s;
}

void number_to_str(float number, char *str,int afterdecimal)
{
	if (afterdecimal>0)
	{
		str = floatnum(number, str, afterdecimal);
	}
	if (afterdecimal == 0)
	{
		int num = (int)number;
		str = intnum(num, str, 0);
	}
}
