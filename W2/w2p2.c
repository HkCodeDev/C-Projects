/*****************************************************************************
<assessment name example : Workshop - #2 (Part - 2)>
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
    int smallInCents, mediumInCents, largeInCents;
    int numberOfShirtsPatty = 0;
    int numberOfShirtsTommy = 0;
    int numberOfShirtsSally = 0;
    int subTotalInCentsPatty;
    int subTotalInCentsTommy;
    int subTotalInCentsSally;
    int pattyTaxCents;
    int tommyTaxCents;
    int sallyTaxCents;
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallPrice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mediumPrice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largePrice);
    smallInCents = (int)(smallPrice * 100 + 0.5);
    mediumInCents = (int)(mediumPrice * 100 + 0.5);
    largeInCents = (int)(largePrice * 100 + 0.5);
    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", smallPrice);
    printf("MEDIUM : $%.2lf\n", mediumPrice);
    printf("LARGE  : $%.2lf\n\n", largePrice);
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numberOfShirtsPatty);
    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &numberOfShirtsTommy);
    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &numberOfShirtsSally);
    subTotalInCentsPatty = (smallInCents * numberOfShirtsPatty);
    subTotalInCentsTommy = (largeInCents * numberOfShirtsTommy);
    subTotalInCentsSally = (mediumInCents * numberOfShirtsSally);
    pattyTaxCents = (int)(subTotalInCentsPatty * TAX + 0.5);
    tommyTaxCents = (int)(subTotalInCentsTommy * TAX + 0.5);
    sallyTaxCents = (int)(subTotalInCentsSally * TAX + 0.5);
    int totalPatty = pattyTaxCents + subTotalInCentsPatty;
    int totalTommy = tommyTaxCents + subTotalInCentsTommy;
    int totalSally = sallyTaxCents + subTotalInCentsSally;
    int total = totalPatty + totalTommy + totalSally;
    int subTotal = subTotalInCentsPatty + subTotalInCentsSally + subTotalInCentsTommy;
    int totalTax = pattyTaxCents + sallyTaxCents + tommyTaxCents;
    
    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallPrice, numberOfShirtsPatty, (double)(subTotalInCentsPatty/ 100.0), (double)(pattyTaxCents / 100.0), (double )totalPatty/100.0 );
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mediumPrice, numberOfShirtsSally, (double)(subTotalInCentsSally/ 100.0), (double)(sallyTaxCents / 100.0), (double )totalSally/100.0 );
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largePrice, numberOfShirtsTommy, (double)(subTotalInCentsTommy/ 100.0), (double)(tommyTaxCents / 100.0), (double )totalTommy/100.0 );
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("                        %9.4lf %9.4lf %9.4lf\n\n", (double)(subTotal / 100.0), (double)(totalTax / 100.0), (double)total / 100.0);
    
    int tooniesQty = subTotal / 200;
    int tooniesBalance = subTotal % 200;
    int looniesQty = tooniesBalance / 100;
    int looniesBalance = tooniesBalance % 100;
    int quartersQty = looniesBalance / 25;
    int quartersBalance = looniesBalance % 25;
    int dimesQty = quartersBalance / 10;
    int dimesBalance = quartersBalance % 10;
    int nickelsQty = dimesBalance / 5;
    int nickelsBalance = dimesBalance % 5;
    int penniesQty = nickelsBalance;
    int penniesBalance = nickelsBalance % 1;


    int tooniesQtyTax = total / 200 ;
    int tooniesBalanceTax = total % 200;
    int looniesQtyTax = tooniesBalanceTax  / 100;
    int looniesBalanceTax =tooniesBalanceTax  % 100;
    int quartersQtyTax = looniesBalanceTax  / 25 ;
    int quartersBalanceTax = looniesBalanceTax  % 25 ;
    int dimesQtyTax = quartersBalanceTax  / 10;
    int dimesBalanceTax = quartersBalanceTax  % 10 ;
    int nickelsQtyTax = dimesBalanceTax  / 5 ;
    int nickelsBalanceTax = dimesBalanceTax  % 5 ;
    int penniesQtyTax = nickelsBalanceTax;
    int penniesBalanceTax = nickelsBalanceTax % 1;  
    int totalShirt = numberOfShirtsPatty + numberOfShirtsSally + numberOfShirtsTommy ;

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n",(double)subTotal / 100.0);
    printf("Toonies  %3d %9.4lf\n", tooniesQty, (double)tooniesBalance / 100.0);
    printf("Loonies  %3d %9.4lf\n", looniesQty, (double)looniesBalance / 100.0);
    printf("Quarters %3d %9.4lf\n", quartersQty, (double)quartersBalance / 100.0);
    printf("Dimes    %3d %9.4lf\n", dimesQty, (double)dimesBalance/ 100.0);
    printf("Nickels  %3d %9.4lf\n", nickelsQty, (double)nickelsBalance / 100.0);
    printf("Pennies  %3d %9.4lf\n\n", penniesQty, (double) penniesBalance/100.0);
    printf("Average cost/shirt: $%.4lf\n\n", (double)subTotal / totalShirt / 100.0);
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n",(double)total / 100.0);
    printf("Toonies  %3d %9.4lf\n", tooniesQtyTax, (double)tooniesBalanceTax / 100.0);
    printf("Loonies  %3d %9.4lf\n", looniesQtyTax, (double)looniesBalanceTax / 100.0);
    printf("Quarters %3d %9.4lf\n", quartersQtyTax, (double)quartersBalanceTax / 100.0);
    printf("Dimes    %3d %9.4lf\n", dimesQtyTax, (double)dimesBalanceTax / 100.0);
    printf("Nickels  %3d %9.4lf\n", nickelsQtyTax, (double)nickelsBalanceTax / 100.0);
    printf("Pennies  %3d %9.4lf\n\n", penniesQtyTax, (double)penniesBalanceTax/100.0);
    printf("Average cost/shirt: $%.4lf\n", (double)total / totalShirt / 100.0);
    return 0;
}