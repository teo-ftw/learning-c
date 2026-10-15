#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s [string]\n", argv[0]);

		return 1;
	}

	char user_input[MAX_INPUT_LENGTH + 1];

	if (strlen(argv[1]) > MAX_INPUT_LENGTH)
	{
		printf("MAX INPUT LENGTH: %d\n", MAX_INPUT_LENGTH);

		return 1;
	}

	strcpy(user_input, argv[1]);

	for (int i = 0; i < strlen(user_input); i++)
		switch (toupper(user_input[i]))
		{
			case 'A': putchar('4'); break;
			case 'B': putchar('8'); break;
			case 'C': putchar('['); break;
			case 'D': putchar(')'); break;
			case 'E': putchar('3'); break;
			case 'G': putchar('6'); break;
			case 'I': putchar('1'); break;
			case 'O': putchar('0'); break;
			case 'S': putchar('5'); break;
			case 'T': putchar('7'); break;

			default: putchar(user_input[i]); break;
		}

	putchar('\n');

	return 0;
}
