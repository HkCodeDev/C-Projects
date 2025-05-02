/*****************************************************************************
<assessment name example : Workshop - #2 (Part - 1)>
Full Name : Hoda Karimi
Student ID# : 138611223
    Email : hkarimi9@myseneca.ca
    Section : NKK
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    double smallPrice, mediumPrice, largePrice;
    int smallInCents;
    int numberOfShirts;
    int subTotalInCents;
    const double TAX = 0.13;
    const char patSize = 'S';
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", & smallPrice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", & mediumPrice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", & largePrice);
    smallInCents = (int)(smallPrice * 100 + 0.5 ); 
    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", smallPrice);
    printf("MEDIUM : $%.2lf\n", mediumPrice);
    printf("LARGE  : $%.2lf\n\n", largePrice);
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numberOfShirts);
    subTotalInCents = (smallInCents * numberOfShirts);
    int taxInCents = (int)(subTotalInCents * TAX + 0.5 );
    int totalCents = subTotalInCents + taxInCents;
    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", numberOfShirts);
    printf("Sub-total: $%8.4lf\n", (double)(subTotalInCents / 100.0));
    printf("Taxes    : $%8.4lf\n", (double)(taxInCents / 100.0));
    printf("Total    : $%8.4lf\n", (double)(totalCents / 100.0));
    return 0;
}
