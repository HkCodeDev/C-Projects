/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012 
#define MAX_YEAR 2022
#define LOG_DAYS 3
#include <stdio.h>
int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int year;
    int month;
    int flag = 0;
    double morningTotal = 0.0;
    double eveningTotal = 0.0;
    double morningRating, eveningRating;
    int i;
    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
       

        if (year >= MIN_YEAR && year <= MAX_YEAR) 
        {
            if (month >= JAN && month <= DEC) 
            {
                printf("\n");
                printf("*** Log date set! ***\n");
            }
            
        }
        else 
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }

        if (month < JAN || month > DEC) 
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        if (year >= MIN_YEAR && year <= MAX_YEAR && month >= JAN && month <= DEC)
        {
            flag = 1;
        }
        else 
        {
            flag = 0;
        }

    } while (!flag);

    for (i = 1; i <= LOG_DAYS; i++) {
        if (year >= MIN_YEAR && year <= MAX_YEAR) {
            switch (month)
            {
            case 1:
                printf("\n");
                printf("%d-JAN-%02d\n", year, i);
                flag = 1;
                break;
            case 2:
                printf("\n");
                printf("%d-FEB-%02d\n", year, i);
                flag = 1;
                break;
            case 3:
                printf("\n");
                printf("%d-MAR-%02d\n", year, i);
                flag = 1;
                break;
            case 4:
                printf("\n");
                printf("%d-APR-%02d\n", year, i);
                flag = 1;
                break;
            case 5:
                printf("\n");
                printf("%d-MAY-%02d\n", year, i);
                flag = 1;
                break;
            case 6:
                printf("\n");
                printf("%d-JUN-%02d\n", year, i);
                flag = 1;
                break;
            case 7:
                printf("\n");
                printf("%d-JUL-%02d\n", year, i);
                flag = 1;
                break;
            case 8:
                printf("\n");
                printf("%d-AUG-%02d\n", year, i);
                flag = 1;
                break;
            case 9:
                printf("\n");
                printf("%d-SEP-%02d\n", year, i);
                flag = 1;
                break;
            case 10:
                printf("\n");
                printf("%d-OCT-%02d\n", year, i);
                flag = 1;
                break;
            case 11:
                printf("\n");
                printf("%d-NOV-%02d\n", year, i);
                flag = 1;
                break;
            case 12:
                printf("\n");
                printf("%d-DEC-%02d\n", year, i);
                flag = 1;
                break;

            }
        }
        do {

            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);
            if (morningRating < 0.0 || morningRating > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (morningRating < 0.0 || morningRating > 5.0);

        do {

            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);
            if (eveningRating < 0.0 || eveningRating > 5.0)
            {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (eveningRating < 0.0 || eveningRating > 5.0);
        morningTotal += morningRating;
        eveningTotal += eveningRating;
    }
    printf("\n");
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating:%7.3lf\n", morningTotal);
    printf("Evening total rating:%7.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating:%7.3lf\n\n", morningTotal + eveningTotal);
    printf("Average morning rating:  %.1f\n", morningTotal / LOG_DAYS);
    printf("Average evening rating:  %.1f\n", eveningTotal / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1f\n", (morningTotal + eveningTotal) / (2*(LOG_DAYS)));
    return 0;
}