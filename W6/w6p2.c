/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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

#define MAX_ITEMS 10
#define MIN_ITEMS 1

int main(void) {

    double income = 0.0;
    int numItems = 0;
    const double minIncome = 500.00;
    const double maxIncome = 400000.00;
    const double minCost = 100.00;
    double totalCost = 0.0;
    double costs[MAX_ITEMS] = { 0 };
    int priorities[MAX_ITEMS] = { 0 };
    char financing[MAX_ITEMS] = " ";
    int flag = 1;
    int quitFlag = 0;

    int i;
    int j;
    int filterPriority = 0;
    double filterAmount = 0;
    int hasFinancingOptions = 0;
    double combinedPrice = 0;
    int years = 0;
    int months = 0;



    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");
    // Part 1 of the loop
    // Step 1: Prompt for monthly income
    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);
        if (income < minIncome) {
            printf("ERROR: You must have a consistent monthly "
                "income of at least $%.2lf\n\n", minIncome);
        }
        else if (income > maxIncome) {
            printf("ERROR: Liar! I'll believe you if you enter a value "
                "no more than $%.2lf\n\n", maxIncome);
        }
    } while (income < minIncome || income > maxIncome);

    // Step 2: Prompt for the number of wish list items
    do {
        printf("\n");
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numItems);
        if (numItems < MIN_ITEMS || numItems > MAX_ITEMS) {
            printf("ERROR: List is restricted "
                "to between %d and %d items.\n", MIN_ITEMS, MAX_ITEMS);
        }
    } while (numItems < MIN_ITEMS || numItems > MAX_ITEMS);

    // Step 3, 4, 5: Collect wish list item details
    if (flag) {

        for (i = 0; i < numItems; i++) {
            printf("\n");
            printf("Item-%d Details:\n", i + 1);

            // Item cost
            do {
                printf("   Item cost: $");
                scanf("%lf", &costs[i]);
                if (costs[i] < minCost) {
                    printf("      ERROR: Cost must be at least $%.2lf\n", minCost);
                }
            } while (costs[i] < minCost);

            // Item priority
            do {
                printf("   How important is it to you? "
                    "[1=must have, 2=important, 3=want]: ");
                scanf("%d", &priorities[i]);
                if (priorities[i] < 1 || priorities[i] > 3) {
                    printf("      ERROR: Value must be between 1 and 3\n");
                }
            } while (priorities[i] < 1 || priorities[i] > 3);

            // Financing options
            do {
                printf("   Does this item have financing options? [y/n]: ");
                scanf(" %c", &financing[i]);
                if (financing[i] != 'y' && financing[i] != 'n') {
                    printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                }
            } while (financing[i] != 'y' && financing[i] != 'n');
        }
    }
    // Step 7: Display a formatted table of the data
    printf("\n");
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < numItems; i++) {
        printf("%3d  %5d    %5c    "
            "%11.2lf\n", i + 1, priorities[i], financing[i], costs[i]);
    }

    // Step 8: Summarize total item costs

    for (i = 0; i < numItems; i++) {
        totalCost += costs[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);

    // Part 2 loop begins
    // Step 1 & 2: print the menu
    while (!quitFlag) {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &filterPriority);
        // Step 3: if 0 is entered, end the loop
        if (filterPriority == 0) {
            printf("\n");
            printf("Best of luck in all your future endeavours!\n");
            quitFlag = 1;
        }
        // Step 4: take care of invalid values for menue selection
        else if (filterPriority != 0 && filterPriority != 1 && filterPriority != 2) {
            printf("\n");
            printf("ERROR: Invalid menu selection.\n");
            printf("\n");
        }
        // Step 5: choosing option 1
        else if (filterPriority == 1) {
            // Forecast all items
            filterAmount = 0;
            // Remeber if the item has financing option
            for (i = 0; i < numItems; i++) {
                filterAmount += costs[i];
                if (financing[i] == 'y') {
                    hasFinancingOptions = 1;
                }

            }
            // Calculate the months and years
            years = (int)(filterAmount / (income * 12));
            months = (int)((filterAmount / income) - (years * 12));
            if ((filterAmount - (income * 12 * years)) > 0) {
                months++;
            }

            printf("\n");
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", filterAmount);
            printf("Forecast: %d years, %d months\n", years, months);

            // If at least 1 item has has financial option
            if (hasFinancingOptions) {
                printf("NOTE: Financing options are available"
                     " on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }

                printf("====================================================\n");
                printf("\n");
        }
        // Step 6: choosing option 2
        else if (filterPriority == 2) {
            printf("\n");
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &filterPriority);
            // Remeber if the item has financing option
            filterAmount = 0;
            hasFinancingOptions = 0;
              for (i = 0; i < numItems; i++) {
                if (priorities[i] == filterPriority) {
                    filterAmount += costs[i];
                    if (financing[i] == 'y') {
                        // Set the flag if financing is available
                        hasFinancingOptions = 1;  
                    }

                }
            }
          // Add the item costs if they have the same priority number
            combinedPrice = filterAmount;
            for (j = i + 1; j < numItems; j++) {
                if (priorities[i]== priorities[j]) {
                    combinedPrice += filterAmount;
                    
                }
            }

           // Calculating the months and years
            years = (int)(filterAmount / (income * 12));
            months = (int)((filterAmount / income) - (years * 12));
            if ((filterAmount - (income * 12 * years)) > 0) {
                months++;
            }
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", filterPriority);
            printf("Amount:   $%1.2lf\n", combinedPrice);
            printf("Forecast: %d years, %d months\n", years, months);


            // Print the finance option note
            if (hasFinancingOptions) {
                printf("NOTE: Financing options are available"
                    " on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
                printf("====================================================\n");
                printf("\n");
        }
    }
   return 0;
}


