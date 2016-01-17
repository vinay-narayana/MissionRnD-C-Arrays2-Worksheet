/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare(char *str, char *str1)
{
	int i, j, day = 0, month = 0, year = 0, day1 = 0, month1 = 0, year1 = 0;
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
				return 0;
		}
	}
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction *new_obj =(struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	int i, j, flag=-1,k=0,tmp=0;
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			flag = compare(A[i].date, B[j].date);
			if (flag == 0)
			{
				tmp = 1;
				new_obj[k] = A[i];
				k++;
				
			}
		}
	}
	if (tmp == 0)
		return NULL;
	return new_obj;
}