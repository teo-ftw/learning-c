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
	char* program_name = argv[0];
	char* flag_argument = argv[1];
	char* number_argument = argv[2];

	/* FAIL CASES */
	if (argc != 3 || flag_argument[0] != '-')
	{
		print_program_usage(program_name);

		return 1;
	}

	for (int i = 0; i < strlen(number_argument); i++)
		if (!isdigit(number_argument[i]))
		{
			print_program_usage(program_name);

			return 1;
		}

	/* HANDLE ARGUMENTS */
	switch (flag_argument[1])
	{
		case BINARY_FLAG:

			for (int i = 0; i < strlen(number_argument); i++)
				if (number_argument[i] != '0' && number_argument[i] != '1')
				{
					print_program_usage(program_name);

					return 1;
				}

			int power = 0;
			int result = 0;

			for (int i = strlen(number_argument) - 1; i >= 0; i--)
				if (number_argument[i] == '1')
				{
					result += raise_to_power(2, power);
					power++;
				}
				else
					power++;

			printf("%d\n", result);

			break;

		case DECIMAL_FLAG:

			int decimal_number = atoi(number_argument);
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
			print_program_usage(program_name);
			
			return 1;
	}

	return 0;
}
