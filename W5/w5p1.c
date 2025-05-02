/*****************************************************************************
<assessment name example : Workshop - #5 (Part - 1)>
Full Name : Hoda Karimi
Student ID# : 138611223
    Email : hkarimi9@myseneca.ca
    Section : NKK
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2012 
#define MAX_YEAR 2022
#include <stdio.h>
int main()
{
    const int JAN = 1;
    const int DEC = 12;
    int year;
    int month;
    int flag = 0;
    
    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        switch (year)
        {
        case 2012:
        case 2013:
        case 2014:
        case 2015:
        case 2016:
        case 2017:
        case 2018:
        case 2019:
        case 2020:
        case 2021:
        case 2022:
            switch (month)
            {
            case 1:
                printf("\n");
                printf("*** Log date set! ***\n\n");
                printf("Log starting date: %d-JAN-01\n", year);
                flag = 1;
                break;
            case 2:
                printf("\n");
                printf("*** Log date set! ***\n\n");
                printf("Log starting date: %d-FEB-01\n", year);
                flag = 1;
                break;
            case 3:
                printf("\n");
                printf("*** Log date set! ***\n\n");
                printf("Log starting date: %d-MAR-01\n", year);
                flag = 1;
                break;
            case 4:
                printf("\n");
                printf("*** Log date set! ***\n\n");
                printf("Log starting date: %d-APR-01\n", year);
                flag = 1;
                break;
            case 5:
                printf("\n");
                printf("*** Log date set! ***\n\n");
                printf("Log starting date: %d-MAY-01\n", year);
                flag = 1;
                break;
            case 6:
                printf("\n");
                printf("*** Log date set! ***\n\n");
                printf("Log starting date: %d-JUN-01\n", year);
                flag = 1;
                break;

            case 7:
                printf("\n");
                printf("*** Log date set! ***\n\n");
                printf("Log starting date: %d-JUL-01\n", year);
                flag = 1;
                break;
            case 8:
                printf("\n");
                printf("*** Log date set! ***\n\n");
                printf("Log starting date: %d-AUG-01\n", year);
                flag = 1;
                break;
            case 9:
                printf("\n");
                printf("*** Log date set! ***\n\n");
                printf("Log starting date: %d-SEP-01\n", year);
                flag = 1;
                break;
            case 10:
                printf("\n");
                printf("*** Log date set! ***\n\n");
                printf("Log starting date: %d-OCT-01\n", year);
                flag = 1;
                break;
            case 11:
                printf("\n");
                printf("*** Log date set! ***\n\n");
                printf("Log starting date: %d-NOV-01\n", year);
                flag = 1;
                break;
            case 12:
                printf("\n");
                printf("*** Log date set! ***\n\n");
                printf("Log starting date: %d-DEC-01\n", year);
                flag = 1;
                break;
           
            }
            break;   

        }  
        if (year < MIN_YEAR || year > MAX_YEAR || month < JAN || month > DEC)
        {
            if (year < MIN_YEAR || year > MAX_YEAR)
            {
                printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            }
            if (month < JAN || month > DEC)
            {
                printf("   ERROR: Jan.(1) - Dec.(12)\n");
             
            }
            flag = 0; 
        }
        else
        {
            flag = 1; 
        }

         
        } while (!flag);
    
    return 0;
}
