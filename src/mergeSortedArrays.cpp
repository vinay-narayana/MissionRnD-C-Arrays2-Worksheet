/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<malloc.h>
#include<string.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
typedef struct transaction temp_obj;


int isBigger(char *str, char *str1)
{
	int i, j, day = 0, month = 0, year = 0, day1 = 0, month1 = 0, year1 = 0, v1, v2;
	for (i = 0; str[i] >= '0' && str[i] <= '9'; i++)
	{
		day = (day * 10) + str[i] - '0';
		day1 = (day1 * 10) + str1[i] - '0';
	}
	i++;
	for (j = i; str[j] >= '0' && str[j] <= '9'; j++)
	{
		month = (month * 10) + str[j] - '0';
		month1 = (month1 * 10) + str1[j] - '0';
	}
	j++;
	for (i = j; str[i] >= '0' && str[i] <= '9'; i++)
	{
		year = (year * 10) + str[i] - '0';
		year1 = (year1 * 10) + str1[i] - '0';
	}
	
	if (year < year1)
		return 1;
	else if (year>year1)
		return 2;
	else
	{
		if (month < month1)
			return 1;
		else if (month>month1)
			return 2;
		else
		{
			if (day < day1)
				return 1;
			else if (day>day1)
				return 2;
			else
				return 1;
		}
	}
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction *newobj=(struct transaction *)malloc(sizeof(struct transaction)*(ALen+BLen));
	int bigger_len = ALen>BLen ? ALen : BLen;
	int flag, i=0, j=0,k=0;
	while (i!=ALen && j!=BLen)
	{
		flag = isBigger(A[i].date, B[j].date);
		if (flag == 1)
		{
			newobj[k] = A[i];
			k++;
			i++;
		}
		if (flag == 2)
		{
			newobj[k] = B[j];
			k++;
			j++;
		}
	}
	while (i != ALen)
	{
		newobj[k] = A[i];
		k++;
		i++;
	}
	while (j != BLen)
	{
		newobj[k] = B[j];
		k++;
		j++;
	}
	
	return newobj;
}