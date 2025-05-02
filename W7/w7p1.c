/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Hoda Karimi
Student ID#: 138611223
Email      : hkarimi9@myseneca.ca
Section    : NKK

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LIVES 10
#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70
#define MAX_MOVES_PERCENT 75
#define MULTIPLE 5

// Configuring the game
struct GameInfo {
    int pathLength;
    int maxMoves;
    int bombs[MAX_PATH_LENGTH];
    int treasures[MAX_PATH_LENGTH];
};

// configure the player
struct PlayerInfo {
    int lives;
    char symbol;
    int treasures;
    int history[MAX_PATH_LENGTH];
};



int main(void) {
    struct PlayerInfo player = { 0 };
    struct GameInfo game = { 0 };

    int validPlayerLives = 0; 
    int validPathLength = 0; 
    int validMaxMoves = 0; 

    int i;
    int j;
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
   

    // Player Configuration
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    // Recieving number of lives and checking
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives < 1 || player.lives > MAX_LIVES) {
            printf("     Must be between 1 and %d!\n", MIN_PATH_LENGTH);
        }
        else {
            validPlayerLives = 1;
        }
    } while (!validPlayerLives);

    // Initialize player's history
    for (i = 0; i < MAX_PATH_LENGTH; i++) {
        player.history[i] = 0;
    }

    printf("Player configuration set-up is complete\n\n");

    // Game Configuration
    printf("GAME Configuration\n");
    printf("------------------\n");
    // Recieve path length
    do {
        printf("Set the path length (a multiple of %d between "
            "%d-%d): ", MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH); 
        scanf("%d", &game.pathLength);
        if (game.pathLength < MIN_PATH_LENGTH || 
            game.pathLength > MAX_PATH_LENGTH || 
            game.pathLength % MULTIPLE != 0){
            printf("     Must be a multiple of %d and "
            "between %d-%d!!!\n", MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
        else {
            validPathLength = 1;
        }
    } while (!validPathLength);
    //Recive the limit of moves
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxMoves);
        if (game.maxMoves < player.lives || 
            game.maxMoves >(int)(game.pathLength * MAX_MOVES_PERCENT / 100)) {
            printf("    Value must be between %d and %d\n",
              player.lives, (int)(game.pathLength * MAX_MOVES_PERCENT / 100));
        }
        else {
            validMaxMoves = 1;
        }
    } while (!validMaxMoves);
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: "
        "there are %d to set!\n", game.pathLength);

    // Loop of displaying bomb position
    for (i = 0; i < game.pathLength; i += MULTIPLE) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for (j = 0; j < MULTIPLE; j++) {
            scanf("%d", &game.bombs[i + j]);
        }
    }

    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets "
        "of %d where a value\n", MULTIPLE); 
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: "
        "there are %d to set!\n", game.pathLength);
   // Loop of displaying treasure position
    for (i = 0; i < game.pathLength; i += MULTIPLE) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for (j = 0; j < MULTIPLE; j++) {
            scanf("%d", &game.treasures[i + j]);
        }
    }

    printf("TREASURE placement set\n\n");

    // Display Configuration Settings
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%d", game.treasures[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;
}

