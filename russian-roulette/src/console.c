#include <stdio.h>
#include <stdlib.h>

void clear_console(void)
{
    #ifdef _WIN32
        system("cls");
    #elif defined(__linux__)
        system("clear");
    #elif defined(__APPLE__)
        system("clear");
    #endif
}

void display_main_menu(void)
{
    printf("-- RUSSIAN ROULETTE --\n\n");

	printf("0 -- QUIT\n");
	printf("1 -- PLAY ALONE\n");
	printf("2 -- PLAY BOT\n\n");
}

void wait_for_confirmation(void)
{
    printf("Press ENTER to continue... ");

    getchar();
}

void display_random_quote(const char* file_name)
{
    FILE* file;

    file = fopen(file_name, "r");

    if (file == NULL)
    {
        printf("[ERROR]: File could not be opened.\n");

        return;
    }

    char quote[1024];
    int quotes_count = 0;

    while (fgets(quote, sizeof(quote), file) != NULL)
        quotes_count++;
    
    if (quotes_count == 0)
    {
        printf("[ERROR]: File is empty.\n");

        fclose(file);
        return;
    }

    int quote_number = rand() % quotes_count;

    rewind(file);

    for (int i = 0; i <= quote_number; i++)
        fgets(quote, sizeof(quote), file);
    
    printf("%s", quote);

    fclose(file);
}