#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>

#include "player.h"
#include "console.h"

#define MAX_INPUT_LENGTH 128

int parse_player_input(char* string, int* integer)
{
	char integer_string[MAX_INPUT_LENGTH];
	int integer_char_count = 0;
	int i = 0;

	while (isspace(string[i])) i++;
	
	int string_length = strlen(string);

	if (i == string_length)
		return 0;

	if (string[i] == '-')
	{
		integer_string[integer_char_count] = '-';

		integer_char_count++;
		i++;

		if (!isdigit(string[i]))
			return 0;
	}

	while (i < string_length && !isspace(string[i]))
	{
		if (!isdigit(string[i]))
			return 0;

		integer_string[integer_char_count] = string[i];
	
		integer_char_count++;
		i++;
	}

	integer_string[integer_char_count] = '\0';

	while (isspace(string[i])) i++;

	if (string[i] != '\0')
		return 0;
	
	*integer = atoi(integer_string);

	return 1;
}

int get_player_choice()
{
	int player_choice;
	int is_parsed_correctly = 1;

	do
	{
		char input_string[MAX_INPUT_LENGTH];

		printf("CHOICE > ");
		fgets(input_string, MAX_INPUT_LENGTH, stdin);
		putchar('\n');

		is_parsed_correctly = parse_player_input(input_string, &player_choice);
		if (!is_parsed_correctly)
			printf("[ERROR]: Non integer value entered.\n\n");
		else if (player_choice != 0 && player_choice != 1 && player_choice != 2)
		{
			printf("[ERROR]: Invalid option entered.\n\n");

			is_parsed_correctly = 0;
		}
	}
	while (!is_parsed_correctly);

	return player_choice;
}

void play_alone(Player* player)
{
	int shots_fired = 0;
	int is_game_over = 0;
	
	int initial_bullet_position = rand() % 6;
	int position = 0;

	player->bullets[initial_bullet_position] = 'X';

	while (!is_game_over)
	{
		clear_console();

		printf("0 -- QUIT\n");
		printf("1 -- SHOOT YOURSELF\n");
		printf("2 -- SPIN CYLINDER\n\n");

		player->choice = get_player_choice();

		switch (player->choice)
		{
			case 0:
				is_game_over = 1;

				clear_console();
				display_random_quote("./data/quotes.txt");

				printf("\n\n");

				printf("You walked out of here alive after %d shot(s) fired.\n", shots_fired);

				if (shots_fired == 0)
					printf("Guess life's treating you well, then.\n");
				else if (shots_fired <= 5)
					printf("Lucky bastard.\n");
				else if (shots_fired <= 25)
					printf("Damn, you doing alright homie?\n");
				else if (shots_fired <= 50)
					printf("You might as well cheer up, you're lucky asf.\n");
				else
					printf("How in the hell are you still alive?!\n");

				putchar('\n');

				break;
			
			case 1:
				shots_fired++;

				if (player->bullets[position] == 'X')
				{
					printf("*  B O O M  *\n\n");

					printf("\"In loving memory of [CENSORED]. (20XX-2026)\n");
					printf("Died in a deadly game of russian roulette ");
					printf("after %d shot(s) fired.\"\n", shots_fired);

					is_game_over = 1;
				}
				else
				{
					printf("*  C L I C K  *\n");

					position++;
				}

				putchar('\n');

				break;

			case 2:
				printf("Spinning the cylinder");

				for (int i = 0; i < 4; i++)
				{
					#ifdef _WIN32
						Sleep(250);
					#elif defined(__linux__)
						sleep(250);
					#elif defined(__APPLE__)
						sleep(250);
					#endif

					if (i == 3)
						putchar(' ');
					else
						putchar('.');
				}

				printf("\n\n");

				for (int i = 0; i < 6; i++)
					player->bullets[i] = ' ';

				int new_bullet_position = rand() % 6;

				player->bullets[new_bullet_position] = 'X';

				position = 0;

				break;
		}

		wait_for_confirmation();
	}
}