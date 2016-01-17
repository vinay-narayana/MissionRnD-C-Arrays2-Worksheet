/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int validate(int day, int month, int year)
{
	int range[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 == 0)
		range[1] = 29;
	if ((month > 0 && month <= 12) && (day <= range[month - 1]))
		return 1;
	else
		return 0;
}
int isOlder(char *str, char *str1)
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
	v1 = validate(day, month, year);
	v2 = validate(day1, month1, year1);
	if (v1 == 0 || v2 == 0)
		return -1;
	else if (year<year1)
		return 1;
	else if (year1 < year)
		return 2;
	else if (month < month1)
		return 1;
	else if (month1 < month)
		return 2;
	else if (day < day1)
		return 1;
	else if (day1 < day)
		return 2;
	else
		return 0;
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	
	int s = 0, i, flag = 0;
	for (i = 0; i < len; i++)
	{
		flag = isOlder(Arr[i].date, date);
		if (flag == 2)
			s++;
	}
	return s;

}
