#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BET_MULTIPLIER 5

void print_choices()
{
	printf("0. QUIT\n");
	printf("1. BET\n");

	putchar('\n');
}

int get_player_choice()
{
	int player_choice;

	printf("CHOICE: ");
	scanf("%d", &player_choice);

	if (player_choice == 0 || player_choice == 1)
		return player_choice;

	return -1;
}

typedef struct Player
{
	float balance;
	float bet;
	
	int choice;
} Player;

int main(void)
{
	/* Seed the random number generation
	 * with the current time. */
	srand(time(NULL));

	const char SYMBOLS[] = {'7', 'X', '0'};

	Player player;
	player.balance = 10;

	printf("WELCOME!\n");
	printf("(Winnings: 5 x BET)\n\n");

	int is_game_over = 0;
	while (!is_game_over)
	{
		printf("CURRENT BALANCE: $%0.2f\n\n", player.balance);

		print_choices();

		player.choice = get_player_choice();

		switch (player.choice)
		{
			case 0:
				printf("Thank you for playing!\n");
				printf("Your remaining balance is $%0.2f.\n", player.balance);

				is_game_over = 1;

				break;

			case 1:
				printf("BET AMOUNT: $");
				scanf("%f", &player.bet);

				if (player.bet > player.balance)
				{
					printf("Insufficient funds.\n\n");
					continue;
				}
				else if (player.bet <= 0)
				{
					printf("The minimum bet amount is $0.1\n\n");
					continue;
				}

				player.balance -= player.bet;

				int first_symbol = rand() % 3;
				int second_symbol = rand() % 3;
				int third_symbol = rand() % 3;

				printf("[ %c | %c | %c ]\n\n",
					SYMBOLS[first_symbol],
					SYMBOLS[second_symbol],
					SYMBOLS[third_symbol]
				);

				if (first_symbol == second_symbol && second_symbol == third_symbol)
					player.balance += BET_MULTIPLIER * player.bet;
				else
					printf("Better luck next spin!\n\n");

				break;

			default:
				printf("Invalid choice inputted.\n\n");

				continue;
		}
	
		if (player.balance == 0)
		{
			printf("GAME OVER!!! NOW GET OUT OF MY CASINO!\n");
			
			is_game_over = 1;
		}
	}

	return 0;
}
