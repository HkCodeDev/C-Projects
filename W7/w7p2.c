/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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
    char location[MAX_PATH_LENGTH];
    int moves;
};

int main(void) {
    struct PlayerInfo player = { 0 };
    struct GameInfo game = { 0 };

    int i, j;
    int valid = 1;

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
            //I changed the flags for part 1 and used one flag for the rest of the code
            valid = 1;
        }
        else {
            valid = 0;
        }
    } while (valid);

    // Initialize player's history


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
            game.pathLength % MULTIPLE != 0) {
            printf("     Must be a multiple of %d and "
                "between %d-%d!!!\n", MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
            valid = 1;
        }
        else {
            valid = 0;
        }
    } while (valid);
    // Form the path with '-' 
    for (i = 0; i < game.pathLength; i++)
    {
        player.location[i] = '-';
    }
    // Limit of moves
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxMoves);
        if (game.maxMoves < player.lives ||
            game.maxMoves >(int)(game.pathLength * MAX_MOVES_PERCENT / 100)) {
            printf("    Value must be between %d and %d\n",
                player.lives, (int)(game.pathLength * MAX_MOVES_PERCENT / 100));
            valid = 0;
        }
        else {
            valid = 1;
        }
    } while (!valid);
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
    // Display Game board 
    while (game.maxMoves > 0 && player.lives > 0) {
        // If there's no player move, go to next line
        if (player.moves == 0) {
            printf("\n");
        }
        // If player moved go forward
        else {
            printf("  ");
            i = 0;
            valid = 1;
            // The current position of the player
            // Count the moves
            while (valid) {
                if (player.moves != 0 && i == player.moves - 1) {
                    // If there's no moves left to count, stop right there!
                    printf("%c", player.symbol);
                    valid = 0;
                }
                //If there's still any left, keep counting and spacing
                else {
                    printf(" ");
                    i++;
                    valid = 1;
                }

            }
            printf("\n");
        }
        printf("  ");
        // Display the symbols of game path
        for (i = 0; i < game.pathLength; i++) {
            printf("%c", player.location[i]);
        }
        printf("\n");
        printf("  ");

        //Major ruler
        //|||||||||1|||||||||2
        for (i = 1; i <= game.pathLength; i++) {
            if (i % 10 != 0) {
                printf("|");
            }
            else
            {
                printf("%d", (i + 1) / 10);

            }
        }
        printf("\n");
        printf("  ");
        // Minor ruler
        //1234567890
        for (i = 1; i <= game.pathLength; i++) {
            printf("%d", i % 10);

        }
        printf("\n");

        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: "
            "%2d\n", player.lives, player.treasures, game.maxMoves);
        printf("+---------------------------------------------------+\n");
        do {
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &player.moves);
            if (player.moves >= 1 && player.moves <= game.pathLength) {

                valid = 0;
            }
            else {
                printf("  Out of Range!!!\n");
                valid = 1;
            }
        } while (valid);

        printf("\n");
        // Game Starts
        // Each character reperasent: 
        // !:bomb, $:treasure, &: both, .:none, -:not there yet
        if (player.location[player.moves - 1] == '-') {
            if (game.bombs[player.moves - 1] == 1) {
                if (game.treasures[player.moves - 1] == 1) {
                    printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                    printf("===============> [&] $$$ Life "
                        "Insurance Payout!!! [&]\n");
                    printf("\n");
                    player.lives--;
                    player.treasures++;
                    player.location[player.moves - 1] = '&';
                }
                else {
                    printf("===============> [!] !!! BOOOOOM !!! [!]\n");
                    printf("\n");
                    player.lives--;
                    player.location[player.moves - 1] = '!';
                }
            }
            else if (game.treasures[player.moves - 1] == 1) {
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
                printf("\n");
                player.treasures++;
                player.location[player.moves - 1] = '$';
            }
            else {
                printf("===============> [.] ...Nothing found here... [.]\n");
                printf("\n");
                player.location[player.moves - 1] = '.';
            }
            // Reduce the moves
            game.maxMoves--;
        }
        // If it's a location that the player privously went to, don't reduce
        else {
            printf("===============> Dope! You've been here before!\n");
            printf("\n");
        }
    }

    player.lives == 0 ? printf("No more LIVES remaining!\n\n")
        : printf("No more MOVES remaining!\n\n");
    // For the last display, when the game is over
    printf("  ");
    valid = 1;
    i = 0;
    // The current position of the character
    while (valid) {
        if (i == player.moves - 1 && player.moves != 0) {
            printf("%c", player.symbol);
            valid = 0;
        }
        else {
            printf(" ");
            i++;
            valid = 1;
        }
    }
    printf("\n");
    printf("  ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%c", player.location[i]);
    }
    printf("\n");
    printf("  ");
    //Major ruler
    for (i = 1; i <= game.pathLength; i++) {
        if (i % 10 != 0) {
            printf("|");
        }
        else {
            printf("%d", (i + 1) / 10);

        }
    }
    printf("\n");
    printf("  ");
    // Minor ruler
    for (i = 1; i <= game.pathLength; i++) {
        printf("%d", i % 10);
    }
    printf("\n");
    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  "
        "Moves Remaining: %2d\n", player.lives, player.treasures, game.maxMoves);
    printf("+---------------------------------------------------+\n\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n");
    return 0;
}