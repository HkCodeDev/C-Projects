/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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
#include "w8p1.h"
// Function to get a positive integer from the user
int getIntPositive(int* value) {
    int input;
    int validInput = 0;
    while (!validInput) {
        scanf("%d", &input);
        if (input <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            if (value != NULL) {
                *value = input;
            }
            validInput = 1;
        }
    } 
    return input;
}
// Function to get a positive double from the user
double getDoublePositive(double* value) {
    double input;
    int validInput = 0;
    while (!validInput) {
        scanf("%lf", &input);
        if (input <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            if (value != NULL) {
                *value = input;
            }
            validInput = 1;
        }
    }
    return input;
}
// Display the opening message with information about the number of products
void openingMessage(const int productCount) {
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of "
        "product data for analysis.\n", productCount);
    printf("NOTE: A 'serving' is %dg\n\n", GRAMS_PER_SERVING);
}
// Function to get information about cat food products
struct CatFoodInfo getCatFoodInfo(int productNumber) {
    struct CatFoodInfo info;
    printf("Cat Food Product #%d\n", productNumber);
    printf("--------------------\n");
    printf("SKU           : ");
    getIntPositive(&info.sku);
    printf("PRICE         : $");
    getDoublePositive(&info.price);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&info.weight);
    printf("CALORIES/SERV.: ");
    getIntPositive(&info.calories);
    printf("\n");
    return info;

}

// Display the header for the cat food data table
void displayCatFoodHeader() {
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}
// Display data for a single cat food product
void displayCatFoodData(const int sku, const double *price,
    const double *weight, const int calories) {
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}
// The main function to start the program
void start() {
    struct CatFoodInfo products[MAX_PRODUCTS];
    int i;

    // Initialize the array to a safe empty state
    for (i = 0; i < MAX_PRODUCTS; i++) {
        products[i].sku = 0;
        products[i].price = 0.0;
        products[i].calories = 0;
        products[i].weight = 0.0;
    }

    openingMessage(MAX_PRODUCTS);

    // Get user input for each product and assign the values to the array
    for (i = 0; i < MAX_PRODUCTS; i++) {
        products[i] = getCatFoodInfo(i + 1);
    }

    displayCatFoodHeader();

    // Display each CatFoodInfo record
    for (i = 0; i < MAX_PRODUCTS; i++) {
        displayCatFoodData(products[i].sku, 
            &products[i].price, &products[i].weight, products[i].calories);
    }
}



    
