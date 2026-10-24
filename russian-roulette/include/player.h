#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player
{
    int choice;
    char bullets[6];
} Player;

int parse_player_input(char* string, int* integer);
int get_player_choice(void);

void play_alone(Player* player);

#endif