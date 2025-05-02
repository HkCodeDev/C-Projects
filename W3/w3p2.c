/*///////////////////////////////////////////////////////////////////////////
                              Reflection
                          Workshop - #3 (P2)
Full Name  : Hoda Karimi
Student ID#: 138611223
Email      : hkarimi9@myseneca.ca
Section    : NKK

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    const double GRAMS_IN_LBS = 453.5924;

    char coffeeType1, coffeeType2, coffeeType3;
    int coffeeweight1, coffeeweight2, coffeeweight3;
    char cream1, cream2, cream3;

    char customerStrength, customerCream;
    int customerServings;


    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType1);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeweight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType2);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeweight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType3);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeweight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);

    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeeType1 == 'L' || coffeeType1 == 'l'), (coffeeType1 == 'M' || coffeeType1 == 'm'), (coffeeType1 == 'R' || coffeeType1 == 'r'), coffeeweight1, (double)coffeeweight1 / GRAMS_IN_LBS, (cream1 == 'Y' || cream1 == 'y'));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeeType2 == 'L' || coffeeType2 == 'l'), (coffeeType2 == 'M' || coffeeType2 == 'm'), (coffeeType2 == 'R' || coffeeType2 == 'r'), coffeeweight2, (double)coffeeweight2 / GRAMS_IN_LBS, (cream2 == 'Y' || cream2 == 'y'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", (coffeeType3 == 'L' || coffeeType3 == 'l'), (coffeeType3 == 'M' || coffeeType3 == 'm'), (coffeeType3 == 'R' || coffeeType3 == 'r'), coffeeweight3, (double)coffeeweight3 / GRAMS_IN_LBS, (cream3 == 'Y' || cream3 == 'y'));

    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &customerStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &customerCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &customerServings);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (customerStrength == 'L' && coffeeType1 == 'L') || (customerStrength == 'l' && coffeeType1 == 'l') || (customerStrength == 'L' && coffeeType1 == 'l') || (customerStrength == 'l' && coffeeType1 == 'L') || (customerStrength == 'M' && coffeeType1 == 'M') || (customerStrength == 'm' && coffeeType1 == 'm') || (customerStrength == 'M' && coffeeType1 == 'm') || (customerStrength == 'm' && coffeeType1 == 'M') || (customerStrength == 'R' && coffeeType1 == 'R') || (customerStrength == 'r' && coffeeType1 == 'r') || (customerStrength == 'R' && coffeeType1 == 'r') || (customerStrength == 'r' && coffeeType1 == 'R'), (customerServings >= 1 && customerServings <= 4 && coffeeweight1 == 250) || ((customerServings >= 5 && customerServings <= 9 && coffeeweight1 == 500) || (customerServings >= 10 && coffeeweight1 == 1000)), (customerCream == 'Y' && cream1 == 'Y') || (customerCream == 'y' && cream1 == 'y') || (customerCream == 'Y' && cream1 == 'y') || (customerCream == 'y' && cream1 == 'Y') || (customerCream == 'N' && cream1 == 'N') || (customerCream == 'n' && cream1 == 'n') || (customerCream == 'N' && cream1 == 'n') || (customerCream == 'n' && cream1 == 'N'));
    printf(" 2|       %d         |      %d      |   %d   |\n", (customerStrength == 'L' && coffeeType2 == 'L') || (customerStrength == 'l' && coffeeType2 == 'l') || (customerStrength == 'L' && coffeeType2 == 'l') || (customerStrength == 'l' && coffeeType2 == 'L') || (customerStrength == 'M' && coffeeType2 == 'M') || (customerStrength == 'm' && coffeeType2 == 'm') || (customerStrength == 'M' && coffeeType2 == 'm') || (customerStrength == 'm' && coffeeType2 == 'M') || (customerStrength == 'R' && coffeeType2 == 'R') || (customerStrength == 'r' && coffeeType2 == 'r') || (customerStrength == 'R' && coffeeType2 == 'r') || (customerStrength == 'r' && coffeeType2 == 'R'), (customerServings >= 1 && customerServings <= 4 && coffeeweight2 == 250) || ((customerServings >= 5 && customerServings <= 9 && coffeeweight2 == 500) || (customerServings >= 10 && coffeeweight2 == 1000)), (customerCream == 'Y' && cream2 == 'Y') || (customerCream == 'y' && cream2 == 'y') || (customerCream == 'Y' && cream2 == 'y') || (customerCream == 'y' && cream2 == 'Y') || (customerCream == 'N' && cream2 == 'N') || (customerCream == 'n' && cream2 == 'n') || (customerCream == 'N' && cream2 == 'n') || (customerCream == 'n' && cream2 == 'N'));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", (customerStrength == 'L' && coffeeType3 == 'L') || (customerStrength == 'l' && coffeeType3 == 'l') || (customerStrength == 'L' && coffeeType3 == 'l') || (customerStrength == 'l' && coffeeType3 == 'L') || (customerStrength == 'M' && coffeeType3 == 'M') || (customerStrength == 'm' && coffeeType3 == 'm') || (customerStrength == 'M' && coffeeType3 == 'm') || (customerStrength == 'm' && coffeeType3 == 'M') || (customerStrength == 'R' && coffeeType3 == 'R') || (customerStrength == 'r' && coffeeType3 == 'r') || (customerStrength == 'R' && coffeeType3 == 'r') || (customerStrength == 'r' && coffeeType3 == 'R'), (customerServings >= 1 && customerServings <= 4 && coffeeweight3 == 250) || ((customerServings >= 5 && customerServings <= 9 && coffeeweight3 == 500) || (customerServings >= 10 && coffeeweight3 == 1000)), (customerCream == 'Y' && cream3 == 'Y') || (customerCream == 'y' && cream3 == 'y') || (customerCream == 'Y' && cream3 == 'y') || (customerCream == 'y' && cream3 == 'Y') || (customerCream == 'N' && cream3 == 'N') || (customerCream == 'n' && cream3 == 'n') || (customerCream == 'N' && cream3 == 'n') || (customerCream == 'n' && cream3 == 'N'));

    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &customerStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &customerCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &customerServings);
    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (customerStrength =='L' && coffeeType1 == 'L') || (customerStrength == 'l' && coffeeType1 == 'l') || (customerStrength == 'L' && coffeeType1 == 'l') || (customerStrength == 'l' && coffeeType1 == 'L') || (customerStrength == 'M' && coffeeType1 == 'M') || (customerStrength == 'm' && coffeeType1 == 'm') || (customerStrength == 'M' && coffeeType1 == 'm') || (customerStrength == 'm' && coffeeType1 == 'M') || (customerStrength == 'R' && coffeeType1 == 'R') || (customerStrength == 'r' && coffeeType1 == 'r') || (customerStrength == 'R' && coffeeType1 == 'r') || (customerStrength == 'r' && coffeeType1 == 'R'), (customerServings >= 1 && customerServings <= 4 && coffeeweight1 == 250) ||((customerServings >= 5 && customerServings <= 9 && coffeeweight1 == 500) || (customerServings >= 10 && coffeeweight1 == 1000)), (customerCream == 'Y' && cream1 == 'Y') || (customerCream == 'y' && cream1 == 'y') || (customerCream == 'Y' && cream1 == 'y') || (customerCream == 'y' && cream1 == 'Y') || (customerCream == 'N' && cream1 == 'N') || (customerCream == 'n' && cream1 == 'n') || (customerCream == 'N' && cream1 == 'n') || (customerCream == 'n' && cream1 == 'N'));
    printf(" 2|       %d         |      %d      |   %d   |\n", (customerStrength == 'L' && coffeeType2 == 'L') || (customerStrength == 'l' && coffeeType2 == 'l') || (customerStrength == 'L' && coffeeType2 == 'l') || (customerStrength == 'l' && coffeeType2 == 'L') || (customerStrength == 'M' && coffeeType2 == 'M') || (customerStrength == 'm' && coffeeType2 == 'm') || (customerStrength == 'M' && coffeeType2 == 'm') || (customerStrength == 'm' && coffeeType2 == 'M') || (customerStrength == 'R' && coffeeType2 == 'R') || (customerStrength == 'r' && coffeeType2 == 'r') || (customerStrength == 'R' && coffeeType2 == 'r') || (customerStrength == 'r' && coffeeType2 == 'R'), (customerServings >= 1 && customerServings <= 4 && coffeeweight2 == 250) || ((customerServings >= 5 && customerServings <= 9 && coffeeweight2 == 500) || (customerServings >= 10 && coffeeweight2 == 1000)), (customerCream == 'Y' && cream2 == 'Y') || (customerCream == 'y' && cream2 == 'y') || (customerCream == 'Y' && cream2 == 'y') || (customerCream == 'y' && cream2 == 'Y') || (customerCream == 'N' && cream2 == 'N') || (customerCream == 'n' && cream2 == 'n') || (customerCream == 'N' && cream2 == 'n') || (customerCream == 'n' && cream2 == 'N'));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", (customerStrength == 'L' && coffeeType3 == 'L') || (customerStrength == 'l' && coffeeType3 == 'l') || (customerStrength == 'L' && coffeeType3 == 'l') || (customerStrength == 'l' && coffeeType3 == 'L') || (customerStrength == 'M' && coffeeType3 == 'M') || (customerStrength == 'm' && coffeeType3 == 'm') || (customerStrength == 'M' && coffeeType3 == 'm') || (customerStrength == 'm' && coffeeType3 == 'M') || (customerStrength == 'R' && coffeeType3 == 'R') || (customerStrength == 'r' && coffeeType3 == 'r') || (customerStrength == 'R' && coffeeType3 == 'r') || (customerStrength == 'r' && coffeeType3 == 'R'), (customerServings >= 1 && customerServings <= 4 && coffeeweight3 == 250) || ((customerServings >= 5 && customerServings <= 9 && coffeeweight3 == 500) || (customerServings >= 10 && coffeeweight3 == 1000)), (customerCream == 'Y' && cream3 == 'Y') || (customerCream == 'y' && cream3 == 'y') || (customerCream == 'Y' && cream3 == 'y') || (customerCream == 'y' && cream3 == 'Y') || (customerCream == 'N' && cream3 == 'N') || (customerCream == 'n' && cream3 == 'n') || (customerCream == 'N' && cream3 == 'n') || (customerCream == 'n' && cream3 == 'N'));
    printf("Hope you found a product that suits your likes!\n");
    return 0;
}

