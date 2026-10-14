#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	/* Seed the random number generation
	 * with the current time. */
	srand(time(NULL));

	const int CORRECT_NUMBER = (rand() % 10) + 1;

	printf("Guess a number between 1 and 10!\n\n");

	int guesses_count = 0;
	int is_game_over = 0;
	while (!is_game_over)
	{
		int user_guess;

		printf("GUESS: ");
		scanf("%d", &user_guess);

		guesses_count++;

		if (user_guess > CORRECT_NUMBER)
			printf("Too high!\n");
		else if (user_guess < CORRECT_NUMBER)
			printf("Too low!\n");
		else
		{
			printf("Correct!\n");
			printf("You won in %d guess(es).\n", guesses_count);

			is_game_over = 1;
		}
	}

	return 0;
}
