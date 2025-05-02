
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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
#include "w8p2.h"
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
void displayCatFoodData(const int sku, const double* price,
    const double* weight, const int calories) {
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// Function to convert pounds (lbs) to kilograms (kg)
double convertLbsKg(const double* lbs, double* kg) {
    // Initialize the result to 0.0
    double result = *lbs / LBS_TO_KG;

    // Check if pointers are not NULL before dereferencing
    if ( kg != NULL) {

        *kg = result;
    }
    // Return the converted value (or 0.0 if pointers were NULL)
    return result;  
}



// Function to convert pounds (lbs) to grams (g)
int convertLbsG(const double* lbs, int* g) {
    // Initialize the result to 0.0
    double weightInPounds = *lbs;
    double weightInGrams = 
        convertLbsKg(&weightInPounds, &weightInGrams) * 1000;

    // Check if pointers are not NULL before dereferencing
    if ( g != NULL) {

        *g = (int)weightInGrams;
    }

    return (int)weightInGrams;
}


// Function to convert pounds (lbs) 
// to both kilograms (kg) and grams (g)
void convertLbs(const double* lbs, double* kg, int* g) {
    
    *kg = *lbs / LBS_TO_KG;
    *g = (int)(*lbs / LBS_TO_KG * 1000);
}


// Function to calculate total servings

double calculateServings(const int servingSize, 
    const int weightG, double* totalServings) {
    // Check if pointers are not NULL before dereferencing
    double result = ((double)(weightG) / (servingSize));
    if (totalServings != NULL) {
        *totalServings = result;
    }
    return result;
}

// Function to calculate cost per serving
double calculateCostPerServing(const double price, 
    const double* totalServings, double* costPerServing) {
    double result = (price / *totalServings);
    if (costPerServing != NULL) {
        *costPerServing = result;
    }
    return result;
}

// Function to calculate cost per calorie
double calculateCostPerCal(const double price, const double calories, 
    double* costPerCal, double* totalServings) {
    double result = (price / calories) / *totalServings;
    if (costPerCal != NULL) {
        *costPerCal = result;
    }
    return result;
}
// Function to calculate report data
struct ReportData calculateReportData(const struct CatFoodInfo* product) {
    struct ReportData report;

    // Assign the first 4 members directly
    report.sku = product->sku;
    report.price = product->price;
    report.calories = product->calories;
    report.weightLbs = product->weight;

    int servingSize = GRAMS_PER_SERVING;
    report.totalServings = calculateServings(servingSize, 
        convertLbsG(&(product->weight), NULL),&(report.totalServings));
    report.costPerServing = calculateCostPerServing(product->price, 
        &(report.totalServings), &(report.costPerServing));
    report.costPerCal = calculateCostPerCal(product->price, product->calories, 
        &(report.costPerCal), &(report.totalServings));
    report.weightKg = convertLbsKg(&(product->weight), &(report.weightKg));
    report.weightG = convertLbsG(&(product->weight), &(report.weightG));

    return report;  // Return the calculated ReportData
}


// Function to display the report header
void displayReportHeader() {
    // Use the macro for serving size
    printf("\n");
    printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_PER_SERVING);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     "
        "Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- "
        "--------- -------- -------- ------- -------\n");
}

// Function to display report data
void displayReportData(const struct ReportData* data, const int cheapestProduct) {
    if (cheapestProduct) {
        printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n",
            data->sku, data->price, data->weightLbs, data->weightKg, data->weightG,
            data->calories, data->totalServings, 
            data->costPerServing, data->costPerCal);
    }
    else {
        printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n",
            data->sku, data->price, data->weightLbs, data->weightKg, data->weightG,
            data->calories, data->totalServings,
            data->costPerServing, data->costPerCal);
    }
}


// Function to display the final analysis
void displayFinalAnalysis(const struct CatFoodInfo* cheapestProduct) {
    printf("\n");
    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, "
        "the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n\n", 
        cheapestProduct->sku, cheapestProduct->price);
    printf("Happy shopping!\n");
}


// Move the "start" function to the end of the file
void start() {
    struct CatFoodInfo products[MAX_PRODUCTS];

    int i, t;

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

    struct ReportData reports[MAX_PRODUCTS] = { {0} };
    for (i = 0; i < MAX_PRODUCTS; i++) {
        reports[i] = calculateReportData(&products[i]);
    }

    displayReportHeader();

    // Find the index of the cheapest product
    t = 0;
    for (i = 1; i < MAX_PRODUCTS; i++) {
        if (reports[i].costPerServing < reports[t].costPerServing) {
            t = i;
        }
    }

    // Display the analysis report
    for (i = 0; i < MAX_PRODUCTS; i++) {
        int isCheapest = (i == t);
        displayReportData(&reports[i], isCheapest);
    }

    // Display the final analysis
    displayFinalAnalysis(&products[t]);
}




