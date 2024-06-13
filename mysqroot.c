#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define LIMIT 0.001
#define MAX_ITERATION 25
#define MAX_LENGTH_INPUT 20
int ifchar(const char *);

int main(int argc, char **argv)
{
	int i = 0;
	float z = 1;
	double number = 0, temp = 0;

	if (argc != 2) // if argument is not given
	{
		printf("number not provided\n usage:./a.out number\n");
		return 1;
	}
	else if (argv[1][0] == '-') // checking number is negetive
	{
		printf("%s incorrect number \n", argv[1]);
		return 1;
	}
	else if (ifchar(argv[1])) // checking input is other then integer
	{
		printf("incorrect input %s\n", argv[1]);
		return 1;
	}

	if (argv[1][0] == '+') // if input start with +
	{
		number = atof(argv[1] + 1);
		if (number == 0)
		{
			printf("incorrect input %s \n", argv[1]);
			return 1;
		}
	}
	else
	{
		number = atof(argv[1]);
	}

	if (strlen(argv[1]) > MAX_LENGTH_INPUT)
	{
		printf("Too long input\n");
		return 1;
	}

	for (i = 0; i < MAX_ITERATION; i++)
	{
		temp = z;
		z -= ((z * z) - number) / (2 * z);

		if (fabs(temp - z) <= LIMIT)
		{
			printf("%s  %.4f\n", argv[1], z);
			break;
		}
	}
	if (i == MAX_ITERATION)
	{
		printf("%s  %.4f\n", argv[1], z);
	}
}

// checking if character present  as an input
int ifchar(const char *string)
{
	int count = 0;
	for (int index = 0; string[index]; index++)
	{
		if (string[index] >= '0' && string[index] <= '9')
		{
			continue;
		}
		else
		{

			if (string[index] == '.')
			{
				count++;
				if (count > 1)
				{
					return 1;
				}
			}
			if (string[index] == '+' || string[index] == '.')
				continue;
			return 1;
		}
	}
	return 0;
}

/*
 ************TEST CASES***************
1) -1 incorrect input
2) - incorrect input
3) + incorrect input
4) % incorrect input
5) a incorrect input
6) +1 valid input
*/
