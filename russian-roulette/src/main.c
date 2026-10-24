#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"
#include "player.h"

int main(void)
{
	/* Seed the random number generation
	with the current time. */
	srand(time(NULL));

	clear_console();
	display_main_menu();

	Player player;
	for (int i = 0; i < 6; i++)
		player.bullets[i] = ' ';
	
	player.choice = get_player_choice();

	switch (player.choice)
	{
		case 0:
			clear_console();
			display_random_quote("./data/quotes.txt");

			putchar('\n');

			wait_for_confirmation();

			break;

		case 1:
			clear_console();

			play_alone(&player);

			break;

		case 2:
			clear_console();

			printf("!!! UNDER CONSTRUCTION !!!\n\n");

			wait_for_confirmation();
			
			break;
	}

	return 0;
}