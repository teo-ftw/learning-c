#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BINARY_FLAG 'b'
#define DECIMAL_FLAG 'd'

void print_program_usage(const char* program_name)
{
	printf("Usage: %s [Option] [Positive decimal/binary number]\n\n",
			program_name);

	printf("Options:\n\n");
	printf("-b\n\tconvert from binary to decimal.\n");
	printf("-d\n\tconvert from decimal to binary.\n\n");
}

int raise_to_power(int base, int power)
{
	int result = 1;

	while (power != 0)
	{
		result *= base;

		power--;
	}

	return result;
}

int main(int argc, char* argv[])
{
	/* CLI ARGUMENTS */
	char* PROGRAM_NAME = argv[0];
	char* FLAG_ARGUMENT = argv[1];
	char* NUMBER_ARGUMENT = argv[2];

	/* FAIL CASES */
	if (argc != 3 || FLAG_ARGUMENT[0] != '-')
	{
		print_program_usage(PROGRAM_NAME);

		return 1;
	}

	for (int i = 0; i < strlen(NUMBER_ARGUMENT); i++)
		if (!isdigit(NUMBER_ARGUMENT[i]))
		{
			print_program_usage(PROGRAM_NAME);

			return 1;
		}

	/* HANDLE ARGUMENTS */
	switch (FLAG_ARGUMENT[1])
	{
		case BINARY_FLAG:

			for (int i = 0; i < strlen(NUMBER_ARGUMENT); i++)
				if (NUMBER_ARGUMENT[i] != '0' && NUMBER_ARGUMENT[i] != '1')
				{
					print_program_usage(PROGRAM_NAME);

					return 1;
				}

			int power = 0;
			int result = 0;

			for (int i = strlen(NUMBER_ARGUMENT) - 1; i >= 0; i--)
				if (NUMBER_ARGUMENT[i] == '1')
				{
					result += raise_to_power(2, power);
					power++;
				}
				else
					power++;

			printf("%d\n", result);

			break;

		case DECIMAL_FLAG:

			int decimal_number = atoi(NUMBER_ARGUMENT);
			int binary_number[32];
			
			if (decimal_number == 0)
				printf("%d\n", 0);
			else
			{
				int i = 0;
				while (decimal_number != 0)
				{
					binary_number[i] = decimal_number % 2;

					decimal_number /= 2;
					i++;
				}

				for (int j = i - 1; j >= 0; j--)
					printf("%d", binary_number[j]);

				putchar('\n');
			}

			break;

		default:
			print_program_usage(PROGRAM_NAME);
			
			return 1;
	}

	return 0;
}
