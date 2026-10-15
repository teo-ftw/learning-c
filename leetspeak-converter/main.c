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
	char leetspeak_result[MAX_INPUT_LENGTH + 1] = "";

	if (strlen(argv[1]) > MAX_INPUT_LENGTH)
	{
		printf("MAX INPUT LENGTH: %d\n", MAX_INPUT_LENGTH);

		return 1;
	}

	strcpy(user_input, argv[1]);

	for (int i = 0; i < strlen(user_input); i++)
		switch (toupper(user_input[i]))
		{
			case 'A': strcat(leetspeak_result, "4"); break;
			case 'B': strcat(leetspeak_result, "8"); break;
			case 'C': strcat(leetspeak_result, "["); break;
			case 'D': strcat(leetspeak_result, ")"); break;
			case 'E': strcat(leetspeak_result, "3"); break;
			case 'G': strcat(leetspeak_result, "6"); break;
			case 'I': strcat(leetspeak_result, "1"); break;
			case 'O': strcat(leetspeak_result, "0"); break;
			case 'S': strcat(leetspeak_result, "5"); break;
			case 'T': strcat(leetspeak_result, "7"); break;

			default:
				  char character_string[2];
				  character_string[0] = user_input[i];

				  strcat(leetspeak_result, character_string);

				  break;
		}

	printf("%s\n", leetspeak_result);

	return 0;
}
