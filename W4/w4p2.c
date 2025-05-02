/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Hoda Karimi
Student ID#: 138611223
Email      : hkarimi9@myseneca.ca
Section    : NKK

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int apples, oranges, pears, tomatoes, cabbages;
    int shoppingFlag;

    do {
        shoppingFlag = 0;

        printf("Grocery Shopping\n");
        printf("================\n");

        printf("How many APPLES do you need? : ");
        scanf("%d", &apples);

        while (apples < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
        }

        printf("\nHow many ORANGES do you need? : ");
        scanf("%d", &oranges);
        while (oranges < 0) 
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
        }

        printf("\nHow many PEARS do you need? : ");
        scanf("%d", &pears);
        while (pears < 0) 
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
        }

        printf("\nHow many TOMATOES do you need? : ");
        scanf("%d", &tomatoes);
        while (tomatoes < 0) 
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
        }

        printf("\nHow many CABBAGES do you need? : ");
        scanf("%d", &cabbages);
        while (cabbages < 0) 
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
        }

        printf("\n--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");


        if (apples > 0) 
        {
            int pickedApples = 0;
            int remainingApples = apples;

            while (remainingApples > 0) 
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickedApples);

                if (pickedApples < 1) 
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickedApples > remainingApples) 
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", remainingApples);
                }
                else 
                {
                    remainingApples -= pickedApples;
                    if (remainingApples > 0) 
                    {
                        printf("Looks like we still need some APPLES...\n");
                    }
                    else 
                    {
                        printf("Great, that's the apples done!\n\n");
                    }
                }
            }
        }
        if (oranges > 0) 
        {
            int pickedOranges = 0;
            int remainingOranges = oranges;

            while (remainingOranges > 0) 
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickedOranges);

                if (pickedOranges < 1) 
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickedOranges > remainingOranges) 
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", remainingOranges);
                }
                else
                {
                    remainingOranges -= pickedOranges;
                    if (remainingOranges > 0) 
                    {
                        printf("Looks like we still need some ORANGES...\n");
                    }
                    else 
                    {
                        printf("Great, that's the oranges done!\n\n");
                    }
                }
            }
        }
        if (pears > 0) 
        {
            int pickedPears = 0;
            int remainingPears = pears;

            while (remainingPears > 0) 
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickedPears);

                if (pickedPears < 1) 
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickedPears > remainingPears) 
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", remainingPears);
                }
                else 
                {
                    remainingPears -= pickedPears;
                    if (remainingPears > 0) 
                    {
                        printf("Looks like we still need some PEARS...\n");
                    }
                    else
                    {
                        printf("Great, that's the pears done!\n\n");
                    }
                }
            }
        }
        if (tomatoes > 0)
        {
            int pickedTomatoes = 0;
            int remainingTomatoes = tomatoes;

            while (remainingTomatoes > 0) 
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickedTomatoes);

                if (pickedTomatoes < 1) 
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickedTomatoes > remainingTomatoes) 
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", remainingTomatoes);
                }
                else 
                {
                    remainingTomatoes -= pickedTomatoes;
                    if (remainingTomatoes > 0) 
                    {
                        printf("Looks like we still need some TOMATOES...\n");
                    }
                    else 
                    {
                        printf("Great, that's the tomatoes done!\n\n");
                    }
                }
            }
        }
        if (cabbages > 0) 
        {
            int pickedCabbages = 0;
            int remainingCabbages = cabbages;

            while (remainingCabbages > 0) 
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickedCabbages);

                if (pickedCabbages < 1) 
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickedCabbages > remainingCabbages) 
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", remainingCabbages);
                }
                else 
                {
                    remainingCabbages -= pickedCabbages;
                    if (remainingCabbages > 0) 
                    {
                        printf("Looks like we still need some CABBAGES...\n");
                    }
                    else 
                    {
                        printf("Great, that's the cabbages done!\n");
                    }
                }
            }
            printf("\n");
        } printf("All the items are picked!\n\n");

            printf("Do another shopping? (0=NO): ");
            scanf("%d", &shoppingFlag);
            printf("\n");
    } while (shoppingFlag == 1);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}
